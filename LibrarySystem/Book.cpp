#include "Book.h"


void Book::setNext(Book* next)
{
  this->next = next;
}

QString Book::toString()
{
  return "name = " + this->name
    + "  ISBN = " + this->ISBN
    + "  author = " + this->author
    + "  publishing = " + this->publishing
    + "  publishTime = " + this->publishTime
    + "  storageTime = " + this->storageTime
    + "  storageCount = " + this->storageCount
    + "  borrowCount = " + this->borrowCount;
}


Book::Book()
{
  this->name = "";
  this->ISBN = "";
  this->author = "";
  this->publishing = "";
  this->publishTime = "";
  this->storageTime = "";
  this->next = NULL;
  this->storageCount = 0;
  this->borrowCount = 0;
}

Book::Book(QString name, QString ISBN, QString author, QString publishing, QString publishTime, QString storageTime, Book* next, int storageCount, int borrowCount)
{
  this->name = name;
  this->ISBN = ISBN;
  this->author = author;
  this->publishing = publishing;
  this->publishTime = publishTime;
  this->storageTime = storageTime;
  this->next = next;
  this->storageCount = storageCount;
  this->borrowCount = borrowCount;
}

Book::~Book()
{
}

QString Book::getName()
{
  return this->name;
}

QString Book::getISBN()
{
  return this->ISBN;
}

QString Book::getAuthor()
{
  return this->author;
}

QString Book::getPublishing()
{
  return this->publishing;
}

QString Book::getPublishTime()
{
  return this->publishTime;
}

QString Book::getstorageTime()
{
  return this->storageTime;
}

int Book::getStorageCount()
{
  return this->storageCount;
}

int Book::getBorrowCount()
{
  return this->borrowCount;
}

Book* Book::getNext()
{
  return this->next;
}

void Book::setName(QString name)
{
  this->name = name;
}

void Book::setISBN(QString ISBN)
{
  this->ISBN = ISBN;
}

void Book::setAuthor(QString author)
{
  this->author = author;
}

void Book::setpublishing(QString publishing)
{
  this->publishing = publishing;
}

void Book::setpublishTime(QString publishTime)
{
  this->publishTime = publishTime;
}

void Book::setStorageTime(QString storageTime)
{
  this->storageTime = storageTime;
}

void Book::setStorageCount(int storageCount)
{
  this->storageCount = storageCount;
}

void Book::setBorrowCount(int borrowCount)
{
  this->borrowCount = borrowCount;
}

QDataStream& operator<<(QDataStream& out, const Book& book)
{
  out << book.name << book.ISBN << book.author << book.publishing << book.publishTime << book.storageTime << book.storageCount << book.borrowCount;
  return out;
}

QDataStream& operator>>(QDataStream& in, Book& book)
{
  in >> book.name >> book.ISBN >> book.author >> book.publishing >> book.publishTime >> book.storageTime >> book.storageCount >> book.borrowCount;
  return in;
}
