/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *label;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *passwordLineEdit;
    QPushButton *loginButton;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(313, 163);
        LoginWindow->setContextMenuPolicy(Qt::NoContextMenu);
        label = new QLabel(LoginWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 10, 72, 72));
        label->setContextMenuPolicy(Qt::NoContextMenu);
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/logo")));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 100, 151, 16));
        label_3->setStyleSheet(QString::fromUtf8("font-weight:bold; \n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        layoutWidget = new QWidget(LoginWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 130, 291, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(passwordLineEdit);

        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        horizontalLayout->addWidget(loginButton);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "\347\224\250\346\210\267\347\231\273\345\275\225", 0));
        label->setText(QString());
        label_3->setText(QApplication::translate("LoginWindow", "AE\346\250\241\346\235\277\345\206\205\345\256\271\346\233\277\346\215\242\345\267\245\345\205\267v1.0", 0));
        label_2->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225\345\217\243\344\273\244\357\274\232", 0));
        loginButton->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
