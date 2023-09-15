/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace ui {

class Ui_MainWindow
{
public:
    QAction *actionguanyu;
    QAction *actionopenTcp;
    QAction *actioncloseTcp;
    QAction *actionfile;
    QAction *actionloadFile;
    QAction *actiondataPicture;
    QAction *actionAMOLED;
    QAction *actionConsoleStyle;
    QAction *actionManjaroMix;
    QAction *actionMatrialDark;
    QAction *actionpoint_2;
    QAction *actiontriangleColor;
    QAction *actiontriangle_2;
    QAction *actiontriangleColor_2;
    QAction *actionpointColor;
    QAction *actiondefault;
    QAction *actionHV;
    QAction *actionGND;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Button1;
    QPushButton *Button2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Button3;
    QPushButton *Button4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_7;
    QGridLayout *gridLayout_5;
    QLabel *label_8;
    QPushButton *ascBtn;
    QPushButton *descBtn;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *comboBox;
    QComboBox *comboBox_1;
    QGridLayout *gridLayout;
    QPushButton *qurryBtn;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_10;
    QLineEdit *qurryLine_1;
    QLineEdit *qurryLine_2;
    QHBoxLayout *horizontalLayout_12;
    QComboBox *comboBox_2;
    QComboBox *comboBox_4;
    QGridLayout *gridLayout_4;
    QLabel *label_9;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_9;
    QLineEdit *qurryLine_3;
    QLineEdit *qurryLine_4;
    QLineEdit *qurryLine_5;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *delBtn;
    QCheckBox *checkBox_del;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *Button5;
    QPushButton *Button6;
    QPushButton *pictureShowBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QMenu *menu_7;
    QMenu *menu_8;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ui__MainWindow)
    {
        if (ui__MainWindow->objectName().isEmpty())
            ui__MainWindow->setObjectName("ui__MainWindow");
        ui__MainWindow->resize(1054, 539);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ui__MainWindow->sizePolicy().hasHeightForWidth());
        ui__MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("weather-fog");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8(":/icon/qss/3.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        ui__MainWindow->setWindowIcon(icon);
        actionguanyu = new QAction(ui__MainWindow);
        actionguanyu->setObjectName("actionguanyu");
        actionopenTcp = new QAction(ui__MainWindow);
        actionopenTcp->setObjectName("actionopenTcp");
        actioncloseTcp = new QAction(ui__MainWindow);
        actioncloseTcp->setObjectName("actioncloseTcp");
        actionfile = new QAction(ui__MainWindow);
        actionfile->setObjectName("actionfile");
        actionloadFile = new QAction(ui__MainWindow);
        actionloadFile->setObjectName("actionloadFile");
        actiondataPicture = new QAction(ui__MainWindow);
        actiondataPicture->setObjectName("actiondataPicture");
        actionAMOLED = new QAction(ui__MainWindow);
        actionAMOLED->setObjectName("actionAMOLED");
        actionConsoleStyle = new QAction(ui__MainWindow);
        actionConsoleStyle->setObjectName("actionConsoleStyle");
        actionManjaroMix = new QAction(ui__MainWindow);
        actionManjaroMix->setObjectName("actionManjaroMix");
        actionMatrialDark = new QAction(ui__MainWindow);
        actionMatrialDark->setObjectName("actionMatrialDark");
        actionpoint_2 = new QAction(ui__MainWindow);
        actionpoint_2->setObjectName("actionpoint_2");
        actionpoint_2->setCheckable(true);
        actiontriangleColor = new QAction(ui__MainWindow);
        actiontriangleColor->setObjectName("actiontriangleColor");
        actiontriangle_2 = new QAction(ui__MainWindow);
        actiontriangle_2->setObjectName("actiontriangle_2");
        actiontriangle_2->setCheckable(true);
        actiontriangleColor_2 = new QAction(ui__MainWindow);
        actiontriangleColor_2->setObjectName("actiontriangleColor_2");
        actiontriangleColor_2->setCheckable(true);
        actionpointColor = new QAction(ui__MainWindow);
        actionpointColor->setObjectName("actionpointColor");
        actionpointColor->setCheckable(true);
        actiondefault = new QAction(ui__MainWindow);
        actiondefault->setObjectName("actiondefault");
        actionHV = new QAction(ui__MainWindow);
        actionHV->setObjectName("actionHV");
        actionHV->setCheckable(true);
        actionGND = new QAction(ui__MainWindow);
        actionGND->setObjectName("actionGND");
        actionGND->setCheckable(true);
        centralwidget = new QWidget(ui__MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(label_3);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(label_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        Button1 = new QPushButton(centralwidget);
        Button1->setObjectName("Button1");
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Button1->sizePolicy().hasHeightForWidth());
        Button1->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(12);
        Button1->setFont(font);

        horizontalLayout_2->addWidget(Button1);

        Button2 = new QPushButton(centralwidget);
        Button2->setObjectName("Button2");
        sizePolicy2.setHeightForWidth(Button2->sizePolicy().hasHeightForWidth());
        Button2->setSizePolicy(sizePolicy2);
        Button2->setFont(font);

        horizontalLayout_2->addWidget(Button2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        Button3 = new QPushButton(centralwidget);
        Button3->setObjectName("Button3");
        sizePolicy2.setHeightForWidth(Button3->sizePolicy().hasHeightForWidth());
        Button3->setSizePolicy(sizePolicy2);
        Button3->setFont(font);

        horizontalLayout_3->addWidget(Button3);

        Button4 = new QPushButton(centralwidget);
        Button4->setObjectName("Button4");
        sizePolicy2.setHeightForWidth(Button4->sizePolicy().hasHeightForWidth());
        Button4->setSizePolicy(sizePolicy2);
        Button4->setFont(font);

        horizontalLayout_3->addWidget(Button4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(label_7);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        ascBtn = new QPushButton(centralwidget);
        ascBtn->setObjectName("ascBtn");

        gridLayout_5->addWidget(ascBtn, 2, 0, 1, 1);

        descBtn = new QPushButton(centralwidget);
        descBtn->setObjectName("descBtn");

        gridLayout_5->addWidget(descBtn, 3, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");

        horizontalLayout_8->addWidget(comboBox);

        comboBox_1 = new QComboBox(centralwidget);
        comboBox_1->setObjectName("comboBox_1");

        horizontalLayout_8->addWidget(comboBox_1);


        gridLayout_5->addLayout(horizontalLayout_8, 1, 0, 1, 1);


        horizontalLayout_7->addLayout(gridLayout_5);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        qurryBtn = new QPushButton(centralwidget);
        qurryBtn->setObjectName("qurryBtn");
        sizePolicy2.setHeightForWidth(qurryBtn->sizePolicy().hasHeightForWidth());
        qurryBtn->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(qurryBtn, 3, 0, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        qurryLine_1 = new QLineEdit(centralwidget);
        qurryLine_1->setObjectName("qurryLine_1");

        horizontalLayout_10->addWidget(qurryLine_1);

        qurryLine_2 = new QLineEdit(centralwidget);
        qurryLine_2->setObjectName("qurryLine_2");

        horizontalLayout_10->addWidget(qurryLine_2);


        gridLayout->addLayout(horizontalLayout_10, 2, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName("comboBox_2");

        horizontalLayout_12->addWidget(comboBox_2);

        comboBox_4 = new QComboBox(centralwidget);
        comboBox_4->setObjectName("comboBox_4");

        horizontalLayout_12->addWidget(comboBox_4);


        gridLayout->addLayout(horizontalLayout_12, 1, 0, 1, 1);


        horizontalLayout_7->addLayout(gridLayout);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_9, 0, 0, 1, 1);

        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->setObjectName("comboBox_3");

        gridLayout_4->addWidget(comboBox_3, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        qurryLine_3 = new QLineEdit(centralwidget);
        qurryLine_3->setObjectName("qurryLine_3");
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(qurryLine_3->sizePolicy().hasHeightForWidth());
        qurryLine_3->setSizePolicy(sizePolicy4);

        horizontalLayout_9->addWidget(qurryLine_3);

        qurryLine_4 = new QLineEdit(centralwidget);
        qurryLine_4->setObjectName("qurryLine_4");

        horizontalLayout_9->addWidget(qurryLine_4);

        qurryLine_5 = new QLineEdit(centralwidget);
        qurryLine_5->setObjectName("qurryLine_5");

        horizontalLayout_9->addWidget(qurryLine_5);


        gridLayout_4->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        delBtn = new QPushButton(centralwidget);
        delBtn->setObjectName("delBtn");

        horizontalLayout_11->addWidget(delBtn);

        checkBox_del = new QCheckBox(centralwidget);
        checkBox_del->setObjectName("checkBox_del");

        horizontalLayout_11->addWidget(checkBox_del);


        gridLayout_4->addLayout(horizontalLayout_11, 3, 0, 1, 1);


        horizontalLayout_7->addLayout(gridLayout_4);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_7);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(label_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        Button5 = new QPushButton(centralwidget);
        Button5->setObjectName("Button5");
        sizePolicy2.setHeightForWidth(Button5->sizePolicy().hasHeightForWidth());
        Button5->setSizePolicy(sizePolicy2);
        Button5->setFont(font);

        horizontalLayout_4->addWidget(Button5);

        Button6 = new QPushButton(centralwidget);
        Button6->setObjectName("Button6");
        sizePolicy2.setHeightForWidth(Button6->sizePolicy().hasHeightForWidth());
        Button6->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(12);
        font1.setHintingPreference(QFont::PreferDefaultHinting);
        Button6->setFont(font1);
        Button6->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout_4->addWidget(Button6);

        pictureShowBtn = new QPushButton(centralwidget);
        pictureShowBtn->setObjectName("pictureShowBtn");
        sizePolicy2.setHeightForWidth(pictureShowBtn->sizePolicy().hasHeightForWidth());
        pictureShowBtn->setSizePolicy(sizePolicy2);
        pictureShowBtn->setFont(font);

        horizontalLayout_4->addWidget(pictureShowBtn);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);
        label_2->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(label_2);

        horizontalLayout->setStretch(0, 20);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 10);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy6);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1030, 99));
        horizontalLayout_6 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        label->setFrameShape(QFrame::NoFrame);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_6->addWidget(label);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");

        verticalLayout->addLayout(horizontalLayout_5);

        verticalLayout->setStretch(0, 20);
        verticalLayout->setStretch(1, 2);
        verticalLayout->setStretch(2, 20);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        ui__MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ui__MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1054, 22));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        sizePolicy6.setHeightForWidth(menu_3->sizePolicy().hasHeightForWidth());
        menu_3->setSizePolicy(sizePolicy6);
        menu_4 = new QMenu(menu_3);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menu_3);
        menu_5->setObjectName("menu_5");
        menu_5->setGeometry(QRect(321, 173, 117, 111));
        menu_6 = new QMenu(menu_5);
        menu_6->setObjectName("menu_6");
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(menu_6->sizePolicy().hasHeightForWidth());
        menu_6->setSizePolicy(sizePolicy7);
        menu_7 = new QMenu(menu_5);
        menu_7->setObjectName("menu_7");
        menu_8 = new QMenu(menu_5);
        menu_8->setObjectName("menu_8");
        ui__MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ui__MainWindow);
        statusbar->setObjectName("statusbar");
        ui__MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(actionguanyu);
        menu_2->addAction(actionloadFile);
        menu_2->addAction(actiondataPicture);
        menu_3->addAction(menu_4->menuAction());
        menu_3->addAction(menu_5->menuAction());
        menu_4->addAction(actionAMOLED);
        menu_4->addAction(actionConsoleStyle);
        menu_4->addAction(actionManjaroMix);
        menu_4->addAction(actionMatrialDark);
        menu_4->addAction(actiondefault);
        menu_5->addAction(menu_6->menuAction());
        menu_5->addAction(menu_7->menuAction());
        menu_5->addAction(menu_8->menuAction());
        menu_6->addAction(actionpoint_2);
        menu_6->addAction(actionpointColor);
        menu_7->addAction(actiontriangle_2);
        menu_7->addAction(actiontriangleColor_2);
        menu_8->addAction(actionHV);
        menu_8->addAction(actionGND);

        retranslateUi(ui__MainWindow);

        QMetaObject::connectSlotsByName(ui__MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ui__MainWindow)
    {
        ui__MainWindow->setWindowTitle(QCoreApplication::translate("ui::MainWindow", "COMSOL Mini", nullptr));
        actionguanyu->setText(QCoreApplication::translate("ui::MainWindow", "\345\205\263\344\272\216", nullptr));
        actionopenTcp->setText(QCoreApplication::translate("ui::MainWindow", "\346\211\223\345\274\200\346\234\254\345\234\260\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        actioncloseTcp->setText(QCoreApplication::translate("ui::MainWindow", "\345\205\263\351\227\255\347\233\221\345\220\254\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        actionfile->setText(QCoreApplication::translate("ui::MainWindow", "\350\257\273\345\217\226\346\226\207\344\273\266", nullptr));
        actionloadFile->setText(QCoreApplication::translate("ui::MainWindow", "\350\257\273\345\217\226\346\226\207\344\273\266", nullptr));
        actiondataPicture->setText(QCoreApplication::translate("ui::MainWindow", "\346\225\260\346\215\256\345\217\257\350\247\206\345\214\226", nullptr));
        actionAMOLED->setText(QCoreApplication::translate("ui::MainWindow", "AMOLED", nullptr));
        actionConsoleStyle->setText(QCoreApplication::translate("ui::MainWindow", "ConsoleStyle", nullptr));
        actionManjaroMix->setText(QCoreApplication::translate("ui::MainWindow", "ManjaroMix", nullptr));
        actionMatrialDark->setText(QCoreApplication::translate("ui::MainWindow", "MatrialDark", nullptr));
        actionpoint_2->setText(QCoreApplication::translate("ui::MainWindow", "\347\273\230\345\210\266\346\225\243\347\202\271", nullptr));
        actiontriangleColor->setText(QCoreApplication::translate("ui::MainWindow", "\344\270\211\350\247\222\345\275\242\344\270\212\350\211\262", nullptr));
        actiontriangle_2->setText(QCoreApplication::translate("ui::MainWindow", "\347\273\230\345\210\266\344\270\211\350\247\222\345\275\242", nullptr));
        actiontriangle_2->setIconText(QCoreApplication::translate("ui::MainWindow", "\344\270\211\350\247\222\345\275\242\344\270\212\350\211\262", nullptr));
        actiontriangleColor_2->setText(QCoreApplication::translate("ui::MainWindow", "\344\270\211\350\247\222\345\275\242\344\270\212\350\211\262", nullptr));
        actionpointColor->setText(QCoreApplication::translate("ui::MainWindow", "\346\225\243\347\202\271\344\270\212\350\211\262", nullptr));
        actiondefault->setText(QCoreApplication::translate("ui::MainWindow", "default", nullptr));
        actionHV->setText(QCoreApplication::translate("ui::MainWindow", "\347\273\230\345\210\266\351\253\230\345\216\213\350\276\271\347\225\214", nullptr));
        actionGND->setText(QCoreApplication::translate("ui::MainWindow", "\347\273\230\345\210\266\344\275\216\345\216\213\350\276\271\347\225\214", nullptr));
        label_3->setText(QCoreApplication::translate("ui::MainWindow", "\345\212\237\350\203\275\345\214\272", nullptr));
        label_6->setText(QCoreApplication::translate("ui::MainWindow", "TCP\347\253\257\345\217\243\346\216\245\346\224\266\346\225\260\346\215\256", nullptr));
        Button1->setText(QCoreApplication::translate("ui::MainWindow", "\346\211\223\345\274\200\346\234\254\345\234\260\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        Button2->setText(QCoreApplication::translate("ui::MainWindow", "\345\205\263\351\227\255\347\233\221\345\220\254\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        label_4->setText(QCoreApplication::translate("ui::MainWindow", "\347\275\221\347\273\234\350\257\273\345\217\226\344\270\216\350\256\241\347\256\227", nullptr));
        Button3->setText(QCoreApplication::translate("ui::MainWindow", "\350\257\273\345\217\226\346\226\207\344\273\266", nullptr));
        Button4->setText(QCoreApplication::translate("ui::MainWindow", "\350\256\241\347\256\227\347\224\265\345\234\272\345\210\206\345\270\203", nullptr));
        label_7->setText(QCoreApplication::translate("ui::MainWindow", "\346\225\260\346\215\256\346\223\215\344\275\234", nullptr));
        label_8->setText(QCoreApplication::translate("ui::MainWindow", "\346\216\222\345\272\217\346\225\260\346\215\256", nullptr));
        ascBtn->setText(QCoreApplication::translate("ui::MainWindow", "\345\215\207\345\272\217\346\216\222\345\210\227", nullptr));
        descBtn->setText(QCoreApplication::translate("ui::MainWindow", "\351\231\215\345\272\217\346\216\222\345\210\227", nullptr));
        qurryBtn->setText(QCoreApplication::translate("ui::MainWindow", "\346\237\245\350\257\242", nullptr));
        label_10->setText(QCoreApplication::translate("ui::MainWindow", "\346\237\245\350\257\242\346\225\260\346\215\256", nullptr));
        label_9->setText(QCoreApplication::translate("ui::MainWindow", "\345\242\236\345\210\240\346\225\260\346\215\256", nullptr));
        delBtn->setText(QCoreApplication::translate("ui::MainWindow", "\346\267\273\345\212\240\346\225\260\346\215\256", nullptr));
        checkBox_del->setText(QCoreApplication::translate("ui::MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        label_5->setText(QCoreApplication::translate("ui::MainWindow", "\346\225\260\346\215\256\345\272\223\346\223\215\344\275\234", nullptr));
        Button5->setText(QCoreApplication::translate("ui::MainWindow", "\346\267\273\345\212\240\350\256\241\347\256\227\347\273\223\346\236\234", nullptr));
        Button6->setText(QCoreApplication::translate("ui::MainWindow", "\346\237\245\350\257\242\350\256\241\347\256\227\347\273\223\346\236\234", nullptr));
        pictureShowBtn->setText(QCoreApplication::translate("ui::MainWindow", "\346\225\260\346\215\256\345\217\257\350\247\206\345\214\226", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("ui::MainWindow", "\344\277\241\346\201\257\346\230\276\347\244\272", nullptr));
        menu->setTitle(QCoreApplication::translate("ui::MainWindow", "\345\274\200\345\247\213", nullptr));
        menu_2->setTitle(QCoreApplication::translate("ui::MainWindow", "\346\223\215\344\275\234", nullptr));
        menu_3->setTitle(QCoreApplication::translate("ui::MainWindow", "\351\200\211\351\241\271", nullptr));
        menu_4->setTitle(QCoreApplication::translate("ui::MainWindow", "\344\270\273\351\242\230", nullptr));
        menu_5->setTitle(QCoreApplication::translate("ui::MainWindow", "\345\217\257\350\247\206\345\214\226", nullptr));
        menu_6->setTitle(QCoreApplication::translate("ui::MainWindow", "\346\225\243\347\202\271", nullptr));
        menu_7->setTitle(QCoreApplication::translate("ui::MainWindow", "\344\270\211\350\247\222\345\275\242", nullptr));
        menu_8->setTitle(QCoreApplication::translate("ui::MainWindow", "\350\276\271\347\272\277", nullptr));
    } // retranslateUi

};

} // namespace ui

namespace ui {
namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui
} // namespace ui

#endif // UI_MAINWINDOW_H
