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

	QMap<QString, int> parseTemplateText();
	QMap<QString, int> parseTemplateImage();
	bool replaceTemplateText(const std::string& newText, const int index);
	bool replaceTemplateImage(const std::string& newImagePath, const int index);
	void saveAs(const std::string filePath);

private:
	void loadTemplateFile();
	bool replaceTextBdata(const char* original_bdata, char* modified_bdata);
	bool replaceImageBdata(const char* imagePath, const char* original_bdata, char* modified_btata, const char* type);

private:
	std::string mFilePath;
	XMLDocument* mXMLDocument;
	XMLElement* mRootElement;
	XMLElement* mFoldNode;
};

