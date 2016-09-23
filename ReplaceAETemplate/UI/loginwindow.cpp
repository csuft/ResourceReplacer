#include "loginwindow.h"
#include <QCryptographicHash>
#include <QCloseEvent>
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.loginButton->setDisabled(true);
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
	const QString key = "5304ED7AEDA4FC57A7920217A4ED4A39";
	const QString password = ui.passwordLineEdit->text();  
	QString result(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex()); 
	if (!result.toUpper().compare(key))
	{
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