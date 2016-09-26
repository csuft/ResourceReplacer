#ifndef REPLACEAETEMPLATE_H
#define REPLACEAETEMPLATE_H

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include "ui_replaceaetemplate.h"
#include "../Utilities/XMLParser.h"

class ReplaceAETemplate : public QMainWindow
{
	Q_OBJECT

public:
	ReplaceAETemplate(QWidget *parent = 0);
	~ReplaceAETemplate();

private slots: 
	void onReplaceText();
	void onReplaceImage();
	void onOpenFile();
	void onQuitApp();
	void onCloseFile();
	void onSaveFile();
	void onDeveloper();
	void onTextItemClicked(QListWidgetItem* item);
	void onImageItemClicked(QListWidgetItem* item);
	void onNewTextChanged(const QString& newText);
	void onImageChoosed();

private:
	Ui::ReplaceAETemplateClass ui;

	XMLParser* m_parser;
	QLabel* m_dir;
	int m_selectedTextIndex;		// 旧文本在aepx中的索引值
	QString m_selectedText;			// 旧文本内容
	QString m_selectedFile;			// 当前选择的aepx文件
	QString m_selectedImage;		// 旧图片路径
};

#endif // REPLACEAETEMPLATE_H
