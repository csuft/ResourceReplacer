#include "replaceaetemplate.h"

#include <QIcon>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>

ReplaceAETemplate::ReplaceAETemplate(QWidget *parent)
: QMainWindow(parent), m_parser(nullptr), m_selectedText(-1)
{
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("AE模板内容替换工具v1.0"));
	setWindowIcon(QIcon(":/images/logo"));
	setFixedHeight(400);
	setFixedWidth(600);

	ui.imagePreviewLabel->setPixmap(QPixmap(":/images/placeholder"));
	ui.replaceTextButton->setDisabled(true);
	ui.replaceImageButton->setDisabled(true);
	ui.actionCloseFile->setDisabled(true);
	ui.actionSaveFile->setDisabled(true);
	ui.newTextLineEdit->setDisabled(true);
	m_dir = new QLabel(this); 
	ui.statusBar->addWidget(m_dir);
	 
	connect(ui.replaceImageButton, SIGNAL(clicked()), this, SLOT(onReplaceImage()));
	connect(ui.replaceTextButton, SIGNAL(clicked()), this, SLOT(onReplaceText()));
	connect(ui.actionQuitApplication, SIGNAL(triggered()), this, SLOT(onQuitApp()));
	connect(ui.actionCloseFile, SIGNAL(triggered()), this, SLOT(onCloseFile()));
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
		m_parser = nullptr;
	}

} 

void ReplaceAETemplate::onOpenFile()
{
	m_selectedFile = QFileDialog::getOpenFileName(this, QStringLiteral("选择AE模板工程"), QStringLiteral("C:"), tr("AE Template Files (*.aepx)"));
	if (!m_selectedFile.isEmpty())
	{ 
		m_dir->setText(QStringLiteral("当前打开文件：") + m_selectedFile);
		m_parser = new XMLParser(m_selectedFile.toLocal8Bit());
		bool ret = m_parser->loadTemplateFile();
		if (!ret)
		{
			QMessageBox::critical(this, QStringLiteral("错误提示"), QStringLiteral("打开文件失败"), QMessageBox::Ok);
			return;
		}
		
		m_parser->startParseTemplate();
		QMap<QString, int> textMap = m_parser->getTextMap();
		QMapIterator<QString, int> textIterator(textMap);
		QMap<QString, int> imageMap = m_parser->getImageMap();
		QMapIterator<QString, int> imageIterator(imageMap);
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
	m_dir->setText("");
	m_selectedFile.clear();

	if (m_parser != nullptr)
	{
		delete m_parser;
		m_parser = nullptr;
	}
	ui.textListWidget->clear();
	ui.imageListWidget->clear();
	ui.newTextLineEdit->clear();
	ui.destImagePathLineEdit->clear();
	ui.replaceImageButton->setDisabled(true);
	ui.imagePreviewLabel->setPixmap(QPixmap(":/images/placeholder"));
	ui.imageCountLabel->setText("");
	ui.newTextLineEdit->setDisabled(true);
	ui.actionCloseFile->setDisabled(true);
	ui.actionSaveFile->setDisabled(true);
	
	m_selectedImage.clear();
	m_selectedText.clear();
	m_selectedTextIndex = -1;
}

void ReplaceAETemplate::onSaveFile()
{
	if (m_parser != nullptr)
	{
		QFileInfo fileInfo(m_selectedFile);
		QString generatedFile = fileInfo.path() + "generated.aepx";
		m_parser->saveAs(generatedFile.toStdString());
		QMessageBox::information(this, QStringLiteral("文件已保存"), generatedFile, QMessageBox::Ok);
	}
}

void ReplaceAETemplate::onDeveloper()
{
	QMessageBox::information(this, QStringLiteral("关于开发者"), QStringLiteral("https://github.com/csuft"), QMessageBox::Ok);
}

void ReplaceAETemplate::onReplaceImage()
{
	QString newFilePath = QDir::toNativeSeparators(ui.destImagePathLineEdit->text()); 
	int index = ui.imageCountLabel->text().toInt();
	bool result = m_parser->replaceTemplateImage(newFilePath.toStdString(), index);
	if (result)
	{
		QMessageBox::information(this, QStringLiteral("执行结果"), QStringLiteral("已成功替换图片"), QMessageBox::Ok);
		QPixmap newImage(newFilePath);
		newImage = newImage.scaled(QSize(321, 221), Qt::KeepAspectRatio);
		ui.imagePreviewLabel->setPixmap(newImage);
		QList<QListWidgetItem*> listItems = ui.imageListWidget->findItems(m_selectedImage, Qt::MatchExactly);
		listItems[0]->setText(newFilePath);
	}
	else
	{
		QMessageBox::critical(this, QStringLiteral("执行结果"), QStringLiteral("执行失败，发生未知错误"), QMessageBox::Ok);
	}
}

void ReplaceAETemplate::onReplaceText()
{
	QString newText = ui.newTextLineEdit->text();
	bool result = m_parser->replaceTemplateText(newText.toStdString(), m_selectedTextIndex);
	if (result)
	{
		QMessageBox::information(this, QStringLiteral("执行结果"), QStringLiteral("已成功替换文本"), QMessageBox::Ok);
		QList<QListWidgetItem*> listItems = ui.textListWidget->findItems(m_selectedText, Qt::MatchExactly);
		listItems[0]->setText(newText);
	}
	else
	{
		QMessageBox::critical(this, QStringLiteral("执行结果"), QStringLiteral("执行失败，发生未知错误"), QMessageBox::Ok);
	}
}

void ReplaceAETemplate::onTextItemClicked(QListWidgetItem* item)
{
	ui.newTextLineEdit->clear();
	m_selectedText = item->text();
	m_selectedTextIndex = item->data(Qt::ToolTipRole).toInt();

	ui.originalTextLabel->setText(m_selectedText);
	ui.newTextLineEdit->setEnabled(true);
}

void ReplaceAETemplate::onImageItemClicked(QListWidgetItem* item)
{
	m_selectedImage = item->text();
	ui.imageCountLabel->setText(item->data(Qt::ToolTipRole).toString());
	ui.destImagePathLineEdit->clear();
	QFile imageFile(m_selectedImage);
	if (imageFile.exists())
	{
		QPixmap oldImage(m_selectedImage);
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
	if (!newText.isEmpty() && !m_selectedText.isEmpty())
	{
		ui.replaceTextButton->setEnabled(true);
	}
	else
	{
		ui.replaceTextButton->setDisabled(true);
	}
}

void ReplaceAETemplate::onImageChoosed()
{
	QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("选择图片资源"), QStringLiteral("C:"), tr("Image Files (*.tif *.tiff *.png *.jpg *.jpeg *.bmp)"));
	if (!fileName.isEmpty())
	{
		if (m_selectedImage.isEmpty())
		{
			ui.replaceImageButton->setDisabled(true);
		}
		else
		{
			ui.replaceImageButton->setEnabled(true);
		}
		
		ui.destImagePathLineEdit->setText(fileName);
	}
}