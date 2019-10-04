/********************************************************************************
** Form generated from reading UI file 'Admin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QAction *newAction;
    QAction *deleteAction;
    QAction *saveAction;
    QAction *searchAction;
    QAction *sortAction;
    QAction *statsAction;
    QAction *exportAction;
    QAction *infoAction;
    QAction *aboutAction;
    QAction *returnAction;
    QAction *resetAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *Book;
    QMenu *Op;
    QMenu *Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(807, 501);
        newAction = new QAction(Admin);
        newAction->setObjectName(QString::fromUtf8("newAction"));
        deleteAction = new QAction(Admin);
        deleteAction->setObjectName(QString::fromUtf8("deleteAction"));
        saveAction = new QAction(Admin);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        searchAction = new QAction(Admin);
        searchAction->setObjectName(QString::fromUtf8("searchAction"));
        sortAction = new QAction(Admin);
        sortAction->setObjectName(QString::fromUtf8("sortAction"));
        statsAction = new QAction(Admin);
        statsAction->setObjectName(QString::fromUtf8("statsAction"));
        exportAction = new QAction(Admin);
        exportAction->setObjectName(QString::fromUtf8("exportAction"));
        infoAction = new QAction(Admin);
        infoAction->setObjectName(QString::fromUtf8("infoAction"));
        aboutAction = new QAction(Admin);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        returnAction = new QAction(Admin);
        returnAction->setObjectName(QString::fromUtf8("returnAction"));
        resetAction = new QAction(Admin);
        resetAction->setObjectName(QString::fromUtf8("resetAction"));
        centralWidget = new QWidget(Admin);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        Admin->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Admin);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 807, 23));
        Book = new QMenu(menuBar);
        Book->setObjectName(QString::fromUtf8("Book"));
        Op = new QMenu(menuBar);
        Op->setObjectName(QString::fromUtf8("Op"));
        Help = new QMenu(menuBar);
        Help->setObjectName(QString::fromUtf8("Help"));
        Admin->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Admin);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Admin->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Admin);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Admin->setStatusBar(statusBar);

        menuBar->addAction(Book->menuAction());
        menuBar->addAction(Op->menuAction());
        menuBar->addAction(Help->menuAction());
        Book->addAction(newAction);
        Book->addAction(deleteAction);
        Book->addAction(saveAction);
        Book->addAction(returnAction);
        Op->addAction(searchAction);
        Op->addAction(sortAction);
        Op->addAction(statsAction);
        Op->addAction(exportAction);
        Op->addAction(resetAction);
        Help->addAction(infoAction);
        Help->addAction(aboutAction);

        retranslateUi(Admin);

        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QMainWindow *Admin)
    {
        Admin->setWindowTitle(QApplication::translate("Admin", "Admin", nullptr));
        newAction->setText(QApplication::translate("Admin", "\346\226\260\345\273\272", nullptr));
        deleteAction->setText(QApplication::translate("Admin", "\345\210\240\351\231\244", nullptr));
        saveAction->setText(QApplication::translate("Admin", "\344\277\235\345\255\230", nullptr));
        searchAction->setText(QApplication::translate("Admin", "\346\237\245\350\257\242", nullptr));
        sortAction->setText(QApplication::translate("Admin", "\346\216\222\345\272\217", nullptr));
        statsAction->setText(QApplication::translate("Admin", "\347\273\237\350\256\241", nullptr));
        exportAction->setText(QApplication::translate("Admin", "\345\257\274\345\207\272", nullptr));
        infoAction->setText(QApplication::translate("Admin", "\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
        aboutAction->setText(QApplication::translate("Admin", "\345\205\263\344\272\216", nullptr));
        returnAction->setText(QApplication::translate("Admin", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
        resetAction->setText(QApplication::translate("Admin", "\346\237\245\347\234\213\345\205\250\351\203\250", nullptr));
        Book->setTitle(QApplication::translate("Admin", "\345\233\276\344\271\246", nullptr));
        Op->setTitle(QApplication::translate("Admin", "\345\256\241\351\230\205", nullptr));
        Help->setTitle(QApplication::translate("Admin", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
