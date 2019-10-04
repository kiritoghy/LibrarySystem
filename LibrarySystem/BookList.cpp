#include "BookList.h"
#include <qDebug>

BookList::BookList()
{
  head = new Book();
  this->bookCount = 0;
  this->allBorrowCount = 0;
}

int BookList::getBookCount()
{
  return this -> bookCount;
}

int BookList::getAllBorrowCount()
{
  return this->allBorrowCount;
}

void BookList::setAllBorrowCount(int allBorrowCount)
{
  this->allBorrowCount = allBorrowCount;
}

void BookList::setBookCount(int bookCount)
{
  this->bookCount = bookCount;
}

void BookList::setHead(Book* book)
{
  this->head = book;
}

Book* BookList::getHead()
{
  return this->head;
}

void BookList::insert(Book* newBook)
{
  this->allBorrowCount += newBook->getBorrowCount();
  this->bookCount += newBook->getStorageCount();
  Book* head = this->head;
  while (head->getNext()) {
    head = head->getNext();
  }
  head->setNext(newBook);
}

void BookList::show()
{
  Book* head = this->head->getNext();
  while (head) {
    qDebug() << head->toString() << endl;
    head = head->getNext();
  }
}

void BookList::deleteBook(QString ISBN)
{
  Book* pre, * q;
  pre = head;
  while (pre && pre -> getNext() != NULL) {
    if (ISBN != pre->getNext()->getISBN()) {
      pre = pre->getNext();
      continue;
    }
    else {
      q = pre->getNext();
      pre->setNext(q->getNext());
      this->allBorrowCount -= q->getBorrowCount();
      this->bookCount -= q->getStorageCount();
      delete q;
      break;
    }
  }
}

void BookList::sort()
{
  head->setNext(mergeSort(head->getNext()));
}

void BookList::borrow(QString ISBN)
{
  Book* book = this->head;
  while (book) {
    if (book->getISBN() == ISBN) {
      book->setBorrowCount(book->getBorrowCount() + 1);
      allBorrowCount++;
    }
    book = book->getNext();
  }
}

void BookList::back(QString ISBN)
{
  Book* book = this->head;
  while (book) {
    if (book->getISBN() == ISBN) {
      book->setBorrowCount(book->getBorrowCount() - 1);
      allBorrowCount++;
    }
    book = book->getNext();
  }
}

Book* BookList::mergeSort(Book* head)
{
  if (head == NULL || head->getNext() == NULL)
    return head;
  Book* mid = getMid(head);
  Book* left = mergeSort(head);
  Book* right = mergeSort(mid);
  return merge(left, right);
}

Book* BookList::merge(Book* left, Book* right)
{
  if (left == NULL)return right;
  if (right == NULL)return left;
  Book* tmp = new Book();
  Book* pre = tmp;
  while (left != NULL && right != NULL) {
    if (left->getName().compare(right->getName()) <= 0) {
      pre->setNext(left);
      left = left->getNext();
    }
    else {
      pre->setNext(right);
      right = right->getNext();
    }
    pre = pre->getNext();
  }
  if (left != NULL)
    pre->setNext(left);
  if (right != NULL)
    pre->setNext(right);
  Book* res = tmp->getNext();
  delete tmp;
  return res;
}

Book* BookList::getMid(Book* head)
{
  if (head == NULL || head->getNext() == NULL)return head;
  Book* left = head;
  Book* right = head;
  Book* pre = head;
  while (right->getNext() != NULL && right->getNext()->getNext() != NULL) {
    pre = left;
    left = left->getNext();
    right = right->getNext()->getNext();
  }
  if (right->getNext() != NULL) {
    pre = left;
    left = left->getNext();
  }
  pre->setNext(NULL);
  return left;
}


