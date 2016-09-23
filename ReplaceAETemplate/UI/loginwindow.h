#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "ui_loginwindow.h"

class LoginWindow : public QDialog
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = 0);
	~LoginWindow();

private slots:
	void onLoginClicked();
	void onPasswordChanged(const QString & text);

protected:
	void closeEvent(QCloseEvent *event);

private:
	Ui::LoginWindow ui;
};

#endif // LOGINWINDOW_H
