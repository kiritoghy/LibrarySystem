#include "LibrarySystem.h"
#include <QtWidgets/QApplication>
#include "FileUtil.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  LibrarySystem w;
  BookList* bookList;
  w.init();
  /*w.setBookList(FileUtil::init());
  w.getBookList()->show();*/
  w.show();
  return a.exec();
}
