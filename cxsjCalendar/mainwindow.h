/**
 * @vspanda
 * cxsjCalendar MainWindow.h
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QActionGroup>

#include <QWidget>
#include <QCalendarWidget>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QGroupBox>

#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>

#include <vector>
#include <algorithm>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Date Selector
    void selectedDateChanged();

    // Menu
    void setWERed();
    void setWEBlu();
    void setWEBlk();
    void setWEClr(QColor col);

    void setWDRed();
    void setWDBlu();
    void setWDBlk();
    void setWDClr(QColor col);

    void toggleGridMode();

private:

    // Menu
    void createMenu();
    QMenuBar *menubar;
    QMenu *settingsMenu;

    // Calendar
    void createCalendar();
    QCalendarWidget *calendar;
    QGridLayout *layout;
    QVBoxLayout *sidebar;


    // Date Selector
    void createDateSelector();

    QGroupBox *dateSelect_box;
    QDateEdit *dateSelect;
    QLabel *dateSelect_label;

    // 农历
    void createNL();

    QGroupBox *NL_box;
    QLabel *NL_label;
    QLineEdit *NL_data;

public:
    void setNL(QString&& n)
    {
        nlrq = n;
    }
    QString getNL() const { return nlrq; };
private:
    // 放农历日期
    QString nlrq;

    // 当年今日
private:
    void createDNJR();
    QGroupBox *dnjr_box;

};
#endif // MAINWINDOW_H
