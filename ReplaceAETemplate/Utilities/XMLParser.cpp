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
 

QMap<QString, int> XMLParser::parseTemplateText()
{
	QMap<QString, int> textMap;
	XMLNode* ItemNode = mFoldNode->FirstChildElement("Item");
	int index = 0;

	while (ItemNode != nullptr)
	{
		XMLNode* LayrElement = ItemNode->FirstChildElement("Layr");
		while (LayrElement != nullptr)
		{
			index++;
			// Replace text in template project
			XMLElement* stringElement = LayrElement->FirstChildElement("string");
			if (stringElement)
			{
				const char* stringValue = stringElement->GetText();
				if (stringValue != nullptr && strcmp(stringValue, ""))
				{
					textMap.insert(stringValue, index);
				}				
			} 
			LayrElement = LayrElement->NextSiblingElement("Layr");
		}
		ItemNode = ItemNode->NextSiblingElement("Item");
	}

	return textMap;
}

QMap<QString, int> XMLParser::parseTemplateImage()
{
	QMap<QString, int> imageList;
	XMLNode* ItemNode = mFoldNode->FirstChildElement("Item");
	int index = 0;

	while (ItemNode != nullptr)
	{
		XMLElement* pinNode = ItemNode->FirstChildElement("Pin");
		while (pinNode != nullptr)
		{ 
			index++;
			XMLElement* Als2Node = pinNode->FirstChildElement("Als2");
			if (Als2Node)
			{
				XMLElement* fileReferenceNode = Als2Node->FirstChildElement("fileReference");
				if (fileReferenceNode)
				{
					const char* fullpath = fileReferenceNode->Attribute("fullpath"); 
					imageList.insert(fullpath, index);
				}
			}
			pinNode = pinNode->NextSiblingElement("Pin");
		}
		ItemNode = ItemNode->NextSiblingElement("Item");
	}

	return imageList;
}

bool XMLParser::replaceTemplateText(const std::string& newText, const int index)
{
	int count = 0;
	XMLNode* ItemNode = mFoldNode->FirstChildElement("Item");
	XMLNode* LayrElement = nullptr;
	while (ItemNode != nullptr && count != index)
	{
		LayrElement = ItemNode->FirstChildElement("Layr");
		while (LayrElement != nullptr && count != index)
		{
			++count;
			LayrElement = LayrElement->NextSiblingElement("Layr");
		}
		
	}

	if (LayrElement != nullptr)
	{
		// Replace text in template project
		XMLElement* stringElement = LayrElement->FirstChildElement("string");
		if (stringElement)
		{
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
							bool result = replaceTextBdata(tdb4AttributeValue, modified_attr);
							if (!result)
							{
								XMLElement* exprNode = mXMLDocument->NewElement("expr");
								exprNode->SetAttribute("bdata", "746578742e736f75726365546578743d6e616d6500");
								tdbsNode->InsertEndChild(exprNode);
								tdb4Node->SetAttribute("bdata", modified_attr);
								return true;
							}
							delete[] modified_attr;
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
	int count = 0;
	XMLNode* ItemNode = mFoldNode->FirstChildElement("Item");
	XMLElement* pinNode = nullptr;
	while (ItemNode != nullptr && count != index)
	{
		pinNode = ItemNode->FirstChildElement("Pin");
		while (pinNode != nullptr && count != index)
		{
			++count;
			pinNode = pinNode->NextSiblingElement("Pin");
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
			if (!result)
			{
				sspcNode->SetAttribute("bdata", modified_attr);
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
			}
		}

		XMLElement* optiNode = pinNode->FirstChildElement("opti");
		if (optiNode)
		{
			const char* optiAttributeValue = optiNode->Attribute("bdata");
			int len = strlen(optiAttributeValue);
			char* modified_attr = new char[len + 1];
			bool result = replaceImageBdata(newImagePath.c_str(), optiAttributeValue, modified_attr, "opti");
			if (!result)
			{
				optiNode->SetAttribute("bdata", modified_attr);
				return true;
			}
			delete[] modified_attr;
		}
	}
	return false;
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

void XMLParser::saveAs(const std::string filePath)
{
	mXMLDocument->SaveFile(filePath.c_str());
}