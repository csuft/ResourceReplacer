#pragma once
#include "tinyxml2.h"
#include <vector>
#include <string>
#include <QString>
#include <QMap>

using namespace tinyxml2; 

class XMLParser
{
public: 
	XMLParser() = default;
	XMLParser(const std::string& file);
	~XMLParser();

	enum ItemType {
		COMPOSITE_ITEM,
		FOLDER_ITEM,
		NORMAL_ITEM,
		UNKNOWN_ITEM
	};
	 
	void startParseTemplate();
	const QMap<QString, int> getTextMap() const { return m_textMap; }
	const QMap<QString, int> getImageMap() const { return m_imageMap; }
	bool replaceTemplateText(const std::string& newText, const int index);
	bool replaceTemplateImage(const std::string& newImagePath, const int index);
	XMLError saveAs(const std::string filePath);
	void loadTemplateFile();

private:
	bool replaceTextBdata(const char* original_bdata, char* modified_bdata);
	bool replaceImageBdata(const char* imagePath, const char* original_bdata, char* modified_btata, const char* type);
	void parseTemplateItem(XMLNode* rootElement, int& index);
	bool isImageFormat(const char* bdata);
	ItemType whichType(const char* bdata);

private:
	std::string mFilePath;
	XMLDocument* mXMLDocument;
	XMLElement* mRootElement;
	XMLElement* mFoldNode;
	QMap<QString, int> m_textMap;
	QMap<QString, int> m_imageMap;
};

