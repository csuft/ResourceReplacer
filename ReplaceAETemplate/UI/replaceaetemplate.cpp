#include "replaceaetemplate.h"

#include <QIcon>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>

ReplaceAETemplate::ReplaceAETemplate(QWidget *parent)
: QMainWindow(parent), m_parser(nullptr)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("模板内容替换工具v1.0"));
	setWindowIcon(QIcon(":/images/logo"));
	setFixedHeight(400);
	setFixedWidth(600);

	ui.replaceTextButton->setDisabled(true);
	ui.replaceImageButton->setDisabled(true);
	ui.actionCloseFile->setDisabled(true);
	ui.actionSaveFile->setDisabled(true);
	m_dir = new QLabel(this); 
	ui.statusBar->addWidget(m_dir);
	 
	connect(ui.replaceImageButton, SIGNAL(clicked()), this, SLOT(onReplaceImage()));
	connect(ui.replaceTextButton, SIGNAL(clicked()), this, SLOT(onReplaceText()));
	connect(ui.actionQuitApplication, SIGNAL(triggered()), this, SLOT(onQuitApp()));
	connect(ui.actionOpenFile, SIGNAL(triggered()), this, SLOT(onOpenFile()));
	connect(ui.actionSaveFile, SIGNAL(triggered()), this, SLOT(onSaveFile()));
	connect(ui.actionDeveloper, SIGNAL(triggered()), this, SLOT(onDeveloper()));
	connect(ui.textListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onTextItemClicked(QListWidgetItem*)));
	connect(ui.imageListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onImageItemClicked(QListWidgetItem*)));
	connect(ui.newTextLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(onNewTextChanged(const QString&)));
	connect(ui.chooseImageButton, SIGNAL(clicked()), this, SLOT(onImageChoosed()));
}

ReplaceAETemplate::~ReplaceAETemplate()
{
	if (m_parser != nullptr)
	{
		delete m_parser;
	}
} 

void ReplaceAETemplate::onOpenFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("选择AE模板工程"), QStringLiteral("C:"), tr("AE Template Files (*.aepx)"));
	if (!fileName.isEmpty())
	{ 
		m_dir->setText(QStringLiteral("当前打开文件：") + fileName);
		m_parser = new XMLParser(fileName.toStdString());
		m_parser->loadTemplateFile();
		QMap<QString, int> textList = m_parser->parseTemplateText();
		QMapIterator<QString, int> textIterator(textList);
		QMap<QString, int> imageList = m_parser->parseTemplateImage();
		QMapIterator<QString, int> imageIterator(imageList);
		int index = 1;
		while (textIterator.hasNext())
		{
			textIterator.next();
			QListWidgetItem* item = new QListWidgetItem(textIterator.key(), ui.textListWidget); 
			item->setData(Qt::ToolTipRole, textIterator.value());
			ui.textListWidget->insertItem(index++, item);
		}
		index = 1;
		while (imageIterator.hasNext())
		{
			imageIterator.next();
			QListWidgetItem* item = new QListWidgetItem(imageIterator.key(), ui.imageListWidget);
			item->setData(Qt::ToolTipRole, imageIterator.value()); 
			ui.imageListWidget->insertItem(index++, item);
		}

		ui.actionCloseFile->setEnabled(true);
		ui.actionSaveFile->setEnabled(true);
	}
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

void ReplaceAETemplate::onDeveloper()
{
	QMessageBox::information(this, QStringLiteral("关于开发者"), QStringLiteral("https://github.com/csuft"), QMessageBox::Ok);
}

void ReplaceAETemplate::onReplaceImage()
{

}

void ReplaceAETemplate::onReplaceText()
{

}

void ReplaceAETemplate::onTextItemClicked(QListWidgetItem* item)
{
	QString oldText = item->text();
	m_selectedText = item->data(Qt::ToolTipRole).toInt();

	ui.originalTextLabel->setText(oldText);
}

void ReplaceAETemplate::onImageItemClicked(QListWidgetItem* item)
{
	QString oldImagePath = item->text();
	ui.imageCountLabel->setText(item->data(Qt::ToolTipRole).toString());
	QFile imageFile(oldImagePath);
	if (imageFile.exists())
	{
		QPixmap oldImage(oldImagePath);
		oldImage = oldImage.scaled(QSize(321, 221), Qt::KeepAspectRatio);
		ui.imagePreviewLabel->setPixmap(oldImage);
	}
	else
	{
		ui.imagePreviewLabel->setPixmap(QPixmap(":/images/placeholder"));
	}
}

void ReplaceAETemplate::onNewTextChanged(const QString& newText)
{
	ui.replaceTextButton->setEnabled(true);
}

void ReplaceAETemplate::onImageChoosed()
{
	QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("选择图片资源"), QStringLiteral("C:"), tr("Image Files (*.tif *.tiff *.png *.jpg *.jpeg *.bmp)"));
	if (!fileName.isEmpty())
	{
		ui.replaceImageButton->setEnabled(true);
		ui.destImagePathLineEdit->setText(fileName);
	}
}