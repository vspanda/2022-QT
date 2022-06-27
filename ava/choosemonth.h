#ifndef CHOOSEMONTH_H
#define CHOOSEMONTH_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class choosemonth; }
QT_END_NAMESPACE

class choosemonth : public QWidget
{
    Q_OBJECT

public:
    choosemonth(QWidget *parent = nullptr);
    ~choosemonth();

private:
    Ui::choosemonth *ui;
};
#endif // CHOOSEMONTH_H
