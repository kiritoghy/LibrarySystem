#pragma once

#include <QMainWindow>
#include <qstandarditemmodel.h>
#include "BookList.h"
#include "ReadOnlyDelegate.h"
#include "Search.h"
#include "FileUtil.h"
#include <qmessagebox.h>
namespace Ui { class User; };

class User : public QMainWindow
{
    Q_OBJECT

public:
    User(QWidget *parent = Q_NULLPTR);
    ~User();
    void setBookList(BookList* bookList);
    BookList* getBookList();
    void setTmp(BookList* tmp);
    void fresh(BookList* list);

private slots:
  void disp(BookList* list);
  void on_infoAction_triggered();
  void on_aboutAction_triggered();
  void on_returnAction_triggered();
  void on_searchAction_triggered();
  void on_resetAction_triggered();
  void on_borrowAction_triggered();
  void on_backAction_triggered();

private:
    Ui::User *ui;
    BookList* bookList;
    BookList* tmp;
    QStandardItemModel* model;
signals:
  void sendUserReturnSignals();
};
