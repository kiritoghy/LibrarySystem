#pragma once

#include <QWidget>
#include "BookList.h"
namespace Ui { class Search; };

class Search : public QWidget
{
    Q_OBJECT

public:
    Search(QWidget *parent = Q_NULLPTR);
    ~Search();
    void setBookList(BookList* bookList);
    BookList* getBookList();

private:
    Ui::Search *ui;
    BookList* bookList;
private slots:
  void on_btnConfirm_clicked();
signals:
  void sendSearchSignals(BookList*);
};
