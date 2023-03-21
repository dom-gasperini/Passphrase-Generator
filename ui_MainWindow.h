/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDark_Mode;
    QAction *actionAbout;
    QWidget *centralwidget;
    QPushButton *generatePhrasesBtn;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *selectComplexityLbl;
    QComboBox *complexityCmbx;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *exampleComplexityLbl;
    QLineEdit *exampleComplexityTextLineE;
    QMenuBar *menubar;
    QMenu *menuSettings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(275, 325);
        MainWindow->setMinimumSize(QSize(275, 325));
        MainWindow->setMaximumSize(QSize(375, 325));
        actionDark_Mode = new QAction(MainWindow);
        actionDark_Mode->setObjectName("actionDark_Mode");
        actionDark_Mode->setCheckable(true);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        generatePhrasesBtn = new QPushButton(centralwidget);
        generatePhrasesBtn->setObjectName("generatePhrasesBtn");
        generatePhrasesBtn->setGeometry(QRect(20, 220, 231, 51));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 251, 201));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 30, 191, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        selectComplexityLbl = new QLabel(layoutWidget);
        selectComplexityLbl->setObjectName("selectComplexityLbl");
        selectComplexityLbl->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        selectComplexityLbl->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(selectComplexityLbl);

        complexityCmbx = new QComboBox(layoutWidget);
        complexityCmbx->addItem(QString());
        complexityCmbx->addItem(QString());
        complexityCmbx->addItem(QString());
        complexityCmbx->setObjectName("complexityCmbx");

        verticalLayout->addWidget(complexityCmbx);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 110, 231, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        exampleComplexityLbl = new QLabel(layoutWidget1);
        exampleComplexityLbl->setObjectName("exampleComplexityLbl");
        exampleComplexityLbl->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Segoe UI\";\n"
"text-decoration: underline;"));
        exampleComplexityLbl->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(exampleComplexityLbl);

        exampleComplexityTextLineE = new QLineEdit(layoutWidget1);
        exampleComplexityTextLineE->setObjectName("exampleComplexityTextLineE");
        exampleComplexityTextLineE->setAlignment(Qt::AlignCenter);
        exampleComplexityTextLineE->setReadOnly(true);

        verticalLayout_2->addWidget(exampleComplexityTextLineE);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 275, 25));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSettings->menuAction());
        menuSettings->addAction(actionDark_Mode);
        menuSettings->addAction(actionAbout);

        retranslateUi(MainWindow);

        complexityCmbx->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionDark_Mode->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        generatePhrasesBtn->setText(QCoreApplication::translate("MainWindow", "Generate Phrases", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Setup", nullptr));
        selectComplexityLbl->setText(QCoreApplication::translate("MainWindow", "Select Complexity Level:", nullptr));
        complexityCmbx->setItemText(0, QCoreApplication::translate("MainWindow", "Basic", nullptr));
        complexityCmbx->setItemText(1, QCoreApplication::translate("MainWindow", "Moderate", nullptr));
        complexityCmbx->setItemText(2, QCoreApplication::translate("MainWindow", "Complex", nullptr));

        exampleComplexityLbl->setText(QCoreApplication::translate("MainWindow", "Example of Phrase Complexity:", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
