/********************************************************************************
** Form generated from reading UI file 'NewBook.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWBOOK_H
#define UI_NEWBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewBook
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QPushButton *btnConfirm;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ISBNEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *authorEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *pubEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *pubtimeEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *storageCountEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *NewBook)
    {
        if (NewBook->objectName().isEmpty())
            NewBook->setObjectName(QString::fromUtf8("NewBook"));
        NewBook->resize(400, 404);
        gridLayout = new QGridLayout(NewBook);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 26, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 6, 1, 1, 1);

        btnConfirm = new QPushButton(NewBook);
        btnConfirm->setObjectName(QString::fromUtf8("btnConfirm"));

        gridLayout->addWidget(btnConfirm, 5, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(NewBook);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(NewBook);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(NewBook);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ISBNEdit = new QLineEdit(NewBook);
        ISBNEdit->setObjectName(QString::fromUtf8("ISBNEdit"));

        horizontalLayout_2->addWidget(ISBNEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(NewBook);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        authorEdit = new QLineEdit(NewBook);
        authorEdit->setObjectName(QString::fromUtf8("authorEdit"));

        horizontalLayout_3->addWidget(authorEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(NewBook);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        pubEdit = new QLineEdit(NewBook);
        pubEdit->setObjectName(QString::fromUtf8("pubEdit"));

        horizontalLayout_4->addWidget(pubEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(NewBook);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        pubtimeEdit = new QLineEdit(NewBook);
        pubtimeEdit->setObjectName(QString::fromUtf8("pubtimeEdit"));

        horizontalLayout_5->addWidget(pubtimeEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(NewBook);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        storageCountEdit = new QLineEdit(NewBook);
        storageCountEdit->setObjectName(QString::fromUtf8("storageCountEdit"));

        horizontalLayout_6->addWidget(storageCountEdit);


        verticalLayout->addLayout(horizontalLayout_6);


        gridLayout->addLayout(verticalLayout, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(86, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(87, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(86, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 26, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(86, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        label_8 = new QLabel(NewBook);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font;
        font.setPointSize(12);
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 1, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(87, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 5, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(87, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 0, 1, 1);


        retranslateUi(NewBook);

        QMetaObject::connectSlotsByName(NewBook);
    } // setupUi

    void retranslateUi(QWidget *NewBook)
    {
        NewBook->setWindowTitle(QApplication::translate("NewBook", "NewBook", nullptr));
        btnConfirm->setText(QApplication::translate("NewBook", "\347\241\256\345\256\232", nullptr));
        label->setText(QApplication::translate("NewBook", "\344\271\246\345\220\215", nullptr));
        label_2->setText(QApplication::translate("NewBook", "ISBN", nullptr));
        label_3->setText(QApplication::translate("NewBook", "\344\275\234\350\200\205", nullptr));
        label_4->setText(QApplication::translate("NewBook", "\345\207\272\347\211\210\347\244\276", nullptr));
        label_5->setText(QApplication::translate("NewBook", "\345\207\272\347\211\210\346\227\266\351\227\264", nullptr));
        label_6->setText(QApplication::translate("NewBook", "\345\272\223\345\255\230\351\207\217", nullptr));
        label_8->setText(QApplication::translate("NewBook", "     \350\257\267\345\241\253\345\206\231\345\233\276\344\271\246\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewBook: public Ui_NewBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWBOOK_H
