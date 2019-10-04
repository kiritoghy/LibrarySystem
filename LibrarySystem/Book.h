#pragma once
#include<string>
#include <qDebug>
#include <QDataStream> 
using namespace std;
class Book {
private:
  QString name;
  QString ISBN;
  QString author;
  QString publishing;
  QString publishTime;
  QString storageTime;
  int storageCount;
  int borrowCount;
  Book* next;
public:
  Book();

  Book(QString name, QString ISBN, QString author, QString publishing, QString publishTime, QString storageTime, Book* next, int storageCount, int borrowCount);
  ~Book();
  QString getName();
  QString getISBN();
  QString getAuthor();
  QString getPublishing();
  QString getPublishTime();
  QString getstorageTime();
  int getStorageCount();
  int getBorrowCount();
  Book* getNext();

  void setName(QString name);
  void setISBN(QString ISBN);
  void setAuthor(QString author);
  void setpublishing(QString publishing);
  void setpublishTime(QString publishTime);
  void setStorageTime(QString storageTime);
  void setStorageCount(int storageCount);
  void setBorrowCount(int borrowCount);
  void setNext(Book* next);
  QString toString();

  friend QDataStream& operator<<(QDataStream&, const Book&);
  friend QDataStream& operator>>(QDataStream&, Book&);

};

