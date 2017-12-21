#include "XMLParser.h"


XMLParser::XMLParser(QByteArray& byteArray)
{
	mXMLDocument = new XMLDocument();
	mFilePath = std::string(byteArray);
}

XMLParser::~XMLParser()
{
	delete mXMLDocument;
}

bool XMLParser::loadTemplateFile()
{
	XMLError error = mXMLDocument->LoadFile(mFilePath.c_str());
	if (error != XML_SUCCESS)
	{
		return false;
	}
	mRootElement = mXMLDocument->RootElement();
	if (mRootElement)
	{
		mFoldNode = mRootElement->FirstChildElement("Fold");
		return true;
	}
	return false;
}
 
void XMLParser::startParseTemplate()
{
	XMLNode* ItemNode = mFoldNode->FirstChildElement("Item");
	int index = 1;

	while (ItemNode != nullptr)
	{
		parseTemplateItem(ItemNode, index);
		ItemNode = ItemNode->NextSiblingElement("Item");
	}
}

// 判断Item的类型
// 总共分成三类：文件夹(Folder)、文件(File)、层(Layer)
XMLParser::ItemType XMLParser::whichType(const char* bdata)
{
	if (bdata == nullptr || !strcmp("", bdata))
	{
		return UNKNOWN_ITEM;
	}
	char fourcc[8] = { '\0' };
	memcpy(fourcc, bdata, 4);

	if (!strcmp("0004", fourcc))
	{
		return COMPOSITE_ITEM;
	}
	else if (!strcmp("0001", fourcc))
	{
		return FOLDER_ITEM;
	}
	else if (!strcmp("0007", fourcc))
	{
		return NORMAL_ITEM;
	}
	else
	{
		return UNKNOWN_ITEM;
	}
}

// 根据Item的idta子元素的值，递归解析XML
void XMLParser::parseTemplateItem(XMLNode* rootElement, int& index)
{
	if (rootElement == nullptr)
	{
		return;
	}

	XMLElement* str = rootElement->FirstChildElement("string");
	const char* txt = str->GetText();
	XMLElement* idtaNode = rootElement->FirstChildElement("idta");
	if (idtaNode != nullptr)
	{
		const char* idatBdata = idtaNode->Attribute("bdata");
		ItemType itemType = whichType(idatBdata);
		if (itemType == NORMAL_ITEM)
		{
			XMLElement* pinNode = idtaNode->NextSiblingElement("Pin");
			if (pinNode != nullptr)
			{
				XMLElement* sspcNode = pinNode->FirstChildElement("sspc");
				if (sspcNode == nullptr)
				{
					return;
				}
				const char* sspcBdata = sspcNode->Attribute("bdata");
				bool isNormalFormat = isImageFormat(sspcBdata);
				if (isNormalFormat)
				{
					XMLElement* AlNode = sspcNode->NextSiblingElement("Als2");
					if (AlNode == nullptr)
					{
						// 兼容CS6导出的XML
						AlNode = sspcNode->NextSiblingElement("Alas");
						if (AlNode == nullptr)
						{
							return;
						}
					}
					XMLElement* fileReferenceNode = AlNode->FirstChildElement("fileReference");
					if (fileReferenceNode == nullptr)
					{
						return;
					}
					const char* fullPath = fileReferenceNode->Attribute("fullpath");
					m_imageMap.insertMulti(fullPath, index);
					index++;
				}
			}
		}
		else if (itemType == COMPOSITE_ITEM)
		{
			XMLElement* LayrNode = idtaNode->NextSiblingElement("Layr");
			while (LayrNode != nullptr)
			{
				XMLElement* stringNode = LayrNode->FirstChildElement("string");
				if (stringNode)
				{
					// 文本为空的层直接跳过不要
					const char* layerStr = stringNode->GetText();
					if (layerStr != nullptr && strcmp(layerStr, ""))
					{
						XMLElement* tdgpOuter = stringNode->NextSiblingElement("tdgp");
						if (tdgpOuter)
						{
							XMLElement* tdmnOuter = tdgpOuter->FirstChildElement("tdmn");
							if (tdmnOuter)
							{
								const char* tdmnOuterBdata = tdmnOuter->Attribute("bdata");
								// 'ADBE Text Properties'
								if (tdmnOuterBdata != nullptr && !strcmp("4144424520546578742050726f706572746965730000000000000000000000000000000000000000", tdmnOuterBdata))
								{
									XMLElement* tdgpInner = tdmnOuter->NextSiblingElement("tdgp");
									if (tdgpInner != nullptr)
									{
										XMLElement* tdmnInner = tdgpInner->FirstChildElement("tdmn");
										if (tdmnInner != nullptr)
										{
											const char* tdmnInnerBdata = tdmnInner->Attribute("bdata");
											// 'ADBE Text Document'
											if (tdmnInnerBdata != nullptr || !strcmp("41444245205465787420446f63756d656e7400000000000000000000000000000000000000000000", tdmnInnerBdata))
											{
												m_textMap.insertMulti(layerStr, index);
												index++;
											}
										}
									}
								}
							}
						}
					}
				}
				LayrNode = LayrNode->NextSiblingElement("Layr");
			}
		}
		else if (itemType == FOLDER_ITEM)
		{
			XMLElement* SfdrNode = idtaNode->NextSiblingElement("Sfdr");
			if (SfdrNode == nullptr)
			{
				return;
			}
			XMLElement* tempItem = SfdrNode->FirstChildElement("Item");
			while (tempItem != nullptr)
			{
				parseTemplateItem(tempItem, index);
				tempItem = tempItem->NextSiblingElement("Item");
			}
		}
		else
		{
			return;
		}
	}
}

bool XMLParser::replaceTemplateText(const std::string& newText, int index)
{
	if (index < 0)
	{
		return false;
	}
	XMLNode* ItemNode = mFoldNode->FirstChildElement("Item");
	int counter = 1;

	while (ItemNode != nullptr)
	{
		if (doReplace(ItemNode, newText, counter, index, REPLACE_TEXT))
		{
			break;
		}
		ItemNode = ItemNode->NextSiblingElement("Item");
	}
	return true;
}

bool XMLParser::replaceTemplateImage(const std::string& newImagePath, const int index)
{
	if (index < 0)
	{
		return false;
	}
	XMLNode* ItemNode = mFoldNode->FirstChildElement("Item");
	int counter = 1;

	while (ItemNode != nullptr)
	{
		if (doReplace(ItemNode, newImagePath, counter, index, REPLACE_IMAGE))
		{
			break;
		}
		ItemNode = ItemNode->NextSiblingElement("Item");
	}
	return true;
}

bool XMLParser::replaceTextBdata(const char* original_bdata, char* modified_bdata)
{
	if (original_bdata == nullptr || modified_bdata == nullptr)
	{
		return false;
	}
	int len = strlen(original_bdata);
	modified_bdata[len] = '\0';

	for (int i = len - 1; i >= 0; --i)
	{
		if (i == len - 7)
		{
			if (original_bdata[i] == '1')
			{
				return true;
			}
			else
			{
				modified_bdata[i] = '1';
			}
		}
		else
		{
			modified_bdata[i] = original_bdata[i];
		}
	}
	
	return false;
}

// 判断是否是常见图片格式
bool XMLParser::isImageFormat(const char* bdata)
{
	if (bdata == nullptr || !strcmp(bdata, ""))
	{
		return false;
	}
	char fourcc[16] = { '\0' };
	memcpy(fourcc, bdata + 44, 8);

	// JPEG(JPG), PNG, BMP, TIF(TIFF)
	if (!strcmp(fourcc, "706e6721") || !strcmp(fourcc, "4a504547") || !strcmp(fourcc, "5449465f") || !strcmp(fourcc, "424d5020"))
	{
		return true;
	}
	return false;
}

bool XMLParser::replaceImageBdata(const char* imagePath, const char* original_bdata, char* modified_bdata, const char* type)
{
	if (original_bdata == nullptr || modified_bdata == nullptr || imagePath == nullptr || type == nullptr)
	{
		return false;
	}
	int len = strlen(original_bdata);
	modified_bdata[len] = '\0';
	memcpy(modified_bdata, original_bdata, len);

	char fourcc[16] = { '\0' };
	char imageExt[8] = { '\0' };
	const char* dotPos = strrchr(imagePath, '.');
	memcpy(imageExt, dotPos+1, strlen(dotPos+1));

	if (!strcmp(imageExt, "png"))
	{
		memcpy(fourcc, "706e6721", 9);  // 'png!'
	}
	if (!strcmp(imageExt, "jpg") || !strcmp(imageExt, "jpeg"))
	{
		memcpy(fourcc, "4a504547", 9);  // 'JPEG'
	}
	if (!strcmp(imageExt, "tif") || !strcmp(imageExt, "tiff"))
	{
		memcpy(fourcc, "5449465f", 9);  // 'TIF_'
	}
	if (!strcmp(imageExt, "bmp"))
	{
		memcpy(fourcc, "424d5020", 9);// 'BMP '
	}

	if (!strcmp(type, "sspc"))
	{
		memcpy(modified_bdata + 44, fourcc, strlen(fourcc));
	}
	else
	{
		memcpy(modified_bdata, fourcc, strlen(fourcc));
	}

	return true;
}

XMLError XMLParser::saveAs(QByteArray& filePath)
{
	return mXMLDocument->SaveFile(std::string(filePath).c_str());
}

bool XMLParser::doReplace(XMLNode* rootElement, const std::string& contents, int& counter, int index, int type)
{
	if (rootElement == nullptr)
	{
		return false;
	}

	XMLElement* str = rootElement->FirstChildElement("string");
	const char* txt = str->GetText();
	XMLElement* idtaNode = rootElement->FirstChildElement("idta");
	if (idtaNode != nullptr)
	{
		const char* idatBdata = idtaNode->Attribute("bdata");
		ItemType itemType = whichType(idatBdata);
		if (itemType == NORMAL_ITEM)
		{
			XMLElement* pinNode = idtaNode->NextSiblingElement("Pin");
			if (pinNode != nullptr)
			{
				XMLElement* sspcNode = pinNode->FirstChildElement("sspc");
				if (sspcNode != nullptr)
				{
					const char* sspcBdata = sspcNode->Attribute("bdata");
					bool isNormalFormat = isImageFormat(sspcBdata);
					if (isNormalFormat)
					{
						XMLElement* AlNode = sspcNode->NextSiblingElement("Als2");
						if (AlNode == nullptr)
						{
							AlNode = sspcNode->NextSiblingElement("Alas");
						}
						if (AlNode != nullptr)
						{
							XMLElement* fileReferenceNode = AlNode->FirstChildElement("fileReference");
							if (fileReferenceNode != nullptr)
							{
								if (counter == index && type == REPLACE_IMAGE)
								{
									int bDataLength;
									char* buffer;
									bool result;
									// PART 1
									bDataLength = strlen(sspcBdata);
									buffer = new char[bDataLength + 1];
									result = replaceImageBdata(contents.c_str(), sspcBdata, buffer, "sspc");
									if (result)
									{
										sspcNode->SetAttribute("bdata", buffer);
									}
									delete[] buffer;

									// PART 2
									fileReferenceNode->SetAttribute("fullpath", contents.c_str());

									// PART 3
									XMLElement* optiNode = pinNode->FirstChildElement("opti");
									if (optiNode)
									{
										const char* optiBdata = optiNode->Attribute("bdata");
										bDataLength = strlen(optiBdata);
										buffer = new char[bDataLength + 1];
										result = replaceImageBdata(contents.c_str(), optiBdata, buffer, "opti");
										if (result)
										{
											optiNode->SetAttribute("bdata", buffer);
										}
										delete[] buffer;
										++counter;
										return true;
									} 
								}
								++counter;
							}
						}
					}
				} 
			}
		}
		else if (itemType == COMPOSITE_ITEM)
		{
			XMLElement* LayrNode = idtaNode->NextSiblingElement("Layr");
			while (LayrNode != nullptr)
			{
				XMLElement* stringNode = LayrNode->FirstChildElement("string");
				if (stringNode)
				{
					// 文本为空的层直接跳过不要
					const char* layerStr = stringNode->GetText();
					if (layerStr != nullptr && strcmp(layerStr, ""))
					{
						XMLElement* tdgpOuter = stringNode->NextSiblingElement("tdgp");
						if (tdgpOuter)
						{
							XMLElement* tdmnOuter = tdgpOuter->FirstChildElement("tdmn");
							if (tdmnOuter)
							{
								const char* tdmnOuterBdata = tdmnOuter->Attribute("bdata");
								// 'ADBE Text Properties'
								if (tdmnOuterBdata != nullptr && !strcmp("4144424520546578742050726f706572746965730000000000000000000000000000000000000000", tdmnOuterBdata))
								{
									XMLElement* tdgpInner = tdmnOuter->NextSiblingElement("tdgp");
									if (tdgpInner != nullptr)
									{
										XMLElement* tdmnInner = tdgpInner->FirstChildElement("tdmn");
										if (tdmnInner != nullptr)
										{
											const char* tdmnInnerBdata = tdmnInner->Attribute("bdata");
											// 'ADBE Text Document'
											if (tdmnInnerBdata != nullptr || !strcmp("41444245205465787420446f63756d656e7400000000000000000000000000000000000000000000", tdmnInnerBdata))
											{ 
												if (counter == index && type == REPLACE_TEXT)
												{
													// PART 1
													stringNode->SetText(contents.c_str());

													// PART 2
													XMLElement* btdsNode = tdmnInner->NextSiblingElement("btds");
													if (btdsNode)
													{
														XMLElement* tdbsNode = btdsNode->FirstChildElement("tdbs");
														if (tdbsNode)
														{
															XMLElement* tdb4Node = tdbsNode->FirstChildElement("tdb4");
															if (tdb4Node)
															{
																const char* tdb4Bdata = tdb4Node->Attribute("bdata");
																int len = strlen(tdb4Bdata);
																char* buffer = new char[len + 1];
																bool result = replaceTextBdata(tdb4Bdata, buffer);
																if (!result)
																{
																	XMLElement* exprNode = mXMLDocument->NewElement("expr");
																	// text.sourceText=name
																	exprNode->SetAttribute("bdata", "746578742e736f75726365546578743d6e616d6500");
																	tdbsNode->InsertEndChild(exprNode);
																	tdb4Node->SetAttribute("bdata", buffer);
																}
																delete[] buffer;
																return true;
															}
														}
													} 
												}
												counter++;
											}
										}
									}
								}
							}
						}
					}
				}
				LayrNode = LayrNode->NextSiblingElement("Layr");
			}
		}
		else if (itemType == FOLDER_ITEM)
		{
			XMLElement* SfdrNode = idtaNode->NextSiblingElement("Sfdr");
			if (SfdrNode == nullptr)
			{
				return false;
			}
			XMLElement* tempItem = SfdrNode->FirstChildElement("Item");
			while (tempItem != nullptr)
			{
				if (doReplace(tempItem, contents, counter, index, type))
				{
					break;
				} 
				tempItem = tempItem->NextSiblingElement("Item");
			}
		}
		else
		{
			return false;
		}
	} 
	return false;
}