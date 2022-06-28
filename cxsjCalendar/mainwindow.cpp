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
    createEventManager();
    createDNJR();


    // Sidebar Layout
    sidebar = new QVBoxLayout;
    sidebar->addLayout(dateSelect_layout);



    layout = new QGridLayout;
    layout->addWidget(calendar, 0, 0);
    layout->addLayout(sidebar, 0, 1);

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
    settingsMenu = menubar->addMenu(tr("&s设定"));
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
    dateSelect_layout = new QHBoxLayout;

    dateSelect = new QDateEdit(calendar->selectedDate());
    dateSelect->setDateRange(
                calendar->minimumDate(),
                calendar->maximumDate());
    dateSelect->setDisplayFormat("dd MMM yyyy");



    dateSelect_label = new QLabel(tr("日期： "));


    dateSelect_layout->addWidget(dateSelect_label);
    dateSelect_layout->addWidget(dateSelect);

    connect(dateSelect, &QDateEdit::dateChanged,
            calendar, &QCalendarWidget::setSelectedDate);
}

void MainWindow::createEventManager()
{

}

void MainWindow::createDNJR()
{

}

MainWindow::~MainWindow()
{
    // Menu
    delete settingsMenu;
    delete menubar;

    // DNJR
    delete dnjr_layout;
    delete dnjr_title;

    // Date Selector
    delete dateSelect_layout;
    delete dateSelect;
    delete dateSelect_label;

    // Events
    delete events_layout;
    delete events_title;

    // Calendar
    delete layout;
    delete calendar;
    delete sidebar;

}

