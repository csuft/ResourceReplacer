#include "replaceaetemplate.h"

ReplaceAETemplate::ReplaceAETemplate(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("模板内容替换工具v1.0"));
	setWindowIcon(QIcon(":/images/logo"));
	setFixedHeight(400);
	setFixedWidth(600);
	 
	connect(ui.replaceTextButton, SIGNAL(clicked()), this, SLOT(onReplaceText()));
	connect(ui.actionQuitApplication, SIGNAL(triggered()), this, SLOT(onQuitApp()));
	connect(ui.actionOpenFile, SIGNAL(triggered()), this, SLOT(onOpenFile()));
	connect(ui.actionSaveFile, SIGNAL(triggered()), this, SLOT(onSaveFile()));
}

ReplaceAETemplate::~ReplaceAETemplate()
{

} 


void ReplaceAETemplate::onReplaceText()
{

}

void ReplaceAETemplate::onOpenFile()
{

}

void ReplaceAETemplate::onQuitApp()
{
	QApplication::quit();
}

void ReplaceAETemplate::onCloseFile()
{

}

void ReplaceAETemplate::onSaveFile()
{

}