#include "LibrarySystem.h"
#include <qmessagebox.h>
#include "Admin.h"
#include "User.h"
LibrarySystem::LibrarySystem(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}
void LibrarySystem::showAbout() {
  QMessageBox::information(NULL, QStringLiteral("关于"), QStringLiteral("软件技术基础大作业\n自动化171\n田婷\n2017303010103"), QMessageBox::Yes);
}

void LibrarySystem::init()
{
  connect(ui.aboutAction, SIGNAL(triggered(bool)), this, SLOT(showAbout()));
  connect(ui.infoAction, SIGNAL(triggered(bool)), this, SLOT(showInfo()));
}

void LibrarySystem::closeEvent(QCloseEvent* event)
{
  //QMessageBox::information(NULL, QStringLiteral("使用说明"), QStringLiteral("点击管理员进入管理员界面\n点击用户进入用户界面"), QMessageBox::Yes);
}

void LibrarySystem::showInfo()
{
  QMessageBox::information(NULL, QStringLiteral("使用说明"), QStringLiteral("点击[管理员]进入管理员界面\n点击[用户]进入用户界面"), QMessageBox::Yes);
}

void LibrarySystem::on_btnAdmin_clicked()
{
  Admin* admin = new Admin();
  connect(admin, SIGNAL(sendAdminReturnSignals()), this, SLOT(reshow()));
  BookList* l = FileUtil::init();
  admin->init();
  admin->setBookList(l);
  admin->setTmp(l);
  admin->fresh(l);
  this->hide();
  admin->show();
}

void LibrarySystem::on_btnUser_clicked()
{
  User *user = new User();
  connect(user, SIGNAL(sendUserReturnSignals()), this, SLOT(reshow()));
  BookList* l = FileUtil::init();
  user->setBookList(l);
  user->setTmp(l);
  user->fresh(l);
  this->hide();
  user->show();
}

void LibrarySystem::reshow()
{
  this->show();
}

void LibrarySystem::setBookList(BookList* bookList)
{
  this->bookList = bookList;
}

BookList* LibrarySystem::getBookList()
{
  return this->bookList;
}
