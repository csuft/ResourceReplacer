#include "replaceaetemplate.h"

ReplaceAETemplate::ReplaceAETemplate(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("模板内容替换工具v1.0"));
	setWindowIcon(QIcon(":/images/logo"));
	setFixedHeight(400);
	setFixedWidth(600);

	connect(ui.searchCharButton, SIGNAL(clicked()), this, SLOT(onSearchText()));
	connect(ui.replaceCharButton, SIGNAL(clicked()), this, SLOT(onReplaceText()));



	connect(ui.actionOpenFile, SIGNAL(clicked()), this, SLOT(onOpenFile()));
}

ReplaceAETemplate::~ReplaceAETemplate()
{

}

void ReplaceAETemplate::onSearchText()
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
	close();
}

void ReplaceAETemplate::onCloseFile()
{

}