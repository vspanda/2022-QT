/**
 * @vspanda
 * cxsjCalendar MainWindow.h
 */

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

#include <QGroupBox>

#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QTextEdit>
#include <vector>
#include <algorithm>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFile>

#include <QTextDocument>
#include <QTextCursor>
#include <QTextFrame>
#include <QTextFrameFormat>

#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Date Selector
    void selectedDateChanged();

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
    void changeNL();
    QGroupBox *NL_box;
    QLabel *NL_label;
    QLineEdit *NL_data;

    // 日程管理
    void createEventManager();
    QGroupBox *events_box;

public:
    void setNL(QString n)
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
    void changeDNJR();
    QGroupBox *dnjr_box;
    QTextEdit *dnjr_data;

};
#endif // MAINWINDOW_H
