/********************************************************************************
** Form generated from reading UI file 'User.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

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

class Ui_User
{
public:
    QAction *searchAction;
    QAction *borrowAction;
    QAction *backAction;
    QAction *infoAction;
    QAction *aboutAction;
    QAction *returnAction;
    QAction *resetAction;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *User)
    {
        if (User->objectName().isEmpty())
            User->setObjectName(QString::fromUtf8("User"));
        User->resize(823, 494);
        searchAction = new QAction(User);
        searchAction->setObjectName(QString::fromUtf8("searchAction"));
        borrowAction = new QAction(User);
        borrowAction->setObjectName(QString::fromUtf8("borrowAction"));
        backAction = new QAction(User);
        backAction->setObjectName(QString::fromUtf8("backAction"));
        infoAction = new QAction(User);
        infoAction->setObjectName(QString::fromUtf8("infoAction"));
        aboutAction = new QAction(User);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        returnAction = new QAction(User);
        returnAction->setObjectName(QString::fromUtf8("returnAction"));
        resetAction = new QAction(User);
        resetAction->setObjectName(QString::fromUtf8("resetAction"));
        centralWidget = new QWidget(User);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        User->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(User);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 823, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        User->setMenuBar(menuBar);
        mainToolBar = new QToolBar(User);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        User->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(User);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        User->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(searchAction);
        menu->addAction(borrowAction);
        menu->addAction(backAction);
        menu->addAction(returnAction);
        menu->addAction(resetAction);
        menu_2->addAction(infoAction);
        menu_2->addAction(aboutAction);

        retranslateUi(User);

        QMetaObject::connectSlotsByName(User);
    } // setupUi

    void retranslateUi(QMainWindow *User)
    {
        User->setWindowTitle(QApplication::translate("User", "User", nullptr));
        searchAction->setText(QApplication::translate("User", "\346\237\245\350\257\242", nullptr));
        borrowAction->setText(QApplication::translate("User", "\345\200\237\344\271\246", nullptr));
        backAction->setText(QApplication::translate("User", "\350\277\230\344\271\246", nullptr));
        infoAction->setText(QApplication::translate("User", "\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
        aboutAction->setText(QApplication::translate("User", "\345\205\263\344\272\216", nullptr));
        returnAction->setText(QApplication::translate("User", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", nullptr));
        resetAction->setText(QApplication::translate("User", "\346\237\245\347\234\213\345\205\250\351\203\250", nullptr));
        menu->setTitle(QApplication::translate("User", "\345\233\276\344\271\246", nullptr));
        menu_2->setTitle(QApplication::translate("User", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User: public Ui_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
