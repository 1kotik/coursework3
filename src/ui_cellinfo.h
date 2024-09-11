/********************************************************************************
** Form generated from reading UI file 'cellinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLINFO_H
#define UI_CELLINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CellInfo
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *costlabel;
    QLabel *cost;
    QLabel *rentlabel;
    QLabel *rent;
    QLabel *house1label;
    QLabel *house1;
    QLabel *house2label;
    QLabel *house2;
    QLabel *house3label;
    QLabel *house3;
    QLabel *house4label;
    QLabel *house4;
    QLabel *hotellabel;
    QLabel *hotel;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *mortgagelabel;
    QLabel *mortgage;
    QLabel *housecostlabel;
    QLabel *housecost;
    QLabel *name;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *buyButton;
    QPushButton *houseButton;
    QPushButton *mortgageButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ownerlabel;
    QLabel *owner;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *sellButton;
    QPushButton *sellhouseButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CellInfo)
    {
        if (CellInfo->objectName().isEmpty())
            CellInfo->setObjectName("CellInfo");
        CellInfo->resize(400, 475);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CellInfo->sizePolicy().hasHeightForWidth());
        CellInfo->setSizePolicy(sizePolicy);
        CellInfo->setMinimumSize(QSize(400, 475));
        CellInfo->setMaximumSize(QSize(400, 475));
        centralwidget = new QWidget(CellInfo);
        centralwidget->setObjectName("centralwidget");
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(70, 50, 261, 213));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        costlabel = new QLabel(formLayoutWidget);
        costlabel->setObjectName("costlabel");
        sizePolicy.setHeightForWidth(costlabel->sizePolicy().hasHeightForWidth());
        costlabel->setSizePolicy(sizePolicy);
        costlabel->setMinimumSize(QSize(150, 25));
        QFont font;
        font.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font.setPointSize(14);
        costlabel->setFont(font);
        costlabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, costlabel);

        cost = new QLabel(formLayoutWidget);
        cost->setObjectName("cost");
        sizePolicy.setHeightForWidth(cost->sizePolicy().hasHeightForWidth());
        cost->setSizePolicy(sizePolicy);
        cost->setMinimumSize(QSize(50, 25));
        cost->setMaximumSize(QSize(16777215, 50));
        cost->setFont(font);
        cost->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, cost);

        rentlabel = new QLabel(formLayoutWidget);
        rentlabel->setObjectName("rentlabel");
        sizePolicy.setHeightForWidth(rentlabel->sizePolicy().hasHeightForWidth());
        rentlabel->setSizePolicy(sizePolicy);
        rentlabel->setMinimumSize(QSize(150, 25));
        rentlabel->setFont(font);
        rentlabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, rentlabel);

        rent = new QLabel(formLayoutWidget);
        rent->setObjectName("rent");
        sizePolicy.setHeightForWidth(rent->sizePolicy().hasHeightForWidth());
        rent->setSizePolicy(sizePolicy);
        rent->setMinimumSize(QSize(100, 25));
        rent->setFont(font);
        rent->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, rent);

        house1label = new QLabel(formLayoutWidget);
        house1label->setObjectName("house1label");
        sizePolicy.setHeightForWidth(house1label->sizePolicy().hasHeightForWidth());
        house1label->setSizePolicy(sizePolicy);
        house1label->setMinimumSize(QSize(150, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font1.setPointSize(10);
        house1label->setFont(font1);
        house1label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, house1label);

        house1 = new QLabel(formLayoutWidget);
        house1->setObjectName("house1");
        sizePolicy.setHeightForWidth(house1->sizePolicy().hasHeightForWidth());
        house1->setSizePolicy(sizePolicy);
        house1->setMinimumSize(QSize(100, 25));
        house1->setFont(font);
        house1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, house1);

        house2label = new QLabel(formLayoutWidget);
        house2label->setObjectName("house2label");
        sizePolicy.setHeightForWidth(house2label->sizePolicy().hasHeightForWidth());
        house2label->setSizePolicy(sizePolicy);
        house2label->setMinimumSize(QSize(150, 25));
        house2label->setFont(font1);
        house2label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, house2label);

        house2 = new QLabel(formLayoutWidget);
        house2->setObjectName("house2");
        sizePolicy.setHeightForWidth(house2->sizePolicy().hasHeightForWidth());
        house2->setSizePolicy(sizePolicy);
        house2->setMinimumSize(QSize(100, 25));
        house2->setFont(font);
        house2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::FieldRole, house2);

        house3label = new QLabel(formLayoutWidget);
        house3label->setObjectName("house3label");
        sizePolicy.setHeightForWidth(house3label->sizePolicy().hasHeightForWidth());
        house3label->setSizePolicy(sizePolicy);
        house3label->setMinimumSize(QSize(150, 25));
        house3label->setFont(font1);
        house3label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, house3label);

        house3 = new QLabel(formLayoutWidget);
        house3->setObjectName("house3");
        sizePolicy.setHeightForWidth(house3->sizePolicy().hasHeightForWidth());
        house3->setSizePolicy(sizePolicy);
        house3->setMinimumSize(QSize(100, 25));
        house3->setFont(font);
        house3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, house3);

        house4label = new QLabel(formLayoutWidget);
        house4label->setObjectName("house4label");
        sizePolicy.setHeightForWidth(house4label->sizePolicy().hasHeightForWidth());
        house4label->setSizePolicy(sizePolicy);
        house4label->setMinimumSize(QSize(150, 25));
        house4label->setFont(font1);
        house4label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(5, QFormLayout::LabelRole, house4label);

        house4 = new QLabel(formLayoutWidget);
        house4->setObjectName("house4");
        sizePolicy.setHeightForWidth(house4->sizePolicy().hasHeightForWidth());
        house4->setSizePolicy(sizePolicy);
        house4->setMinimumSize(QSize(100, 25));
        house4->setFont(font);
        house4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(5, QFormLayout::FieldRole, house4);

        hotellabel = new QLabel(formLayoutWidget);
        hotellabel->setObjectName("hotellabel");
        sizePolicy.setHeightForWidth(hotellabel->sizePolicy().hasHeightForWidth());
        hotellabel->setSizePolicy(sizePolicy);
        hotellabel->setMinimumSize(QSize(150, 25));
        hotellabel->setFont(font1);
        hotellabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(6, QFormLayout::LabelRole, hotellabel);

        hotel = new QLabel(formLayoutWidget);
        hotel->setObjectName("hotel");
        sizePolicy.setHeightForWidth(hotel->sizePolicy().hasHeightForWidth());
        hotel->setSizePolicy(sizePolicy);
        hotel->setMinimumSize(QSize(100, 25));
        hotel->setFont(font);
        hotel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(6, QFormLayout::FieldRole, hotel);

        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(50, 290, 311, 61));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        mortgagelabel = new QLabel(formLayoutWidget_2);
        mortgagelabel->setObjectName("mortgagelabel");
        sizePolicy.setHeightForWidth(mortgagelabel->sizePolicy().hasHeightForWidth());
        mortgagelabel->setSizePolicy(sizePolicy);
        mortgagelabel->setMinimumSize(QSize(200, 25));
        mortgagelabel->setFont(font);
        mortgagelabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, mortgagelabel);

        mortgage = new QLabel(formLayoutWidget_2);
        mortgage->setObjectName("mortgage");
        sizePolicy.setHeightForWidth(mortgage->sizePolicy().hasHeightForWidth());
        mortgage->setSizePolicy(sizePolicy);
        mortgage->setMinimumSize(QSize(100, 25));
        mortgage->setFont(font);
        mortgage->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, mortgage);

        housecostlabel = new QLabel(formLayoutWidget_2);
        housecostlabel->setObjectName("housecostlabel");
        sizePolicy.setHeightForWidth(housecostlabel->sizePolicy().hasHeightForWidth());
        housecostlabel->setSizePolicy(sizePolicy);
        housecostlabel->setMinimumSize(QSize(200, 25));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font2.setPointSize(11);
        housecostlabel->setFont(font2);
        housecostlabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, housecostlabel);

        housecost = new QLabel(formLayoutWidget_2);
        housecost->setObjectName("housecost");
        sizePolicy.setHeightForWidth(housecost->sizePolicy().hasHeightForWidth());
        housecost->setSizePolicy(sizePolicy);
        housecost->setMinimumSize(QSize(100, 25));
        housecost->setFont(font);
        housecost->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, housecost);

        name = new QLabel(centralwidget);
        name->setObjectName("name");
        name->setGeometry(QRect(17, 10, 371, 25));
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        name->setMinimumSize(QSize(200, 25));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font3.setPointSize(15);
        name->setFont(font3);
        name->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 350, 321, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buyButton = new QPushButton(layoutWidget);
        buyButton->setObjectName("buyButton");
        buyButton->setMinimumSize(QSize(120, 0));
        buyButton->setMaximumSize(QSize(120, 30));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        buyButton->setFont(font4);

        horizontalLayout->addWidget(buyButton);

        houseButton = new QPushButton(layoutWidget);
        houseButton->setObjectName("houseButton");
        houseButton->setMaximumSize(QSize(76899, 30));
        houseButton->setFont(font4);

        horizontalLayout->addWidget(houseButton);

        mortgageButton = new QPushButton(layoutWidget);
        mortgageButton->setObjectName("mortgageButton");
        mortgageButton->setMaximumSize(QSize(16777215, 30));
        mortgageButton->setFont(font4);

        horizontalLayout->addWidget(mortgageButton);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(37, 260, 311, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ownerlabel = new QLabel(horizontalLayoutWidget);
        ownerlabel->setObjectName("ownerlabel");
        sizePolicy.setHeightForWidth(ownerlabel->sizePolicy().hasHeightForWidth());
        ownerlabel->setSizePolicy(sizePolicy);
        ownerlabel->setMinimumSize(QSize(100, 25));
        ownerlabel->setFont(font);
        ownerlabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(ownerlabel);

        owner = new QLabel(horizontalLayoutWidget);
        owner->setObjectName("owner");
        sizePolicy.setHeightForWidth(owner->sizePolicy().hasHeightForWidth());
        owner->setSizePolicy(sizePolicy);
        owner->setMinimumSize(QSize(150, 25));
        owner->setFont(font);
        owner->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(owner);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(40, 390, 321, 33));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sellButton = new QPushButton(horizontalLayoutWidget_2);
        sellButton->setObjectName("sellButton");
        QFont font5;
        font5.setFamilies({QString::fromUtf8("KabelCTT Medium")});
        font5.setPointSize(13);
        sellButton->setFont(font5);

        horizontalLayout_3->addWidget(sellButton);

        sellhouseButton = new QPushButton(horizontalLayoutWidget_2);
        sellhouseButton->setObjectName("sellhouseButton");
        sellhouseButton->setFont(font5);

        horizontalLayout_3->addWidget(sellhouseButton);

        CellInfo->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CellInfo);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 21));
        CellInfo->setMenuBar(menubar);
        statusbar = new QStatusBar(CellInfo);
        statusbar->setObjectName("statusbar");
        CellInfo->setStatusBar(statusbar);

        retranslateUi(CellInfo);

        QMetaObject::connectSlotsByName(CellInfo);
    } // setupUi

    void retranslateUi(QMainWindow *CellInfo)
    {
        CellInfo->setWindowTitle(QCoreApplication::translate("CellInfo", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217", nullptr));
        costlabel->setText(QCoreApplication::translate("CellInfo", "\320\241\320\242\320\236\320\230\320\234\320\236\320\241\320\242\320\254", nullptr));
        cost->setText(QCoreApplication::translate("CellInfo", "100$", nullptr));
        rentlabel->setText(QCoreApplication::translate("CellInfo", "\320\220\320\240\320\225\320\235\320\224\320\220", nullptr));
        rent->setText(QCoreApplication::translate("CellInfo", "100$", nullptr));
        house1label->setText(QCoreApplication::translate("CellInfo", "\320\241 \320\236\320\224\320\235\320\230\320\234 \320\224\320\236\320\234\320\236\320\234", nullptr));
        house1->setText(QCoreApplication::translate("CellInfo", "100$", nullptr));
        house2label->setText(QCoreApplication::translate("CellInfo", "\320\241 \320\224\320\222\320\243\320\234\320\257 \320\224\320\236\320\234\320\220\320\234\320\230", nullptr));
        house2->setText(QCoreApplication::translate("CellInfo", "100$", nullptr));
        house3label->setText(QCoreApplication::translate("CellInfo", "\320\241 \320\242\320\240\320\225\320\234\320\257 \320\224\320\236\320\234\320\220\320\234\320\230", nullptr));
        house3->setText(QCoreApplication::translate("CellInfo", "100$", nullptr));
        house4label->setText(QCoreApplication::translate("CellInfo", "\320\241 \320\247\320\225\320\242\320\253\320\240\320\254\320\234\320\257 \320\224\320\236\320\234\320\220\320\234\320\230", nullptr));
        house4->setText(QCoreApplication::translate("CellInfo", "100$", nullptr));
        hotellabel->setText(QCoreApplication::translate("CellInfo", "\320\241 \320\236\320\224\320\235\320\230\320\234 \320\236\320\242\320\225\320\233\320\225\320\234", nullptr));
        hotel->setText(QCoreApplication::translate("CellInfo", "100$", nullptr));
        mortgagelabel->setText(QCoreApplication::translate("CellInfo", "\320\241\320\242\320\236\320\230\320\234\320\236\320\241\320\242\320\254 \320\227\320\220\320\233\320\236\320\223\320\220", nullptr));
        mortgage->setText(QCoreApplication::translate("CellInfo", "100$", nullptr));
        housecostlabel->setText(QCoreApplication::translate("CellInfo", "\320\241\320\242\320\236\320\230\320\234\320\236\320\241\320\242\320\254 \320\236\320\224\320\235\320\236\320\223\320\236 \320\224\320\236\320\234\320\220", nullptr));
        housecost->setText(QCoreApplication::translate("CellInfo", "100$", nullptr));
        name->setText(QCoreApplication::translate("CellInfo", "\320\237\320\225\320\240\320\222\320\220\320\257 \320\237\320\220\320\240\320\232\320\236\320\222\320\220\320\257 \320\243\320\233.", nullptr));
        buyButton->setText(QCoreApplication::translate("CellInfo", "\320\232\320\243\320\237\320\230\320\242\320\254 \320\243\320\247\320\220\320\241\320\242\320\236\320\232", nullptr));
        houseButton->setText(QCoreApplication::translate("CellInfo", "\320\232\320\243\320\237\320\230\320\242\320\254 \320\224\320\236\320\234", nullptr));
        mortgageButton->setText(QCoreApplication::translate("CellInfo", "\320\227\320\220\320\233\320\236\320\226\320\230\320\242\320\254", nullptr));
        ownerlabel->setText(QCoreApplication::translate("CellInfo", "\320\222\320\233\320\220\320\224\320\225\320\233\320\225\320\246", nullptr));
        owner->setText(QString());
        sellButton->setText(QCoreApplication::translate("CellInfo", "\320\237\320\240\320\236\320\224\320\220\320\242\320\254 \320\243\320\247\320\220\320\241\320\242\320\236\320\232", nullptr));
        sellhouseButton->setText(QCoreApplication::translate("CellInfo", "\320\237\320\240\320\236\320\224\320\220\320\242\320\254 \320\224\320\236\320\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CellInfo: public Ui_CellInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLINFO_H
