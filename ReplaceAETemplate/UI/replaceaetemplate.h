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
	int m_selectedText;
};

#endif // REPLACEAETEMPLATE_H
