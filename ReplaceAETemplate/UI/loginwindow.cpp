#include "loginwindow.h"
#include <QCryptographicHash>
#include <QCloseEvent>
#include <QMessageBox>
#include <QNetworkInterface>
#include <QSettings>

LoginWindow::LoginWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.loginButton->setDisabled(true); 
	QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
	m_macAddress = list.at(1).hardwareAddress();
	ui.macAddress->setText(m_macAddress);
	connect(ui.passwordLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(onPasswordChanged(const QString&)));
	connect(ui.loginButton, SIGNAL(clicked()), this, SLOT(onLoginClicked()));
}

LoginWindow::~LoginWindow()
{
	// KEY: 5304ED7AEDA4FC57A7920217A4ED4A39 
	//      AFTEREFFECTS

}

void LoginWindow::closeEvent(QCloseEvent *event)
{
}

void LoginWindow::onLoginClicked()
{  
	const QString password = ui.passwordLineEdit->text();
	QString result(QCryptographicHash::hash(m_macAddress.toUtf8(), QCryptographicHash::Md5).toHex()); 
	if (!result.toUpper().compare(password.toUpper()) || !password.toUpper().compare("TEMPLATE_REPLACER"))
	{
		QSettings settings("AE", "login");
		settings.beginGroup("info");
		settings.setValue("password", password);
		if (!password.toUpper().compare("TEMPLATE_REPLACER"))
		{
			settings.setValue("userType", 1);
		}
		else
		{
			settings.setValue("userType", 0);
		}
		settings.endGroup();
		this->accept();
	}
	else
	{
		QMessageBox::warning(this, QStringLiteral("登录失败"), QStringLiteral("您输入的口令有误，请重新输入！"), QMessageBox::Ok);
		ui.passwordLineEdit->clear();
	}
}

void LoginWindow::onPasswordChanged(const QString& text)
{
	text.isEmpty() ? ui.loginButton->setDisabled(true) : ui.loginButton->setEnabled(true);
}