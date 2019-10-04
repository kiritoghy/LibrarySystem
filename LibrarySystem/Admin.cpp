#include "Admin.h"
#include <QCloseEvent>
#include <qfiledialog.h>
#include "ReadOnlyDelegate.h"
#include <ActiveQt/QAxObject>

Admin::Admin(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    model = new QStandardItemModel(this);
    ischanged = false;
}

Admin::~Admin()
{
}

void Admin::setBookList(BookList* bookList)
{
  this->bookList = bookList;
}

BookList* Admin::getBookList()
{
  return this->bookList;
}

void Admin::init()
{
  connect(ui.aboutAction, SIGNAL(triggered(bool)), this, SLOT(showAbout()));
  connect(ui.infoAction, SIGNAL(triggered(bool)), this, SLOT(showInfo()));
}

void Admin::fresh(BookList* list)
{
  disp(list);
}

void Admin::setTmp(BookList* tmp)
{
  this->tmp = tmp;
}

void Admin::closeEvent(QCloseEvent* event)
{
  if (ischanged) {
    int ok = QMessageBox::warning(this, QStringLiteral("警告!"), QStringLiteral("还有未保存的数据，是否退出"), QMessageBox::Yes, QMessageBox::Discard, QMessageBox::Cancel);
    if (ok == QMessageBox::Yes) {
      emit ui.saveAction->triggered(true);
      event->accept();
    }
    else if (ok == QMessageBox::Discard) event->accept();
    else event->ignore();
  }
}

void Admin::disp(BookList* list)
{
  //ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
  tmp = list;
  model->clear();
  model->setColumnCount(8);
  model->setHeaderData(0, Qt::Horizontal, u8"书名");
  model->setHeaderData(1, Qt::Horizontal, u8"ISBN");
  model->setHeaderData(2, Qt::Horizontal, u8"作者");
  model->setHeaderData(3, Qt::Horizontal, u8"出版社");
  model->setHeaderData(4, Qt::Horizontal, u8"出版时间");
  model->setHeaderData(5, Qt::Horizontal, u8"入库时间");
  model->setHeaderData(6, Qt::Horizontal, u8"库存量");
  model->setHeaderData(7, Qt::Horizontal, u8"借阅量");
  ReadOnlyDelegate *readOnlyDelegate = new ReadOnlyDelegate();
  ui.tableView->setItemDelegateForColumn(5, readOnlyDelegate);
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
  connect(model, SIGNAL(dataChanged(QModelIndex, QModelIndex, QVector<int>)), this, SLOT(changed(QModelIndex, QModelIndex, QVector<int>)));
  ui.tableView->setModel(model);
  qDebug() << ui.tableView->model()->rowCount();
}

void Admin::changed(const QModelIndex& topLeft, const QModelIndex& bottomRight, const QVector<int>& roles)
{
  ischanged = true;
}

void Admin::on_searchAction_triggered()
{
  Search *search = new Search();
  connect(search, SIGNAL(sendSearchSignals(BookList*)), this, SLOT(disp(BookList*)));
  search->setBookList(this->bookList);
  search->show();
}

void Admin::on_resetAction_triggered()
{
  tmp = bookList;
  disp(tmp);
}

void Admin::on_statsAction_triggered()
{
  //QMessageBox::information(NULL, QStringLiteral("testuser"), QStringLiteral("软件技术基础大作业\n自动化171\n田婷\n2017303010103"), QMessageBox::Yes);
  QMessageBox::information(NULL, QStringLiteral("统计"), u8"共【"+QString::number(bookList->getBookCount())+ u8"】本书\n借出【" + QString::number(bookList->getAllBorrowCount()) + u8"】本书", QMessageBox::Yes);
}

void Admin::on_sortAction_triggered()
{
  tmp->sort();
  disp(tmp);
}

void Admin::on_exportAction_triggered()
{
  QFileDialog* fileDialog = new QFileDialog(this);
  fileDialog->setWindowTitle(tr("Save As"));//设置文件保存对话框的标题
  fileDialog->setAcceptMode(QFileDialog::AcceptSave);//设置文件对话框为保存模式
  fileDialog->setFileMode(QFileDialog::AnyFile);//设置文件对话框弹出的时候显示任何文件，不论是文件夹还是文件
  fileDialog->setViewMode(QFileDialog::Detail);//文件以详细的形式显示，显示文件名，大小，创建日期等信息；
  fileDialog->setDirectory(".");
  fileDialog->setNameFilter(tr("xlsx (*.xlsx)"));
  if (fileDialog->exec() == QFileDialog::Accepted) {
    QString filename = fileDialog->selectedFiles()[0];
    if (!filename.isEmpty()) {
      QAxObject* excel = new QAxObject(this);
      //连接Excel控件
      excel->setControl("Excel.Application");
      //不显示窗体
      excel->dynamicCall("SetVisible (bool Visible)", "false");
      //不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
      excel->setProperty("DisplayAlerts", false);
      //获取工作簿集合
      QAxObject* workbooks = excel->querySubObject("WorkBooks");
      //新建一个工作簿
      workbooks->dynamicCall("Add");
      //获取当前工作簿
      QAxObject* workbook = excel->querySubObject("ActiveWorkBook");
      //获取工作表集合
      QAxObject* worksheets = workbook->querySubObject("Sheets");
      //获取工作表集合的工作表1，即sheet1
      QAxObject* worksheet = worksheets->querySubObject("Item(int)", 1);

      QAxObject* cellA, * cellB, * cellC, * cellD, * cellE, * cellF, * cellG, * cellH;
      //设置标题
      int cellrow = 1;
      //设置要操作的单元格，如A1
      QString A = "A" + QString::number(cellrow);
      QString B = "B" + QString::number(cellrow);
      QString C = "C" + QString::number(cellrow);
      QString D = "D" + QString::number(cellrow);
      QString E = "E" + QString::number(cellrow);
      QString F = "F" + QString::number(cellrow);
      QString G = "G" + QString::number(cellrow);
      QString H = "H" + QString::number(cellrow);
      //获取单元格
      cellA = worksheet->querySubObject("Range(QVariant, QVariant)", A);
      cellB = worksheet->querySubObject("Range(QVariant, QVariant)", B);
      cellC = worksheet->querySubObject("Range(QVariant, QVariant)", C);
      cellD = worksheet->querySubObject("Range(QVariant, QVariant)", D);
      cellE = worksheet->querySubObject("Range(QVariant, QVariant)", E);
      cellF = worksheet->querySubObject("Range(QVariant, QVariant)", F);
      cellG = worksheet->querySubObject("Range(QVariant, QVariant)", G);
      cellH = worksheet->querySubObject("Range(QVariant, QVariant)", H);
      //设置单元格的表头值
      cellA->dynamicCall("SetValue(const QVariant&)", QVariant(u8"书名"));
      cellB->dynamicCall("SetValue(const QVariant&)", QVariant(u8"ISBN"));
      cellC->dynamicCall("SetValue(const QVariant&)", QVariant(u8"作者"));
      cellD->dynamicCall("SetValue(const QVariant&)", QVariant(u8"出版社"));
      cellE->dynamicCall("SetValue(const QVariant&)", QVariant(u8"出版时间"));
      cellF->dynamicCall("SetValue(const QVariant&)", QVariant(u8"入库时间"));
      cellG->dynamicCall("SetValue(const QVariant&)", QVariant(u8"库存量"));
      cellH->dynamicCall("SetValue(const QVariant&)", QVariant(u8"借阅量"));
      cellrow++;
      int rows = ui.tableView->model()->rowCount();
      //设置表格数据
      for (int i = 0; i < rows; i++) {
        //设置要操作的单元格，如A1，A2，A3，A4
        QString A = "A" + QString::number(cellrow);
        QString B = "B" + QString::number(cellrow);
        QString C = "C" + QString::number(cellrow);
        QString D = "D" + QString::number(cellrow);
        QString E = "E" + QString::number(cellrow);
        QString F = "F" + QString::number(cellrow);
        QString G = "G" + QString::number(cellrow);
        QString H = "H" + QString::number(cellrow);
        //获取单元格
        cellA = worksheet->querySubObject("Range(QVariant, QVariant)", A);
        cellB = worksheet->querySubObject("Range(QVariant, QVariant)", B);
        cellC = worksheet->querySubObject("Range(QVariant, QVariant)", C);
        cellD = worksheet->querySubObject("Range(QVariant, QVariant)", D);
        cellE = worksheet->querySubObject("Range(QVariant, QVariant)", E);
        cellF = worksheet->querySubObject("Range(QVariant, QVariant)", F);
        cellG = worksheet->querySubObject("Range(QVariant, QVariant)", G);
        cellH = worksheet->querySubObject("Range(QVariant, QVariant)", H);
        //设置单元格的值
        cellA->dynamicCall("SetValue(const QVariant&)", QVariant(model->data(model->index(i, 0)).toString()));
        cellB->dynamicCall("SetValue(const QVariant&)", QVariant(model->data(model->index(i, 1)).toString()));
        cellC->dynamicCall("SetValue(const QVariant&)", QVariant(model->data(model->index(i, 2)).toString()));
        cellD->dynamicCall("SetValue(const QVariant&)", QVariant(model->data(model->index(i, 3)).toString()));
        cellE->dynamicCall("SetValue(const QVariant&)", QVariant(model->data(model->index(i, 4)).toString()));
        cellF->dynamicCall("SetValue(const QVariant&)", QVariant(model->data(model->index(i, 5)).toString()));
        cellG->dynamicCall("SetValue(const QVariant&)", QVariant(model->data(model->index(i, 6)).toString()));
        cellH->dynamicCall("SetValue(const QVariant&)", QVariant(model->data(model->index(i, 7)).toString()));
        cellrow++;
      }

      workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filename));//保存至filepath，注意一定要用QDir::toNativeSeparators将路径中的"/"转换为"\"，不然一定保存不了。
      workbook->dynamicCall("Close()");//关闭工作簿
      excel->dynamicCall("Quit()");//关闭excel
      delete excel;
      excel = NULL;
      QMessageBox::information(this, QStringLiteral("消息"), QStringLiteral("导出成功！"), QMessageBox::Yes);
    }
  }
}

void Admin::on_deleteAction_triggered()
{
  QItemSelectionModel* selections = ui.tableView->selectionModel();
  QModelIndexList selected = selections->selectedIndexes();
  QMap <int, int> rowMap;
  foreach(QModelIndex index, selected) {
    rowMap.insert(index.row(), 0);
  }
  QMapIterator<int, int> rowMapIterator(rowMap);
  rowMapIterator.toBack();
  while (rowMapIterator.hasPrevious())
  {
    rowMapIterator.previous();
    int rowToDel = rowMapIterator.key();
    QString ISBN = ui.tableView->model()->data(model->index(rowToDel, 1)).toString();
    bookList->deleteBook(ISBN);
    tmp->deleteBook(ISBN);
    ui.tableView->model()->removeRow(rowToDel);
  }
}



void Admin::on_saveAction_triggered()
{
  int totalRow = ui.tableView->model()->rowCount();
  Book* book = bookList->getHead()->getNext();
  int row = 0;
  while (book) {
    book->setName(model->data(model->index(row, 0)).toString());
    book->setISBN(model->data(model->index(row, 1)).toString());
    book->setAuthor(model->data(model->index(row, 2)).toString());
    book->setpublishing(model->data(model->index(row, 3)).toString());
    book->setpublishTime(model->data(model->index(row, 4)).toString());
    book->setStorageCount(model->data(model->index(row, 6)).toString().toInt());
    book->setBorrowCount(model->data(model->index(row, 7)).toString().toInt());
    row++;
    book = book->getNext();
  }
  if (!FileUtil::save(bookList)) {
    QMessageBox::warning(this, QStringLiteral("错误!"), QStringLiteral("保存失败！请检查！"), QMessageBox::Yes);
  }
  else {
    QMessageBox::information(NULL, QStringLiteral("Save"), QStringLiteral("保存成功"), QMessageBox::Yes);
    ischanged = false;
  }
}


void Admin::on_newAction_triggered()
{
  NewBook *NB = new NewBook();
  NB->setBookList(this->getBookList());
  connect(NB, SIGNAL(sendNewConfirmSignals(BookList*)), this, SLOT(disp(BookList*)));
  NB->show();
}

void Admin::on_returnAction_triggered() {
  emit sendAdminReturnSignals();
  this->close();
}

void Admin::showInfo()
{
  QMessageBox::information(NULL, QStringLiteral("使用说明"), QStringLiteral("点击[图书]进行增删查改\n点击[审阅]进行查询排序等操作"), QMessageBox::Yes);
}

void Admin::showAbout() {
  QMessageBox::information(NULL, QStringLiteral("关于"), QStringLiteral("软件技术基础大作业\n自动化171\n田婷\n2017303010103"), QMessageBox::Yes);
}