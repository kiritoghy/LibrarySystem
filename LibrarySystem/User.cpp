#include "User.h"
#include "ui_User.h"

User::User(QWidget *parent)
    : QMainWindow(parent)
{
    ui = new Ui::User();
    ui->setupUi(this);
    model = new QStandardItemModel(this);
}

User::~User()
{
    delete ui;
}

void User::setBookList(BookList* bookList)
{
  this->bookList = bookList;
}

BookList* User::getBookList()
{
  return this->bookList;
}

void User::setTmp(BookList* tmp)
{
  this->tmp = tmp;
}

void User::fresh(BookList* list)
{
  tmp = bookList;
  disp(tmp);
}

void User::disp(BookList* list)
{
  tmp = list;
  model->clear();
  model->setColumnCount(8);
  model->setHeaderData(0, Qt::Horizontal, u8"����");
  model->setHeaderData(1, Qt::Horizontal, u8"ISBN");
  model->setHeaderData(2, Qt::Horizontal, u8"����");
  model->setHeaderData(3, Qt::Horizontal, u8"������");
  model->setHeaderData(4, Qt::Horizontal, u8"����ʱ��");
  model->setHeaderData(5, Qt::Horizontal, u8"���ʱ��");
  model->setHeaderData(6, Qt::Horizontal, u8"�����");
  model->setHeaderData(7, Qt::Horizontal, u8"������");
  ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate();
  ui->tableView->setItemDelegateForColumn(5, readOnlyDelegate);
  int c = 0;
  Book* book = list->getHead()->getNext();
  while (book) {
    model->setItem(c, 0, new QStandardItem(book->getName()));
    model->setItem(c, 1, new QStandardItem(book->getISBN()));
    model->setItem(c, 2, new QStandardItem(book->getAuthor()));
    model->setItem(c, 3, new QStandardItem(book->getPublishing()));
    model->setItem(c, 4, new QStandardItem(book->getPublishTime()));
    model->setItem(c, 5, new QStandardItem(book->getstorageTime()));
    model->setItem(c, 6, new QStandardItem(QString::number(book->getStorageCount())));
    model->setItem(c, 7, new QStandardItem(QString::number(book->getBorrowCount())));
    c++;
    book = book->getNext();
  }
  ui->tableView->setModel(model);
  qDebug() << ui->tableView->model()->rowCount();
}

void User::on_infoAction_triggered()
{
  QMessageBox::information(NULL, QStringLiteral("ʹ��˵��"), QStringLiteral("���[ͼ��]���в�ѯ���黹��Ȳ���"), QMessageBox::Yes);
}

void User::on_aboutAction_triggered()
{
  QMessageBox::information(NULL, QStringLiteral("����"), QStringLiteral("���������������ҵ\n�Զ���171\n����\n2017303010103"), QMessageBox::Yes);
}

void User::on_returnAction_triggered()
{
  emit sendUserReturnSignals();
  this->close();
}

void User::on_searchAction_triggered()
{
  Search* search = new Search();
  connect(search, SIGNAL(sendSearchSignals(BookList*)), this, SLOT(disp(BookList*)));
  search->setBookList(this->bookList);
  search->show();
}

void User::on_resetAction_triggered()
{
  tmp = bookList;
  disp(tmp);
}

void User::on_borrowAction_triggered()
{
  QItemSelectionModel* selections = ui->tableView->selectionModel();
  QModelIndexList selected = selections->selectedIndexes();
  QList<QString> success;
  QList<QString> fail;
  foreach(QModelIndex index, selected) {
    QString name = model->data(model->index(index.row(), 0)).toString();
    QString ISBN = model->data(model->index(index.row(), 1)).toString();
    int total = model->data(model->index(index.row(), 6)).toString().toInt();
    int borrow = model->data(model->index(index.row(), 7)).toString().toInt();
    if (borrow + 1 > total) {
      fail.append(name);
    }
    else {
      success.append(name);
      bookList->borrow(ISBN);
      if (bookList != tmp)tmp->borrow(ISBN);
    }
  }
  disp(tmp);
  FileUtil::save(bookList);
  QString info = "";
  if (success.size() > 0) {
    info += u8"����ɹ���\n";
    for (QString s : success) {
      info += u8"��" + s + u8"��";
    }
  }
  if (fail.size() > 0) {
    info += u8"\n����ʧ�ܣ�\n";
    for (QString s : fail) {
      info += u8"��" + s + u8"��";
    }
  }
  QMessageBox::information(NULL, QStringLiteral("����"), info, QMessageBox::Yes);
}

void User::on_backAction_triggered()
{
  QItemSelectionModel* selections = ui->tableView->selectionModel();
  QModelIndexList selected = selections->selectedIndexes();
  QList<QString> success;
  QList<QString> fail;
  foreach(QModelIndex index, selected) {
    QString name = model->data(model->index(index.row(), 0)).toString();
    QString ISBN = model->data(model->index(index.row(), 1)).toString();
    int total = model->data(model->index(index.row(), 6)).toString().toInt();
    int borrow = model->data(model->index(index.row(), 7)).toString().toInt();
    if (borrow <= 0) {
      fail.append(name);
    }
    else {
      success.append(name);
      bookList->back(ISBN);
      if (bookList != tmp)tmp->back(ISBN);
    }
  }
  disp(tmp);
  FileUtil::save(bookList);
  QString info = "";
  if (success.size() > 0) {
    info += u8"����ɹ���\n";
    for (QString s : success) {
      info += u8"��" + s + u8"��";
    }
  }
  if (fail.size() > 0) {
    info += u8"\n����ʧ�ܣ�\n";
    for (QString s : fail) {
      info += u8"��" + s + u8"��";
    }
  }
  QMessageBox::information(NULL, QStringLiteral("����"), info, QMessageBox::Yes);
}
