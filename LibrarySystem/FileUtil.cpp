#include "FileUtil.h"
#include <ctime>
using namespace std;
BookList* FileUtil::init()
{
  QFile file("storage.data");
  file.open(QIODevice::ReadOnly);
  BookList* bookList = new BookList();
  if (!file.exists()) return bookList;
  QDataStream in(&file);
  Book* book;
  int bookCount = 0;
  int allBorrowCount = 0;
  while (!in.atEnd()) {
    book = new Book();
    in >> *book;
    bookList->insert(book);
    bookCount += book->getStorageCount();
    allBorrowCount += book->getBorrowCount();
  }
  bookList->setAllBorrowCount(allBorrowCount);
  bookList->setBookCount(bookCount);
  file.close();
  return bookList;
}

bool FileUtil::save(BookList* bookList)
{
  QFile file("storage.data");
  file.open(QIODevice::WriteOnly);
  QDataStream out(&file);
  Book* book = bookList->getHead()->getNext();
  while (book) {
    out << (*book);
    book = book->getNext();
  }
  file.close();
  return true;
}

BookList* FileUtil::test()
{
  BookList* bookList = new BookList();
  Book* book;
  QString storageTime;
  time_t now = time(0);
  storageTime = ctime(&now);
  book = new Book(QString("book1"), QString("112233"), QString(u8"村上春树"), QString(u8"人民出版社"), QString("1991-02-13"), (storageTime), NULL, 5, 2);
  bookList->insert(book);
  storageTime = ctime(&now);
  book = new Book(QString("book2"), QString("112234"), QString(u8"列夫托尔斯泰"), QString(u8"人民出版社"), QString("1991-02-14"), (storageTime), NULL, 6, 1);
  bookList->insert(book);
  storageTime = ctime(&now);
  book = new Book(QString("book3"), QString("112235"), QString(u8"R&H"), QString(u8"人民出版社"), QString("1991-02-15"), (storageTime), NULL, 2, 2);
  bookList->insert(book);
  storageTime = ctime(&now);
  book = new Book(QString("book4"), QString("112236"), QString(u8"哈哈哈"), QString(u8"人民出版社"), QString("1991-02-16"), (storageTime), NULL, 3, 1);
  bookList->insert(book);
  storageTime = ctime(&now);
  book = new Book(QString("book5"), QString("112237"), QString(u8"噫噫噫"), QString(u8"人民出版社"), QString("1991-02-17"), (storageTime), NULL, 4, 2);
  bookList->insert(book);
  QFile file("storage.data");
  file.open(QIODevice::WriteOnly);
  QDataStream out(&file);
  book = bookList->getHead()->getNext();
  while (book) {
    out << (*book);
    book = book->getNext();
  }
  file.close();
  return bookList;
}
