/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QSpinBox *botcount;
    QSpinBox *playercount;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *name1;
    QLineEdit *name1edit;
    QLabel *name2;
    QLabel *name3;
    QLabel *name4;
    QLineEdit *name2edit;
    QLineEdit *name3edit;
    QLineEdit *name4edit;
    QLabel *welcome;
    QLabel *playerlabel;
    QLabel *botlabel;
    QLabel *notice;
    QPushButton *start;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartWindow->sizePolicy().hasHeightForWidth());
        StartWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName("centralwidget");
        botcount = new QSpinBox(centralwidget);
        botcount->setObjectName("botcount");
        botcount->setGeometry(QRect(450, 140, 80, 50));
        sizePolicy.setHeightForWidth(botcount->sizePolicy().hasHeightForWidth());
        botcount->setSizePolicy(sizePolicy);
        botcount->setMinimumSize(QSize(80, 50));
        botcount->setMaximumSize(QSize(80, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font.setPointSize(36);
        botcount->setFont(font);
        botcount->setAlignment(Qt::AlignCenter);
        botcount->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        botcount->setMaximum(3);
        playercount = new QSpinBox(centralwidget);
        playercount->setObjectName("playercount");
        playercount->setGeometry(QRect(230, 140, 80, 50));
        sizePolicy.setHeightForWidth(playercount->sizePolicy().hasHeightForWidth());
        playercount->setSizePolicy(sizePolicy);
        playercount->setMinimumSize(QSize(80, 50));
        playercount->setMaximumSize(QSize(80, 50));
        playercount->setFont(font);
        playercount->setAlignment(Qt::AlignCenter);
        playercount->setMinimum(1);
        playercount->setMaximum(4);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(220, 230, 321, 140));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        name1 = new QLabel(formLayoutWidget);
        name1->setObjectName("name1");
        sizePolicy.setHeightForWidth(name1->sizePolicy().hasHeightForWidth());
        name1->setSizePolicy(sizePolicy);
        name1->setMinimumSize(QSize(80, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font1.setPointSize(16);
        name1->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, name1);

        name1edit = new QLineEdit(formLayoutWidget);
        name1edit->setObjectName("name1edit");
        sizePolicy.setHeightForWidth(name1edit->sizePolicy().hasHeightForWidth());
        name1edit->setSizePolicy(sizePolicy);
        name1edit->setMinimumSize(QSize(200, 30));
        name1edit->setFont(font1);
        name1edit->setMaxLength(8);

        formLayout->setWidget(0, QFormLayout::FieldRole, name1edit);

        name2 = new QLabel(formLayoutWidget);
        name2->setObjectName("name2");
        sizePolicy.setHeightForWidth(name2->sizePolicy().hasHeightForWidth());
        name2->setSizePolicy(sizePolicy);
        name2->setMinimumSize(QSize(80, 30));
        name2->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, name2);

        name3 = new QLabel(formLayoutWidget);
        name3->setObjectName("name3");
        sizePolicy.setHeightForWidth(name3->sizePolicy().hasHeightForWidth());
        name3->setSizePolicy(sizePolicy);
        name3->setMinimumSize(QSize(80, 30));
        name3->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, name3);

        name4 = new QLabel(formLayoutWidget);
        name4->setObjectName("name4");
        sizePolicy.setHeightForWidth(name4->sizePolicy().hasHeightForWidth());
        name4->setSizePolicy(sizePolicy);
        name4->setMinimumSize(QSize(80, 30));
        name4->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, name4);

        name2edit = new QLineEdit(formLayoutWidget);
        name2edit->setObjectName("name2edit");
        sizePolicy.setHeightForWidth(name2edit->sizePolicy().hasHeightForWidth());
        name2edit->setSizePolicy(sizePolicy);
        name2edit->setMinimumSize(QSize(200, 30));
        name2edit->setFont(font1);
        name2edit->setMaxLength(8);

        formLayout->setWidget(1, QFormLayout::FieldRole, name2edit);

        name3edit = new QLineEdit(formLayoutWidget);
        name3edit->setObjectName("name3edit");
        sizePolicy.setHeightForWidth(name3edit->sizePolicy().hasHeightForWidth());
        name3edit->setSizePolicy(sizePolicy);
        name3edit->setMinimumSize(QSize(200, 30));
        name3edit->setFont(font1);
        name3edit->setMaxLength(8);

        formLayout->setWidget(2, QFormLayout::FieldRole, name3edit);

        name4edit = new QLineEdit(formLayoutWidget);
        name4edit->setObjectName("name4edit");
        sizePolicy.setHeightForWidth(name4edit->sizePolicy().hasHeightForWidth());
        name4edit->setSizePolicy(sizePolicy);
        name4edit->setMinimumSize(QSize(200, 30));
        name4edit->setFont(font1);
        name4edit->setMaxLength(8);

        formLayout->setWidget(3, QFormLayout::FieldRole, name4edit);

        welcome = new QLabel(centralwidget);
        welcome->setObjectName("welcome");
        welcome->setGeometry(QRect(160, 10, 441, 71));
        sizePolicy.setHeightForWidth(welcome->sizePolicy().hasHeightForWidth());
        welcome->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font2.setPointSize(30);
        welcome->setFont(font2);
        playerlabel = new QLabel(centralwidget);
        playerlabel->setObjectName("playerlabel");
        playerlabel->setGeometry(QRect(230, 90, 81, 31));
        sizePolicy.setHeightForWidth(playerlabel->sizePolicy().hasHeightForWidth());
        playerlabel->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font3.setPointSize(14);
        playerlabel->setFont(font3);
        playerlabel->setAlignment(Qt::AlignCenter);
        botlabel = new QLabel(centralwidget);
        botlabel->setObjectName("botlabel");
        botlabel->setGeometry(QRect(450, 90, 81, 31));
        sizePolicy.setHeightForWidth(botlabel->sizePolicy().hasHeightForWidth());
        botlabel->setSizePolicy(sizePolicy);
        botlabel->setFont(font3);
        botlabel->setAlignment(Qt::AlignCenter);
        notice = new QLabel(centralwidget);
        notice->setObjectName("notice");
        notice->setGeometry(QRect(20, 390, 751, 41));
        sizePolicy.setHeightForWidth(notice->sizePolicy().hasHeightForWidth());
        notice->setSizePolicy(sizePolicy);
        QFont font4;
        font4.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font4.setPointSize(12);
        notice->setFont(font4);
        notice->setAlignment(Qt::AlignCenter);
        start = new QPushButton(centralwidget);
        start->setObjectName("start");
        start->setGeometry(QRect(160, 440, 491, 101));
        sizePolicy.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font5.setPointSize(43);
        start->setFont(font5);
        StartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName("statusbar");
        StartWindow->setStatusBar(statusbar);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "\320\235\320\260\321\207\320\260\320\273\320\276", nullptr));
        name1->setText(QCoreApplication::translate("StartWindow", "\320\230\320\223\320\240\320\236\320\232 1", nullptr));
        name2->setText(QCoreApplication::translate("StartWindow", "\320\230\320\223\320\240\320\236\320\232 2", nullptr));
        name3->setText(QCoreApplication::translate("StartWindow", "\320\230\320\223\320\240\320\236\320\232 3", nullptr));
        name4->setText(QCoreApplication::translate("StartWindow", "\320\230\320\223\320\240\320\236\320\232 4", nullptr));
        welcome->setText(QCoreApplication::translate("StartWindow", "\320\224\320\236\320\221\320\240\320\236 \320\237\320\236\320\226\320\220\320\233\320\236\320\222\320\220\320\242\320\254!", nullptr));
        playerlabel->setText(QCoreApplication::translate("StartWindow", "\320\230\320\223\320\240\320\236\320\232\320\230", nullptr));
        botlabel->setText(QCoreApplication::translate("StartWindow", "\320\221\320\236\320\242\320\253", nullptr));
        notice->setText(QCoreApplication::translate("StartWindow", "\320\237\320\240\320\230\320\234\320\225\320\247\320\220\320\235\320\230\320\225: \320\234\320\230\320\235\320\230\320\234\320\220\320\233\320\254\320\235\320\236\320\225 \320\232\320\236\320\233\320\230\320\247\320\225\320\241\320\242\320\222\320\236 \320\230\320\223\320\240\320\236\320\232\320\236\320\222 - 1, \320\241\320\243\320\234\320\234\320\220 \320\243\320\247\320\220\320\241\320\242\320\235\320\230\320\232\320\236\320\222 \320\235\320\225 \320\221\320\236\320\233\320\254\320\250\320\225 4 ", nullptr));
        start->setText(QCoreApplication::translate("StartWindow", "\320\237\320\240\320\236\320\224\320\236\320\233\320\226\320\230\320\242\320\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
