#pragma once

#include <QMainWindow>
#include <qstandarditemmodel.h>
#include "ui_Admin.h"
#include "BookList.h"
#include "FileUtil.h"
#include "NewBook.h"
#include "Search.h"

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    Admin(QWidget *parent = Q_NULLPTR);
    ~Admin();
    void setBookList(BookList* bookList);
    BookList* getBookList();
    void init();
    void fresh(BookList* list);
    void setTmp(BookList* tmp);
protected:
  void closeEvent(QCloseEvent* event);
private:
    Ui::Admin ui;
    BookList* bookList;
    BookList* tmp;
    QStandardItemModel* model;
    bool ischanged;
    bool isSearching;
private slots:
  void on_returnAction_triggered();
  void on_newAction_triggered();
  void on_saveAction_triggered();
  void disp(BookList* list);
  void changed(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles = QVector<int>());
  void on_deleteAction_triggered();
  void on_searchAction_triggered();
  void on_resetAction_triggered();
  void on_statsAction_triggered();
  void on_sortAction_triggered();
  void on_exportAction_triggered();
  void showAbout();
  void showInfo();
signals:
  void sendAdminReturnSignals();
};
