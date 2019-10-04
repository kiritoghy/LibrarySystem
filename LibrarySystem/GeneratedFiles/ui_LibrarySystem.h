/********************************************************************************
** Form generated from reading UI file 'LibrarySystem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIBRARYSYSTEM_H
#define UI_LIBRARYSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibrarySystemClass
{
public:
    QAction *infoAction;
    QAction *aboutAction;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAdmin;
    QPushButton *btnUser;
    QMenuBar *menuBar;
    QMenu *helpMenu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LibrarySystemClass)
    {
        if (LibrarySystemClass->objectName().isEmpty())
            LibrarySystemClass->setObjectName(QString::fromUtf8("LibrarySystemClass"));
        LibrarySystemClass->resize(600, 400);
        QFont font;
        font.setPointSize(11);
        LibrarySystemClass->setFont(font);
        infoAction = new QAction(LibrarySystemClass);
        infoAction->setObjectName(QString::fromUtf8("infoAction"));
        aboutAction = new QAction(LibrarySystemClass);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        centralWidget = new QWidget(LibrarySystemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 50, 204, 33));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setIndent(-1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 110, 270, 16));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 180, 271, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnAdmin = new QPushButton(layoutWidget);
        btnAdmin->setObjectName(QString::fromUtf8("btnAdmin"));

        horizontalLayout->addWidget(btnAdmin);

        btnUser = new QPushButton(layoutWidget);
        btnUser->setObjectName(QString::fromUtf8("btnUser"));

        horizontalLayout->addWidget(btnUser);

        LibrarySystemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LibrarySystemClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        helpMenu = new QMenu(menuBar);
        helpMenu->setObjectName(QString::fromUtf8("helpMenu"));
        LibrarySystemClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(LibrarySystemClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LibrarySystemClass->setStatusBar(statusBar);

        menuBar->addAction(helpMenu->menuAction());
        helpMenu->addAction(infoAction);
        helpMenu->addAction(aboutAction);

        retranslateUi(LibrarySystemClass);

        QMetaObject::connectSlotsByName(LibrarySystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *LibrarySystemClass)
    {
        LibrarySystemClass->setWindowTitle(QApplication::translate("LibrarySystemClass", "LibrarySystem", nullptr));
        infoAction->setText(QApplication::translate("LibrarySystemClass", "\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
        aboutAction->setText(QApplication::translate("LibrarySystemClass", "\345\205\263\344\272\216", nullptr));
        label->setText(QApplication::translate("LibrarySystemClass", "\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label_2->setText(QApplication::translate("LibrarySystemClass", "\346\254\242\350\277\216\344\275\277\347\224\250\345\233\276\344\271\246\347\256\241\347\220\206\347\263\273\347\273\237\357\274\214\350\257\267\351\200\211\346\213\251\350\272\253\344\273\275\350\277\233\345\205\245", nullptr));
        btnAdmin->setText(QApplication::translate("LibrarySystemClass", "\347\256\241\347\220\206\345\221\230", nullptr));
        btnUser->setText(QApplication::translate("LibrarySystemClass", "\347\224\250\346\210\267", nullptr));
        helpMenu->setTitle(QApplication::translate("LibrarySystemClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LibrarySystemClass: public Ui_LibrarySystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIBRARYSYSTEM_H
