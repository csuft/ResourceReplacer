/********************************************************************************
** Form generated from reading UI file 'replaceaetemplate.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLACEAETEMPLATE_H
#define UI_REPLACEAETEMPLATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplaceAETemplateClass
{
public:
    QAction *actionOpenFile;
    QAction *actionCloseFile;
    QAction *actionQuitApplication;
    QAction *actionDeveloper;
    QAction *actionSaveFile;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *replaceCharTab;
    QListWidget *textListWidget;
    QGroupBox *groupBox;
    QLabel *originalTextLabel;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *newTextLineEdit;
    QPushButton *replaceTextButton;
    QLabel *label_2;
    QLabel *label_4;
    QWidget *replaceImageTab;
    QListWidget *imageListWidget;
    QGroupBox *groupBox_3;
    QLabel *imagePreviewLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLabel *imageCountLabel;
    QSpacerItem *horizontalSpacer_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *chooseImageButton;
    QLineEdit *destImagePathLineEdit;
    QPushButton *replaceImageButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ReplaceAETemplateClass)
    {
        if (ReplaceAETemplateClass->objectName().isEmpty())
            ReplaceAETemplateClass->setObjectName(QStringLiteral("ReplaceAETemplateClass"));
        ReplaceAETemplateClass->resize(600, 400);
        actionOpenFile = new QAction(ReplaceAETemplateClass);
        actionOpenFile->setObjectName(QStringLiteral("actionOpenFile"));
        actionCloseFile = new QAction(ReplaceAETemplateClass);
        actionCloseFile->setObjectName(QStringLiteral("actionCloseFile"));
        actionQuitApplication = new QAction(ReplaceAETemplateClass);
        actionQuitApplication->setObjectName(QStringLiteral("actionQuitApplication"));
        actionDeveloper = new QAction(ReplaceAETemplateClass);
        actionDeveloper->setObjectName(QStringLiteral("actionDeveloper"));
        actionSaveFile = new QAction(ReplaceAETemplateClass);
        actionSaveFile->setObjectName(QStringLiteral("actionSaveFile"));
        centralWidget = new QWidget(ReplaceAETemplateClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(9, 9, 591, 341));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        replaceCharTab = new QWidget();
        replaceCharTab->setObjectName(QStringLiteral("replaceCharTab"));
        textListWidget = new QListWidget(replaceCharTab);
        textListWidget->setObjectName(QStringLiteral("textListWidget"));
        textListWidget->setGeometry(QRect(9, 9, 181, 311));
        groupBox = new QGroupBox(replaceCharTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(200, 10, 351, 81));
        originalTextLabel = new QLabel(groupBox);
        originalTextLabel->setObjectName(QStringLiteral("originalTextLabel"));
        originalTextLabel->setGeometry(QRect(10, 20, 331, 51));
        groupBox_2 = new QGroupBox(replaceCharTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(200, 100, 351, 221));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 54, 12));
        newTextLineEdit = new QLineEdit(groupBox_2);
        newTextLineEdit->setObjectName(QStringLiteral("newTextLineEdit"));
        newTextLineEdit->setGeometry(QRect(10, 50, 251, 21));
        replaceTextButton = new QPushButton(groupBox_2);
        replaceTextButton->setObjectName(QStringLiteral("replaceTextButton"));
        replaceTextButton->setGeometry(QRect(270, 50, 75, 23));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 54, 12));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 110, 331, 41));
        label_4->setStyleSheet(QStringLiteral("font-weight: bold;"));
        tabWidget->addTab(replaceCharTab, QString());
        replaceImageTab = new QWidget();
        replaceImageTab->setObjectName(QStringLiteral("replaceImageTab"));
        imageListWidget = new QListWidget(replaceImageTab);
        imageListWidget->setObjectName(QStringLiteral("imageListWidget"));
        imageListWidget->setGeometry(QRect(9, 9, 181, 311));
        groupBox_3 = new QGroupBox(replaceImageTab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(200, 9, 341, 311));
        imagePreviewLabel = new QLabel(groupBox_3);
        imagePreviewLabel->setObjectName(QStringLiteral("imagePreviewLabel"));
        imagePreviewLabel->setGeometry(QRect(10, 50, 321, 221));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 22, 321, 22));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        imageCountLabel = new QLabel(layoutWidget);
        imageCountLabel->setObjectName(QStringLiteral("imageCountLabel"));

        horizontalLayout_6->addWidget(imageCountLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 270, 321, 31));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        chooseImageButton = new QPushButton(layoutWidget1);
        chooseImageButton->setObjectName(QStringLiteral("chooseImageButton"));

        horizontalLayout_5->addWidget(chooseImageButton);

        destImagePathLineEdit = new QLineEdit(layoutWidget1);
        destImagePathLineEdit->setObjectName(QStringLiteral("destImagePathLineEdit"));
        destImagePathLineEdit->setReadOnly(true);

        horizontalLayout_5->addWidget(destImagePathLineEdit);

        replaceImageButton = new QPushButton(layoutWidget1);
        replaceImageButton->setObjectName(QStringLiteral("replaceImageButton"));

        horizontalLayout_5->addWidget(replaceImageButton);

        tabWidget->addTab(replaceImageTab, QString());
        ReplaceAETemplateClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ReplaceAETemplateClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        ReplaceAETemplateClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(ReplaceAETemplateClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ReplaceAETemplateClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpenFile);
        menuFile->addAction(actionCloseFile);
        menuFile->addAction(actionSaveFile);
        menuFile->addAction(actionQuitApplication);
        menuAbout->addAction(actionDeveloper);

        retranslateUi(ReplaceAETemplateClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ReplaceAETemplateClass);
    } // setupUi

    void retranslateUi(QMainWindow *ReplaceAETemplateClass)
    {
        ReplaceAETemplateClass->setWindowTitle(QApplication::translate("ReplaceAETemplateClass", "ReplaceAETemplate", 0));
        actionOpenFile->setText(QApplication::translate("ReplaceAETemplateClass", "\346\211\223\345\274\200\346\250\241\346\235\277\346\226\207\344\273\266...(&O)", 0));
        actionOpenFile->setShortcut(QApplication::translate("ReplaceAETemplateClass", "Ctrl+O", 0));
        actionCloseFile->setText(QApplication::translate("ReplaceAETemplateClass", "\345\205\263\351\227\255\346\226\207\344\273\266(&C)", 0));
        actionCloseFile->setShortcut(QApplication::translate("ReplaceAETemplateClass", "Ctrl+W", 0));
        actionQuitApplication->setText(QApplication::translate("ReplaceAETemplateClass", "\351\200\200\345\207\272\347\250\213\345\272\217(&Q)", 0));
        actionQuitApplication->setShortcut(QApplication::translate("ReplaceAETemplateClass", "Ctrl+Q", 0));
        actionDeveloper->setText(QApplication::translate("ReplaceAETemplateClass", "\345\274\200\345\217\221\350\200\205(&D)", 0));
        actionSaveFile->setText(QApplication::translate("ReplaceAETemplateClass", "\344\277\235\345\255\230\346\226\207\344\273\266(&S)", 0));
        actionSaveFile->setShortcut(QApplication::translate("ReplaceAETemplateClass", "Ctrl+S", 0));
        groupBox->setTitle(QApplication::translate("ReplaceAETemplateClass", "\345\216\237\345\247\213\346\226\207\346\234\254", 0));
        originalTextLabel->setText(QString());
        groupBox_2->setTitle(QApplication::translate("ReplaceAETemplateClass", "\346\233\277\346\215\242\346\223\215\344\275\234", 0));
        label->setText(QApplication::translate("ReplaceAETemplateClass", "\346\233\277\346\215\242\344\270\272\357\274\232", 0));
        replaceTextButton->setText(QApplication::translate("ReplaceAETemplateClass", "\345\274\200\345\247\213\346\233\277\346\215\242", 0));
        label_2->setText(QApplication::translate("ReplaceAETemplateClass", "\350\257\264\346\230\216\357\274\232", 0));
        label_4->setText(QApplication::translate("ReplaceAETemplateClass", "\346\223\215\344\275\234\345\211\215\345\205\210\345\234\250\350\217\234\345\215\225\346\240\217\344\270\255\346\211\223\345\274\200\350\246\201\344\277\256\346\224\271\347\232\204\346\250\241\346\235\277\346\226\207\344\273\266\343\200\202\345\246\202\345\216\237\346\250\241\346\235\277\n"
"\346\226\207\344\273\266\346\230\257aep\346\240\274\345\274\217\347\232\204\357\274\214\350\257\267\345\205\210\345\217\246\345\255\230\344\270\272aepx\346\240\274\345\274\217\345\206\215\344\275\277\347\224\250\346\234\254\347\250\213\345\272\217\n"
"\346\211\223\345\274\200\346\223\215\344\275\234\343\200\202", 0));
        tabWidget->setTabText(tabWidget->indexOf(replaceCharTab), QApplication::translate("ReplaceAETemplateClass", "\346\250\241\346\235\277\346\226\207\345\255\227\346\233\277\346\215\242", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(replaceCharTab), QApplication::translate("ReplaceAETemplateClass", "\346\233\277\346\215\242\344\272\214\350\277\233\345\210\266\346\250\241\346\235\277\346\226\207\344\273\266\344\270\255\347\232\204\346\214\207\345\256\232\345\255\227\347\254\246\344\270\262", 0));
        groupBox_3->setTitle(QApplication::translate("ReplaceAETemplateClass", "\346\223\215\344\275\234\351\235\242\346\235\277", 0));
        imagePreviewLabel->setText(QString());
        label_3->setText(QApplication::translate("ReplaceAETemplateClass", "\345\233\276\347\211\207\350\265\204\346\272\220ID:", 0));
        imageCountLabel->setText(QApplication::translate("ReplaceAETemplateClass", "0", 0));
        chooseImageButton->setText(QApplication::translate("ReplaceAETemplateClass", "\346\233\277\346\215\242\346\210\220...", 0));
        replaceImageButton->setText(QApplication::translate("ReplaceAETemplateClass", "\347\241\256\345\256\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(replaceImageTab), QApplication::translate("ReplaceAETemplateClass", "\346\250\241\346\235\277\345\233\276\347\211\207\346\233\277\346\215\242", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(replaceImageTab), QApplication::translate("ReplaceAETemplateClass", "\346\233\277\346\215\242\344\272\214\350\277\233\345\210\266\346\250\241\346\235\277\346\226\207\344\273\266\344\270\255\347\232\204\346\214\207\345\256\232\345\233\276\347\211\207", 0));
        menuFile->setTitle(QApplication::translate("ReplaceAETemplateClass", "\346\226\207\344\273\266(&F)", 0));
        menuAbout->setTitle(QApplication::translate("ReplaceAETemplateClass", "\345\205\263\344\272\216(&A)", 0));
    } // retranslateUi

};

namespace Ui {
    class ReplaceAETemplateClass: public Ui_ReplaceAETemplateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLACEAETEMPLATE_H
