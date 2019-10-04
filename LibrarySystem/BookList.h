#pragma once
#include "Book.h"
class BookList
{
private:
  Book* head;
  int bookCount;
  int allBorrowCount;
public:
  BookList();
  int getBookCount();
  int getAllBorrowCount();
  void setAllBorrowCount(int allBorrowCount);
  void setBookCount(int bookCount);
  void setHead(Book* book);
  Book* getHead();
  void insert(Book* newBook);
  void show();
  void deleteBook(QString ISBN);
  void sort();
  void borrow(QString ISBN);
  void back(QString ISBN);
  Book* mergeSort(Book* head);
  Book* merge(Book* left, Book* right);
  Book* getMid(Book *head);
};

