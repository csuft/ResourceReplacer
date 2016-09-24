#include "XMLParser.h"


XMLParser::XMLParser(const std::string& file)
{
	mXMLDocument = new XMLDocument();
	mFilePath = file;
}

XMLParser::~XMLParser()
{
	delete mXMLDocument;
}

void XMLParser::loadTemplateFile()
{
	mXMLDocument->LoadFile(mFilePath.c_str());
	mRootElement = mXMLDocument->RootElement();
	if (mRootElement)
	{
		mFoldNode = mRootElement->FirstChildElement("Fold");
	}
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
	++index;
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
					XMLElement* Als2Node = sspcNode->NextSiblingElement("Als2");
					if (Als2Node == nullptr)
					{
						return;
					}
					XMLElement* fileReferenceNode = Als2Node->FirstChildElement("fileReference");
					if (fileReferenceNode == nullptr)
					{
						return;
					}
					const char* fullPath = fileReferenceNode->Attribute("fullpath");
					m_imageMap.insert(fullPath, index);
				}
			}
		}
		else if (itemType == COMPOSITE_ITEM)
		{
			XMLElement* LayrNode = idtaNode->NextSiblingElement("Layr");
			if (LayrNode == nullptr)
			{
				return;
			}
			XMLElement* stringNode = LayrNode->FirstChildElement("string");
			if (stringNode == nullptr)
			{
				return;
			}
			// 文本为空的层直接跳过不要
			const char* layerStr = stringNode->GetText();
			if (!strcmp(layerStr, "") || layerStr == nullptr)
			{
				return;
			}
			XMLElement* tdgpOuter = stringNode->NextSiblingElement("tdgp");
			if (tdgpOuter == nullptr)
			{
				return;
			}
			XMLElement* tdmnOuter = tdgpOuter->FirstChildElement("tdmn");
			if (tdmnOuter == nullptr)
			{
				return;
			}
			const char* tdmnOuterBdata = tdmnOuter->Attribute("bdata");
			// 'ADBE Text Properties'
			if (tdmnOuterBdata == nullptr || strcmp("4144424520546578742050726f706572746965730000000000000000000000000000000000000000", tdmnOuterBdata))
			{
				return;
			}
			XMLElement* tdgpInner = tdmnOuter->NextSiblingElement("tdgp");
			if (tdgpInner == nullptr)
			{
				return;
			}
			XMLElement* tdmnInner = tdgpInner->FirstChildElement("tdmn");
			if (tdmnInner == nullptr)
			{
				return;
			}
			const char* tdmnInnerBdata = tdmnInner->Attribute("bdata");
			// 'ADBE Text Document'
			if (tdmnInnerBdata == nullptr || strcmp("41444245205465787420446f63756d656e7400000000000000000000000000000000000000000000", tdmnOuterBdata))
			{
				return;
			}
			m_textMap.insert(layerStr, index);
		}
		else if (itemType == FOLDER_ITEM)
		{
			XMLElement* SfdrNode = idtaNode->NextSiblingElement("Sfdr");
			if (SfdrNode == nullptr)
			{
				return;
			}
			XMLElement* tempItem = SfdrNode->FirstChildElement("Item");
			if (tempItem == nullptr)
			{
				return;
			}
			parseTemplateItem(tempItem, index);
		}
		else
		{
			return;
		}
	}
	

}

bool XMLParser::replaceTemplateText(const std::string& newText, const int index)
{
	bool result;
	int count = 1;
	XMLNode* ItemNode = mFoldNode->FirstChildElement("Item");
	XMLNode* LayrElement = nullptr;
	while (ItemNode != nullptr)
	{
		LayrElement = ItemNode->FirstChildElement("Layr");
		while (LayrElement != nullptr && count != index)
		{
			++count;
			LayrElement = LayrElement->NextSiblingElement("Layr");
		}
		if (count == index)
		{
			break;
		}
		ItemNode = ItemNode->NextSiblingElement("Item");
	}

	if (LayrElement != nullptr)
	{
		// Replace text in template project
		XMLElement* stringElement = LayrElement->FirstChildElement("string");
		if (stringElement)
		{
			const char* str = stringElement->GetText();
			stringElement->SetText(newText.c_str());
		}
		XMLElement* tdgpNode = LayrElement->FirstChildElement("tdgp");
		if (tdgpNode)
		{
			XMLElement* tdgp1Node = tdgpNode->FirstChildElement("tdgp");
			if (tdgp1Node)
			{
				XMLElement* btdsNode = tdgp1Node->FirstChildElement("btds");
				if (btdsNode)
				{
					XMLElement* tdbsNode = btdsNode->FirstChildElement("tdbs");
					if (tdbsNode)
					{
						XMLElement* tdb4Node = tdbsNode->FirstChildElement("tdb4");
						if (tdb4Node)
						{
							const char* tdb4AttributeValue = tdb4Node->Attribute("bdata");
							int len = strlen(tdb4AttributeValue);
							char* modified_attr = new char[len + 1];
							result = replaceTextBdata(tdb4AttributeValue, modified_attr);
							if (!result)
							{
								XMLElement* exprNode = mXMLDocument->NewElement("expr");
								exprNode->SetAttribute("bdata", "746578742e736f75726365546578743d6e616d6500");
								tdbsNode->InsertEndChild(exprNode);
								tdb4Node->SetAttribute("bdata", modified_attr);
							}
							delete[] modified_attr;
							return true;
						}
					}
				}
			}
		} 
	} 
	return false;
}

bool XMLParser::replaceTemplateImage(const std::string& newImagePath, const int index)
{
	int count = 1;
	int flag = 0;
	XMLNode* ItemNode = mFoldNode->FirstChildElement("Item");
	XMLElement* pinNode = nullptr;
	while (ItemNode != nullptr)
	{
		pinNode = ItemNode->FirstChildElement("Pin");
		if (pinNode != nullptr && count != index)
		{
			++count;
		}
		if (count == index)
		{
			break;
		}

		ItemNode = ItemNode->NextSiblingElement("Item");
	}

	if (pinNode != nullptr)
	{
		XMLElement* sspcNode = pinNode->FirstChildElement("sspc");
		if (sspcNode)
		{
			const char* sspcAttributeValue = sspcNode->Attribute("bdata");  
			int len = strlen(sspcAttributeValue);
			char* modified_attr = new char[len + 1];
			bool result = replaceImageBdata(newImagePath.c_str(), sspcAttributeValue, modified_attr, "sspc");
			if (result)
			{
				sspcNode->SetAttribute("bdata", modified_attr);
				++flag;
			}
			delete[] modified_attr;
		}

		XMLElement* Als2Node = pinNode->FirstChildElement("Als2");
		if (Als2Node)
		{
			XMLElement* fileReferenceNode = Als2Node->FirstChildElement("fileReference");
			if (fileReferenceNode)
			{
				fileReferenceNode->SetAttribute("fullpath", newImagePath.c_str()); 
				++flag;
			}
		}

		XMLElement* optiNode = pinNode->FirstChildElement("opti");
		if (optiNode)
		{
			const char* optiAttributeValue = optiNode->Attribute("bdata");
			int len = strlen(optiAttributeValue);
			char* modified_attr = new char[len + 1];
			bool result = replaceImageBdata(newImagePath.c_str(), optiAttributeValue, modified_attr, "opti");
			if (result)
			{
				optiNode->SetAttribute("bdata", modified_attr);
				++flag;
			}
			delete[] modified_attr;
		}
	}
	
	return flag == 3 ? true:false;
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

XMLError XMLParser::saveAs(const std::string filePath)
{
	return mXMLDocument->SaveFile(filePath.c_str());
}