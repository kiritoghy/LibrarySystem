#include "NewBook.h"
#include "ui_NewBook.h"
#include "FileUtil.h"

NewBook::NewBook(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::NewBook();
    ui->setupUi(this);
}

NewBook::~NewBook()
{
    delete ui;
}
void NewBook::setBookList(BookList* bookList)
{
  this->bookList = bookList;
}
BookList* NewBook::getBookList()
{
  return this->bookList;
}
void NewBook::on_btnConfirm_clicked() {
  QString name = ui->nameEdit->text();
  QString ISBN = ui->ISBNEdit->text();
  QString author = ui->authorEdit->text();
  QString publishing = ui->pubEdit->text();
  QString publishTime = ui->pubtimeEdit->text();
  QString storageTime;
  time_t now = time(0);
  storageTime = ctime(&now);
  int storageCount = ui->storageCountEdit->text().toInt();
  int borrowCount = 0;

  Book* book = new Book(name, ISBN, author, publishing, publishTime, storageTime, NULL, storageCount, borrowCount);
  bookList->insert(book);
  if (!FileUtil::save(bookList)) {
    QMessageBox::warning(this, QStringLiteral("´íÎó!"), QStringLiteral("ÐÂÔöÊ§°Ü£¡Çë¼ì²é£¡"),QMessageBox::Yes);
  }
  else {
    emit sendNewConfirmSignals(this->bookList);
    this->close();
  }
}
