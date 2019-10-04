#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LibrarySystem.h"
#include "BookList.h"

class LibrarySystem : public QMainWindow
{
    Q_OBJECT

public:
    LibrarySystem(QWidget *parent = Q_NULLPTR);
    void init();
    BookList* getBookList();
    void setBookList(BookList* bookList);
private:
    Ui::LibrarySystemClass ui;
    BookList* bookList;
protected:
  void closeEvent(QCloseEvent* event);
private slots:
  void showAbout();
  void showInfo();
  void on_btnAdmin_clicked();
  void on_btnUser_clicked();
  void reshow();
  
};
