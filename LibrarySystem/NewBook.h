#pragma once

#include <QWidget>
#include <qmessagebox.h>
#include "BookList.h"
namespace Ui { class NewBook; };

class NewBook : public QWidget
{
    Q_OBJECT

public:
    NewBook(QWidget *parent = Q_NULLPTR);
    ~NewBook();
    void setBookList(BookList* bookList);
    BookList* getBookList();
private:
    Ui::NewBook *ui;
    BookList* bookList;
    
private slots:
  void on_btnConfirm_clicked();
signals:
  void sendNewConfirmSignals(BookList *list);
};
