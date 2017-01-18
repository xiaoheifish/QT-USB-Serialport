/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *textSelfRead_2;
    QLineEdit *textSelfWrite_2;
    QPushButton *buttonSelfWrite_2;
    QPushButton *buttonSelfRead_2;
    QComboBox *serialPortComboBox;
    QComboBox *comboBoxBaud;
    QLabel *totalCount1_2;
    QGroupBox *groupBox_5;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *labelPath13_2;
    QLabel *labelPath14_2;
    QLabel *label_9;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *labelPath24_2;
    QLabel *labelPath11_2;
    QLabel *labelPath12_2;
    QLabel *label_12;
    QLabel *labelPath21_2;
    QLabel *labelPath22_2;
    QLabel *labelPath23_2;
    QLabel *labelCount1_2;
    QLabel *labelCount2_2;
    QGroupBox *groupBox_6;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QCheckBox *checkBoxPathTwo_2;
    QLineEdit *textPathOne_2;
    QCheckBox *checkBoxPathOne_2;
    QLineEdit *textPathTwo_2;
    QPushButton *buttonAddWrite_2;
    QPushButton *buttonReadStop;
    QTextBrowser *textBrowserPathOne_2;
    QLabel *totalCount2_2;
    QTextBrowser *textBrowserPathTwo_2;
    QPushButton *pushButton;
    QRadioButton *radioButtonSerial;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *labelPath14;
    QLabel *label_2;
    QLabel *labelPath13;
    QLabel *labelPath11;
    QLabel *labelPath24;
    QLabel *label_5;
    QLabel *labelPath12;
    QLabel *labelPath23;
    QLabel *labelPath22;
    QLabel *labelPath21;
    QLabel *labelCount2;
    QLabel *labelCount1;
    QLabel *totalCount2;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBoxPathTwo;
    QLineEdit *textPathOne;
    QLineEdit *textPathTwo;
    QCheckBox *checkBoxPathOne;
    QPushButton *buttonAddWrite;
    QTextBrowser *textBrowserPathTwo;
    QLabel *totalCount1;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *textSelfWrite;
    QPushButton *buttonSelfWrite;
    QLabel *textSelfRead;
    QPushButton *buttonSelfRead;
    QTextBrowser *textBrowserPathOne;
    QRadioButton *radioButtonUSB;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(631, 594);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 631, 521));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 40, 341, 80));
        gridLayoutWidget_4 = new QWidget(groupBox_4);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 20, 321, 54));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        textSelfRead_2 = new QLabel(gridLayoutWidget_4);
        textSelfRead_2->setObjectName(QStringLiteral("textSelfRead_2"));

        gridLayout_4->addWidget(textSelfRead_2, 1, 1, 1, 1);

        textSelfWrite_2 = new QLineEdit(gridLayoutWidget_4);
        textSelfWrite_2->setObjectName(QStringLiteral("textSelfWrite_2"));

        gridLayout_4->addWidget(textSelfWrite_2, 0, 1, 1, 1);

        buttonSelfWrite_2 = new QPushButton(gridLayoutWidget_4);
        buttonSelfWrite_2->setObjectName(QStringLiteral("buttonSelfWrite_2"));

        gridLayout_4->addWidget(buttonSelfWrite_2, 0, 2, 1, 1);

        buttonSelfRead_2 = new QPushButton(gridLayoutWidget_4);
        buttonSelfRead_2->setObjectName(QStringLiteral("buttonSelfRead_2"));

        gridLayout_4->addWidget(buttonSelfRead_2, 1, 2, 1, 1);

        serialPortComboBox = new QComboBox(gridLayoutWidget_4);
        serialPortComboBox->setObjectName(QStringLiteral("serialPortComboBox"));
        serialPortComboBox->setMinimumSize(QSize(100, 0));

        gridLayout_4->addWidget(serialPortComboBox, 0, 0, 1, 1);

        comboBoxBaud = new QComboBox(gridLayoutWidget_4);
        comboBoxBaud->setObjectName(QStringLiteral("comboBoxBaud"));

        gridLayout_4->addWidget(comboBoxBaud, 1, 0, 1, 1);

        totalCount1_2 = new QLabel(tab);
        totalCount1_2->setObjectName(QStringLiteral("totalCount1_2"));
        totalCount1_2->setGeometry(QRect(370, 240, 54, 12));
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 230, 341, 221));
        gridLayoutWidget_5 = new QWidget(groupBox_5);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 20, 321, 191));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_5->addWidget(label_7, 4, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_5);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_5->addWidget(label_8, 0, 1, 1, 1);

        labelPath13_2 = new QLabel(gridLayoutWidget_5);
        labelPath13_2->setObjectName(QStringLiteral("labelPath13_2"));

        gridLayout_5->addWidget(labelPath13_2, 3, 1, 1, 1);

        labelPath14_2 = new QLabel(gridLayoutWidget_5);
        labelPath14_2->setObjectName(QStringLiteral("labelPath14_2"));

        gridLayout_5->addWidget(labelPath14_2, 4, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_5->addWidget(label_9, 1, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 2, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_5->addWidget(label_10, 0, 2, 1, 1);

        labelPath24_2 = new QLabel(gridLayoutWidget_5);
        labelPath24_2->setObjectName(QStringLiteral("labelPath24_2"));

        gridLayout_5->addWidget(labelPath24_2, 4, 2, 1, 1);

        labelPath11_2 = new QLabel(gridLayoutWidget_5);
        labelPath11_2->setObjectName(QStringLiteral("labelPath11_2"));

        gridLayout_5->addWidget(labelPath11_2, 1, 1, 1, 1);

        labelPath12_2 = new QLabel(gridLayoutWidget_5);
        labelPath12_2->setObjectName(QStringLiteral("labelPath12_2"));

        gridLayout_5->addWidget(labelPath12_2, 2, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 3, 0, 1, 1);

        labelPath21_2 = new QLabel(gridLayoutWidget_5);
        labelPath21_2->setObjectName(QStringLiteral("labelPath21_2"));

        gridLayout_5->addWidget(labelPath21_2, 1, 2, 1, 1);

        labelPath22_2 = new QLabel(gridLayoutWidget_5);
        labelPath22_2->setObjectName(QStringLiteral("labelPath22_2"));

        gridLayout_5->addWidget(labelPath22_2, 2, 2, 1, 1);

        labelPath23_2 = new QLabel(gridLayoutWidget_5);
        labelPath23_2->setObjectName(QStringLiteral("labelPath23_2"));

        gridLayout_5->addWidget(labelPath23_2, 3, 2, 1, 1);

        labelCount1_2 = new QLabel(gridLayoutWidget_5);
        labelCount1_2->setObjectName(QStringLiteral("labelCount1_2"));

        gridLayout_5->addWidget(labelCount1_2, 5, 1, 1, 1);

        labelCount2_2 = new QLabel(gridLayoutWidget_5);
        labelCount2_2->setObjectName(QStringLiteral("labelCount2_2"));

        gridLayout_5->addWidget(labelCount2_2, 5, 2, 1, 1);

        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 130, 341, 91));
        gridLayoutWidget_6 = new QWidget(groupBox_6);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 20, 321, 73));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        checkBoxPathTwo_2 = new QCheckBox(gridLayoutWidget_6);
        checkBoxPathTwo_2->setObjectName(QStringLiteral("checkBoxPathTwo_2"));

        gridLayout_6->addWidget(checkBoxPathTwo_2, 0, 1, 1, 1);

        textPathOne_2 = new QLineEdit(gridLayoutWidget_6);
        textPathOne_2->setObjectName(QStringLiteral("textPathOne_2"));

        gridLayout_6->addWidget(textPathOne_2, 1, 0, 1, 1);

        checkBoxPathOne_2 = new QCheckBox(gridLayoutWidget_6);
        checkBoxPathOne_2->setObjectName(QStringLiteral("checkBoxPathOne_2"));

        gridLayout_6->addWidget(checkBoxPathOne_2, 0, 0, 1, 1);

        textPathTwo_2 = new QLineEdit(gridLayoutWidget_6);
        textPathTwo_2->setObjectName(QStringLiteral("textPathTwo_2"));

        gridLayout_6->addWidget(textPathTwo_2, 1, 1, 1, 1);

        buttonAddWrite_2 = new QPushButton(gridLayoutWidget_6);
        buttonAddWrite_2->setObjectName(QStringLiteral("buttonAddWrite_2"));

        gridLayout_6->addWidget(buttonAddWrite_2, 1, 2, 1, 1);

        buttonReadStop = new QPushButton(gridLayoutWidget_6);
        buttonReadStop->setObjectName(QStringLiteral("buttonReadStop"));

        gridLayout_6->addWidget(buttonReadStop, 0, 2, 1, 1);

        gridLayoutWidget_6->raise();
        buttonAddWrite_2->raise();
        textBrowserPathOne_2 = new QTextBrowser(tab);
        textBrowserPathOne_2->setObjectName(QStringLiteral("textBrowserPathOne_2"));
        textBrowserPathOne_2->setGeometry(QRect(360, 50, 256, 181));
        totalCount2_2 = new QLabel(tab);
        totalCount2_2->setObjectName(QStringLiteral("totalCount2_2"));
        totalCount2_2->setGeometry(QRect(370, 450, 54, 12));
        textBrowserPathTwo_2 = new QTextBrowser(tab);
        textBrowserPathTwo_2->setObjectName(QStringLiteral("textBrowserPathTwo_2"));
        textBrowserPathTwo_2->setGeometry(QRect(360, 260, 256, 181));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 460, 75, 23));
        radioButtonSerial = new QRadioButton(tab);
        radioButtonSerial->setObjectName(QStringLiteral("radioButtonSerial"));
        radioButtonSerial->setGeometry(QRect(20, 10, 89, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 230, 341, 221));
        gridLayoutWidget_3 = new QWidget(groupBox_3);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 321, 191));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 4, 0, 1, 1);

        label = new QLabel(gridLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        labelPath14 = new QLabel(gridLayoutWidget_3);
        labelPath14->setObjectName(QStringLiteral("labelPath14"));

        gridLayout_3->addWidget(labelPath14, 4, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 0, 2, 1, 1);

        labelPath13 = new QLabel(gridLayoutWidget_3);
        labelPath13->setObjectName(QStringLiteral("labelPath13"));

        gridLayout_3->addWidget(labelPath13, 3, 1, 1, 1);

        labelPath11 = new QLabel(gridLayoutWidget_3);
        labelPath11->setObjectName(QStringLiteral("labelPath11"));

        gridLayout_3->addWidget(labelPath11, 1, 1, 1, 1);

        labelPath24 = new QLabel(gridLayoutWidget_3);
        labelPath24->setObjectName(QStringLiteral("labelPath24"));

        gridLayout_3->addWidget(labelPath24, 4, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        labelPath12 = new QLabel(gridLayoutWidget_3);
        labelPath12->setObjectName(QStringLiteral("labelPath12"));

        gridLayout_3->addWidget(labelPath12, 2, 1, 1, 1);

        labelPath23 = new QLabel(gridLayoutWidget_3);
        labelPath23->setObjectName(QStringLiteral("labelPath23"));

        gridLayout_3->addWidget(labelPath23, 3, 2, 1, 1);

        labelPath22 = new QLabel(gridLayoutWidget_3);
        labelPath22->setObjectName(QStringLiteral("labelPath22"));

        gridLayout_3->addWidget(labelPath22, 2, 2, 1, 1);

        labelPath21 = new QLabel(gridLayoutWidget_3);
        labelPath21->setObjectName(QStringLiteral("labelPath21"));

        gridLayout_3->addWidget(labelPath21, 1, 2, 1, 1);

        labelCount2 = new QLabel(gridLayoutWidget_3);
        labelCount2->setObjectName(QStringLiteral("labelCount2"));

        gridLayout_3->addWidget(labelCount2, 5, 2, 1, 1);

        labelCount1 = new QLabel(gridLayoutWidget_3);
        labelCount1->setObjectName(QStringLiteral("labelCount1"));

        gridLayout_3->addWidget(labelCount1, 5, 1, 1, 1);

        totalCount2 = new QLabel(tab_2);
        totalCount2->setObjectName(QStringLiteral("totalCount2"));
        totalCount2->setGeometry(QRect(370, 450, 54, 12));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 130, 341, 91));
        gridLayoutWidget_2 = new QWidget(groupBox_2);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 321, 61));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBoxPathTwo = new QCheckBox(gridLayoutWidget_2);
        checkBoxPathTwo->setObjectName(QStringLiteral("checkBoxPathTwo"));

        gridLayout_2->addWidget(checkBoxPathTwo, 0, 1, 1, 1);

        textPathOne = new QLineEdit(gridLayoutWidget_2);
        textPathOne->setObjectName(QStringLiteral("textPathOne"));

        gridLayout_2->addWidget(textPathOne, 1, 0, 1, 1);

        textPathTwo = new QLineEdit(gridLayoutWidget_2);
        textPathTwo->setObjectName(QStringLiteral("textPathTwo"));

        gridLayout_2->addWidget(textPathTwo, 1, 1, 1, 1);

        checkBoxPathOne = new QCheckBox(gridLayoutWidget_2);
        checkBoxPathOne->setObjectName(QStringLiteral("checkBoxPathOne"));

        gridLayout_2->addWidget(checkBoxPathOne, 0, 0, 1, 1);

        buttonAddWrite = new QPushButton(gridLayoutWidget_2);
        buttonAddWrite->setObjectName(QStringLiteral("buttonAddWrite"));

        gridLayout_2->addWidget(buttonAddWrite, 1, 2, 1, 1);

        textBrowserPathTwo = new QTextBrowser(tab_2);
        textBrowserPathTwo->setObjectName(QStringLiteral("textBrowserPathTwo"));
        textBrowserPathTwo->setGeometry(QRect(360, 260, 256, 181));
        totalCount1 = new QLabel(tab_2);
        totalCount1->setObjectName(QStringLiteral("totalCount1"));
        totalCount1->setGeometry(QRect(370, 240, 54, 12));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 341, 80));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 171, 54));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textSelfWrite = new QLineEdit(gridLayoutWidget);
        textSelfWrite->setObjectName(QStringLiteral("textSelfWrite"));

        gridLayout->addWidget(textSelfWrite, 0, 0, 1, 1);

        buttonSelfWrite = new QPushButton(gridLayoutWidget);
        buttonSelfWrite->setObjectName(QStringLiteral("buttonSelfWrite"));

        gridLayout->addWidget(buttonSelfWrite, 0, 1, 1, 1);

        textSelfRead = new QLabel(gridLayoutWidget);
        textSelfRead->setObjectName(QStringLiteral("textSelfRead"));

        gridLayout->addWidget(textSelfRead, 1, 0, 1, 1);

        buttonSelfRead = new QPushButton(gridLayoutWidget);
        buttonSelfRead->setObjectName(QStringLiteral("buttonSelfRead"));

        gridLayout->addWidget(buttonSelfRead, 1, 1, 1, 1);

        textBrowserPathOne = new QTextBrowser(tab_2);
        textBrowserPathOne->setObjectName(QStringLiteral("textBrowserPathOne"));
        textBrowserPathOne->setGeometry(QRect(360, 50, 256, 181));
        radioButtonUSB = new QRadioButton(tab_2);
        radioButtonUSB->setObjectName(QStringLiteral("radioButtonUSB"));
        radioButtonUSB->setGeometry(QRect(20, 10, 89, 16));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 631, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\350\207\252\346\243\200", 0));
        textSelfRead_2->setText(QApplication::translate("MainWindow", "0", 0));
        buttonSelfWrite_2->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245", 0));
        buttonSelfRead_2->setText(QApplication::translate("MainWindow", "\350\257\273\345\207\272", 0));
        comboBoxBaud->clear();
        comboBoxBaud->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "115200", 0)
         << QApplication::translate("MainWindow", "57600", 0)
         << QApplication::translate("MainWindow", "38400", 0)
         << QApplication::translate("MainWindow", "19200", 0)
         << QApplication::translate("MainWindow", "9600", 0)
        );
        totalCount1_2->setText(QApplication::translate("MainWindow", "0", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "SSI\346\216\245\345\217\243\344\274\240\346\204\237\345\231\250\346\225\260\346\215\256", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\206\205\351\203\250\345\257\204\345\255\230\345\231\2504", 0));
        label_8->setText(QApplication::translate("MainWindow", "\347\254\254\344\270\200\350\267\257", 0));
        labelPath13_2->setText(QApplication::translate("MainWindow", "0", 0));
        labelPath14_2->setText(QApplication::translate("MainWindow", "0", 0));
        label_9->setText(QApplication::translate("MainWindow", "\345\206\205\351\203\250\345\257\204\345\255\230\345\231\2501", 0));
        label_11->setText(QApplication::translate("MainWindow", "\345\206\205\351\203\250\345\257\204\345\255\230\345\231\2502", 0));
        label_10->setText(QApplication::translate("MainWindow", "\347\254\254\344\272\214\350\267\257", 0));
        labelPath24_2->setText(QApplication::translate("MainWindow", "0", 0));
        labelPath11_2->setText(QApplication::translate("MainWindow", "0", 0));
        labelPath12_2->setText(QApplication::translate("MainWindow", "0", 0));
        label_12->setText(QApplication::translate("MainWindow", "\345\206\205\351\203\250\345\257\204\345\255\230\345\231\2503", 0));
        labelPath21_2->setText(QApplication::translate("MainWindow", "0", 0));
        labelPath22_2->setText(QApplication::translate("MainWindow", "0", 0));
        labelPath23_2->setText(QApplication::translate("MainWindow", "0", 0));
        labelCount1_2->setText(QApplication::translate("MainWindow", "0", 0));
        labelCount2_2->setText(QApplication::translate("MainWindow", "0", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "SSI\346\216\245\345\217\243\344\274\240\346\204\237\345\231\250\344\275\215\346\225\260\350\256\276\347\275\256", 0));
        checkBoxPathTwo_2->setText(QApplication::translate("MainWindow", "\347\254\254\344\272\214\350\267\257", 0));
        checkBoxPathOne_2->setText(QApplication::translate("MainWindow", "\347\254\254\344\270\200\350\267\257", 0));
        buttonAddWrite_2->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245", 0));
        buttonReadStop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
        totalCount2_2->setText(QApplication::translate("MainWindow", "0", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\345\215\225\346\254\241", 0));
        radioButtonSerial->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\344\270\262\345\217\243", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "SSI\346\216\245\345\217\243\344\274\240\346\204\237\345\231\250\346\225\260\346\215\256", 0));
        label_6->setText(QApplication::translate("MainWindow", "\345\206\205\351\203\250\345\257\204\345\255\230\345\231\2504", 0));
        label->setText(QApplication::translate("MainWindow", "\347\254\254\344\270\200\350\267\257", 0));
        label_4->setText(QApplication::translate("MainWindow", "\345\206\205\351\203\250\345\257\204\345\255\230\345\231\2501", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\206\205\351\203\250\345\257\204\345\255\230\345\231\2502", 0));
        labelPath14->setText(QApplication::translate("MainWindow", "0", 0));
        label_2->setText(QApplication::translate("MainWindow", "\347\254\254\344\272\214\350\267\257", 0));
        labelPath13->setText(QApplication::translate("MainWindow", "0", 0));
        labelPath11->setText(QApplication::translate("MainWindow", "0", 0));
        labelPath24->setText(QApplication::translate("MainWindow", "0", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\206\205\351\203\250\345\257\204\345\255\230\345\231\2503", 0));
        labelPath12->setText(QApplication::translate("MainWindow", "0", 0));
        labelPath23->setText(QApplication::translate("MainWindow", "0", 0));
        labelPath22->setText(QApplication::translate("MainWindow", "0", 0));
        labelPath21->setText(QApplication::translate("MainWindow", "0", 0));
        labelCount2->setText(QApplication::translate("MainWindow", "0", 0));
        labelCount1->setText(QApplication::translate("MainWindow", "0", 0));
        totalCount2->setText(QApplication::translate("MainWindow", "0", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "SSI\346\216\245\345\217\243\344\274\240\346\204\237\345\231\250\344\275\215\346\225\260\350\256\276\347\275\256", 0));
        checkBoxPathTwo->setText(QApplication::translate("MainWindow", "\347\254\254\344\272\214\350\267\257", 0));
        checkBoxPathOne->setText(QApplication::translate("MainWindow", "\347\254\254\344\270\200\350\267\257", 0));
        buttonAddWrite->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245", 0));
        totalCount1->setText(QApplication::translate("MainWindow", "0", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\207\252\346\243\200", 0));
        buttonSelfWrite->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245", 0));
        textSelfRead->setText(QApplication::translate("MainWindow", "0", 0));
        buttonSelfRead->setText(QApplication::translate("MainWindow", "\350\257\273\345\207\272", 0));
        radioButtonUSB->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "USB", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
