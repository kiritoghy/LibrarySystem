#include "Search.h"
#include "ui_Search.h"

Search::Search(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::Search();
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}

void Search::setBookList(BookList* bookList)
{
  this->bookList = bookList;
}
BookList* Search::getBookList()
{
  return this->bookList;
}

void Search::on_btnConfirm_clicked()
{
  QString name = ui->nameEdit->text().length() == 0 ? NULL : ui->nameEdit->text();
  QString ISBN = ui->ISBNEdit->text().length() == 0 ? NULL : ui->ISBNEdit->text();
  QString author = ui->authorEdit->text().length() == 0 ? NULL : ui->authorEdit->text();
  QString publishing = ui->pubEdit->text().length() == 0 ? NULL : ui->pubEdit->text();

  BookList* list = new BookList();
  Book* book = bookList->getHead()->getNext();
  while (book) {
    bool isfind = true;
    if (name != NULL && name != book->getName())isfind = false;
    if (ISBN != NULL && ISBN != book->getISBN())isfind = false;
    if (author != NULL && author != book->getAuthor())isfind = false;
    if (publishing != NULL && publishing != book->getPublishing()) isfind = false;
    if (isfind) {
      Book* nb = new Book(book->getName(), book->getISBN(), book->getAuthor(), book->getPublishing(), book->getPublishTime(), book->getstorageTime(), NULL, book->getStorageCount(), book->getBorrowCount());
      list->insert(nb);
    }
    book = book->getNext();
  }
  emit sendSearchSignals(list);
  this->close();
}
