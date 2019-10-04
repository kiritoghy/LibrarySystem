#pragma once

#include <QItemDelegate>

class ReadOnlyDelegate : public QItemDelegate
{
  Q_OBJECT

public:
  ReadOnlyDelegate(QWidget* parent = NULL) :QItemDelegate(parent) {}
  ~ReadOnlyDelegate() {

    }
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override //final
    {
      Q_UNUSED(parent)
      Q_UNUSED(option)
      Q_UNUSED(index)
      return NULL;
    }
};
