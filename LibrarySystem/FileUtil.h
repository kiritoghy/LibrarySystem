#pragma once
#include <QDataStream>
#include <QFile>
#include "BookList.h"
class FileUtil
{
public:
  static BookList* init();//启动初始化，读取存储文件
  static bool save(BookList* bookList);
  static BookList* test();
};

