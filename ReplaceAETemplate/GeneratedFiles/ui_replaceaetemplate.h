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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplaceAETemplateClass
{
public:
    QAction *actionOpenFile;
    QAction *actionCloseFile;
    QAction *actionQuitApplication;
    QAction *actionDeveloper;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *replaceCharTab;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *sourceCharLineEdit;
    QPushButton *searchCharButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *searchCharResult;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLineEdit *destCharLineEdit;
    QPushButton *replaceCharButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLabel *replaceCharResult;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_9;
    QWidget *replaceImageTab;
    QTreeWidget *imageTreeWidget;
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
        centralWidget = new QWidget(ReplaceAETemplateClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        replaceCharTab = new QWidget();
        replaceCharTab->setObjectName(QStringLiteral("replaceCharTab"));
        verticalLayout_4 = new QVBoxLayout(replaceCharTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox = new QGroupBox(replaceCharTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        sourceCharLineEdit = new QLineEdit(groupBox);
        sourceCharLineEdit->setObjectName(QStringLiteral("sourceCharLineEdit"));

        horizontalLayout->addWidget(sourceCharLineEdit);

        searchCharButton = new QPushButton(groupBox);
        searchCharButton->setObjectName(QStringLiteral("searchCharButton"));

        horizontalLayout->addWidget(searchCharButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        searchCharResult = new QLabel(groupBox);
        searchCharResult->setObjectName(QStringLiteral("searchCharResult"));

        horizontalLayout_2->addWidget(searchCharResult);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setScaledContents(false);

        verticalLayout_2->addWidget(label_4);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(replaceCharTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        destCharLineEdit = new QLineEdit(groupBox_2);
        destCharLineEdit->setObjectName(QStringLiteral("destCharLineEdit"));

        horizontalLayout_3->addWidget(destCharLineEdit);

        replaceCharButton = new QPushButton(groupBox_2);
        replaceCharButton->setObjectName(QStringLiteral("replaceCharButton"));

        horizontalLayout_3->addWidget(replaceCharButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        replaceCharResult = new QLabel(groupBox_2);
        replaceCharResult->setObjectName(QStringLiteral("replaceCharResult"));

        horizontalLayout_4->addWidget(replaceCharResult);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_3->addWidget(label_9);


        verticalLayout_4->addWidget(groupBox_2);

        tabWidget->addTab(replaceCharTab, QString());
        replaceImageTab = new QWidget();
        replaceImageTab->setObjectName(QStringLiteral("replaceImageTab"));
        imageTreeWidget = new QTreeWidget(replaceImageTab);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        imageTreeWidget->setHeaderItem(__qtreewidgetitem);
        imageTreeWidget->setObjectName(QStringLiteral("imageTreeWidget"));
        imageTreeWidget->setGeometry(QRect(9, 9, 181, 311));
        groupBox_3 = new QGroupBox(replaceImageTab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(200, 9, 341, 311));
        imagePreviewLabel = new QLabel(groupBox_3);
        imagePreviewLabel->setObjectName(QStringLiteral("imagePreviewLabel"));
        imagePreviewLabel->setGeometry(QRect(10, 54, 371, 221));
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

        verticalLayout->addWidget(tabWidget);

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
        groupBox->setTitle(QApplication::translate("ReplaceAETemplateClass", "\346\237\245\346\211\276", 0));
        label->setText(QApplication::translate("ReplaceAETemplateClass", "\345\260\206\350\246\201\346\233\277\346\215\242\347\232\204\345\255\227\347\254\246\344\270\262:", 0));
        searchCharButton->setText(QApplication::translate("ReplaceAETemplateClass", "\345\274\200\345\247\213\346\237\245\346\211\276", 0));
        label_2->setText(QApplication::translate("ReplaceAETemplateClass", "\346\237\245\346\211\276\347\273\223\346\236\234:", 0));
        searchCharResult->setText(QApplication::translate("ReplaceAETemplateClass", "0", 0));
        label_4->setText(QApplication::translate("ReplaceAETemplateClass", "\350\257\264\346\230\216\357\274\232\345\205\210\350\276\223\345\205\245\350\246\201\346\233\277\346\215\242\347\232\204\345\255\227\347\254\246\344\270\262\357\274\214\347\250\213\345\272\217\345\260\206\345\234\250\344\272\214\350\277\233\345\210\266\346\250\241\346\235\277\346\226\207\344\273\266\344\270\255\350\277\233\350\241\214\346\237\245\346\211\276\343\200\202\345\246\202\346\236\234\346\262\241\346\234\211\346\211\276\345\210\260\345\255\227\347\254\246\344\270\262\357\274\214\n"
"\345\210\231\344\270\215\350\203\275\350\277\233\350\241\214\346\233\277\346\215\242\346\223\215\344\275\234\357\274\201", 0));
        groupBox_2->setTitle(QApplication::translate("ReplaceAETemplateClass", "\346\233\277\346\215\242", 0));
        label_5->setText(QApplication::translate("ReplaceAETemplateClass", "\346\233\277\346\215\242\347\232\204\347\233\256\346\240\207\345\255\227\347\254\246\344\270\262:", 0));
        replaceCharButton->setText(QApplication::translate("ReplaceAETemplateClass", "\345\274\200\345\247\213\346\233\277\346\215\242", 0));
        label_6->setText(QApplication::translate("ReplaceAETemplateClass", "\346\233\277\346\215\242\347\273\223\346\236\234:", 0));
        replaceCharResult->setText(QApplication::translate("ReplaceAETemplateClass", "0", 0));
        label_8->setText(QApplication::translate("ReplaceAETemplateClass", "\346\235\241\345\256\214\346\210\220\346\233\277\346\215\242", 0));
        label_9->setText(QApplication::translate("ReplaceAETemplateClass", "\350\257\264\346\230\216\357\274\232\346\233\277\346\215\242\345\220\216\345\215\263\345\217\257\346\211\223\345\274\200\346\250\241\346\235\277\350\277\233\350\241\214\346\237\245\347\234\213\343\200\202", 0));
        tabWidget->setTabText(tabWidget->indexOf(replaceCharTab), QApplication::translate("ReplaceAETemplateClass", "\346\250\241\346\235\277\346\226\207\345\255\227\346\233\277\346\215\242", 0));
        tabWidget->setTabToolTip(tabWidget->indexOf(replaceCharTab), QApplication::translate("ReplaceAETemplateClass", "\346\233\277\346\215\242\344\272\214\350\277\233\345\210\266\346\250\241\346\235\277\346\226\207\344\273\266\344\270\255\347\232\204\346\214\207\345\256\232\345\255\227\347\254\246\344\270\262", 0));
        groupBox_3->setTitle(QApplication::translate("ReplaceAETemplateClass", "\346\223\215\344\275\234\351\235\242\346\235\277", 0));
        imagePreviewLabel->setText(QApplication::translate("ReplaceAETemplateClass", "TextLabel", 0));
        label_3->setText(QApplication::translate("ReplaceAETemplateClass", "\345\233\276\347\211\207\351\242\204\350\247\210ID:", 0));
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
