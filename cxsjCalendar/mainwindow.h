#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMenuBar>
#include <QMenu>

#include <QWidget>
#include <QCalendarWidget>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QLabel>
#include <QDateEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Date Selector

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
    QHBoxLayout *dateSelect_layout;
    QDateEdit *dateSelect;
    QLabel *dateSelect_label;

    // 日程管理
    void createEventManager();
    QVBoxLayout *events_layout;
    QLabel *events_title;

    // 当年今日
    void createDNJR();
    QVBoxLayout *dnjr_layout;
    QLabel *dnjr_title;


};
#endif // MAINWINDOW_H
