/**
 * @vspanda
 * cxsjCalendar MainWindow.cpp
 */

#include "mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    const int width(1280);
    const int height(720);
    setWindowTitle(tr("CXSJ Calendar"));
    setFixedSize(width, height);

    // Calling Creates
    createMenu();
    createCalendar();
    createDateSelector();
    createNL();
    createEventManager();
    createDNJR();


    // Sidebar Layout
    QWidget *sb = new QWidget();

    sidebar = new QVBoxLayout;
    sidebar->addWidget(dateSelect_box);
    sidebar->addWidget(NL_box);
    sidebar->addWidget(events_box);
    sidebar->addWidget(dnjr_box);



    sb->setLayout(sidebar);
    sb->setFixedWidth(width * .25);
    sb->setFixedHeight(height - menubar->height());


    layout = new QGridLayout;
    layout->addWidget(calendar, 0, 0);
    layout->addWidget(sb, 0, 1);

    layout->setRowMinimumHeight(0, height - menubar->height());
    layout->setColumnMinimumWidth(0, calendar->width());
    layout->setSizeConstraint(QLayout::SetFixedSize);


    QWidget *central = new QWidget(this);
    central->setLayout(layout);
    setCentralWidget(central);


    centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
}

void MainWindow::createMenu()
{
    menubar = menuBar();
    settingsMenu = menubar->addMenu(tr("&Settings"));



}

void MainWindow::createCalendar()
{
    // Calendar
    calendar = new QCalendarWidget;
    calendar->resize(width() * 0.75, height());
    calendar->setGridVisible(true);

    calendar->setDateEditEnabled(false);

}

void MainWindow::createDateSelector()
{
    // Date Selector


    dateSelect_box = new QGroupBox(tr("日期选择"));

    dateSelect = new QDateEdit(calendar->selectedDate());
    dateSelect->setDateRange(
                calendar->minimumDate(),
                calendar->maximumDate());
    dateSelect->setDisplayFormat("dd MMM yyyy");



    dateSelect_label = new QLabel(tr("日期： "));
    dateSelect_label->setBuddy(dateSelect);

    QGridLayout *dateSelect_layout = new QGridLayout;
    dateSelect_layout->addWidget(dateSelect_label, 0, 0);
    dateSelect_layout->addWidget(dateSelect, 0, 1);
    dateSelect_layout->setSizeConstraint(QLayout::SetMinimumSize);


    dateSelect_box->setLayout(dateSelect_layout);
    dateSelect_box->setFixedHeight(40);



    connect(dateSelect, &QDateEdit::dateChanged,
            calendar, &QCalendarWidget::setSelectedDate);
    connect(calendar, &QCalendarWidget::selectionChanged,
            this, &MainWindow::selectedDateChanged);
}

void MainWindow::selectedDateChanged()
{
    dateSelect->setDate(calendar->selectedDate());
}

void MainWindow::createNL()
{
    NL_box = new QGroupBox(tr("农历日期"));



    nlrq = tr("把农历日期放这儿");

    NL_label = new QLabel(tr("农历日期： "));

    NL_data = new QLineEdit;
    NL_data->setReadOnly(true);

    NL_data->setText(nlrq);


    // Have to Connect dateChange to this
    // Allow it to also change


    QHBoxLayout *nl_layout = new QHBoxLayout;
    nl_layout->addWidget(NL_label);
    nl_layout->addWidget(NL_data);
    nl_layout->setSizeConstraint(QLayout::SetMinimumSize);


    NL_box->setLayout(nl_layout);
    NL_box->setFixedHeight(40);

}

void MainWindow::createEventManager()
{
    events_box = new QGroupBox(tr("日程"));

    QVBoxLayout *event_layout = new QVBoxLayout;

    events_box->setLayout(event_layout);
    events_box->setFixedHeight(300);

}

void MainWindow::createDNJR()
{
    dnjr_box = new QGroupBox(tr("当年今日"));

    QVBoxLayout *dnjr_layout = new QVBoxLayout;


    dnjr_box->setLayout(dnjr_layout);

}

MainWindow::~MainWindow()
{
    // Menu
    delete menubar;
    delete settingsMenu;

    // Date Selector
    delete dateSelect_box;
    delete dateSelect;
    delete dateSelect_label;

    // NL
    delete NL_box;
    delete NL_label;
    delete NL_data;

    // DNJR
    delete dnjr_box;

    // Events
    delete events_box;

    // Calendar
    delete calendar;
    delete layout;
    delete sidebar;

}

