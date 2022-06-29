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
//    createEventManager();
    createDNJR();


    // Sidebar Layout
    QWidget *sb = new QWidget();

    sidebar = new QVBoxLayout;
    sidebar->addWidget(dateSelect_box);
    sidebar->addWidget(NL_box);
//    sidebar->addWidget(events_box);
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


    NL_label = new QLabel(tr("农历日期： "));
    NL_data = new QLineEdit;
    NL_data->setReadOnly(true);
    NL_data->setText("测试中");
    changeNL();
    connect(calendar,&QCalendarWidget::selectionChanged,this,&MainWindow::changeNL);
    connect(dateSelect, &QDateEdit::dateChanged,this,&MainWindow::changeNL);



    // Have to Connect dateChange to this
    // Allow it to also change


    QHBoxLayout *nl_layout = new QHBoxLayout;
    nl_layout->addWidget(NL_label);
    nl_layout->addWidget(NL_data);
    nl_layout->setSizeConstraint(QLayout::SetMinimumSize);


    NL_box->setLayout(nl_layout);
    NL_box->setFixedHeight(40);

}

void MainWindow::changeNL(){
    QString path=":/new/prefix1/json_nl/";
    path+=QString::number(calendar->selectedDate().year());
    path+=".json";
    QFile file(path);
    if(!file.open(QFile::ReadOnly)){
       setNL("error");
    }

    QByteArray byteArr = file.readAll();
    QJsonParseError err;
    QJsonDocument Doc= QJsonDocument::fromJson(byteArr,&err);
    QString str;
    QJsonArray arr = Doc.array();
    for(int i=0;i<arr.count();i++){
        QJsonValue datevalue=arr.at(i);
        if(datevalue.type()==QJsonValue::Object){
            QJsonObject dateobj=datevalue.toObject();
            QJsonValue date_gl_val=dateobj.value("gregorian");
            if(date_gl_val.type()==QJsonValue::Object){
                QJsonObject date_gl_obj = date_gl_val.toObject();
                int month_from_json = date_gl_obj.value("month").toInt();
                int day_from_json = date_gl_obj.value("date").toInt();
                if(month_from_json==calendar->selectedDate().month()&&day_from_json==calendar->selectedDate().day()){
                    QJsonValue date_nl_val=dateobj.value("lunar");
                    if(date_nl_val.type()==QJsonValue::Object){
                        QJsonObject date_nl_obj=date_nl_val.toObject();
                        str+=date_nl_obj.value("year").toString();
                        str+=date_nl_obj.value("month").toString();
                        str+=date_nl_obj.value("date").toString();
                    }
                }
            }
        }
    }

    setNL(str);
    NL_data->setText(nlrq);
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
    dnjr_data = new QTextEdit;
    dnjr_data->setReadOnly(true);

    connect(calendar,&QCalendarWidget::selectionChanged,this,&MainWindow::changeDNJR);
    connect(dateSelect, &QDateEdit::dateChanged,this,&MainWindow::changeDNJR);

    QVBoxLayout *dnjr_layout = new QVBoxLayout;
    dnjr_layout->addWidget(dnjr_data);

    dnjr_box->setLayout(dnjr_layout);

}
void MainWindow::changeDNJR(){
    QString path=":/new/prefix1/dnjr _mini.json";
    QFile file(path);
    if(!file.open(QFile::ReadOnly)){
       setNL("error");
    }
    QTextDocument *document=dnjr_data->document();
    dnjr_data->setText("");
    QTextFrame *root_frame = document->rootFrame();
    QTextFrameFormat root_frame_format = root_frame->frameFormat();//创建框架格式

    root_frame_format.setBorder(5);//设置边界宽度
    root_frame->setFrameFormat(root_frame_format); //给框架使用格式
    QTextFrameFormat frame_format;
    frame_format.setBackground(Qt::darkRed);//设置背景色
    frame_format.setMargin(10);//设置边距
    frame_format.setPadding(5);//设置填充
    frame_format.setBorder(2);//设置边界宽度
    frame_format.setBorderStyle(
    QTextFrameFormat::BorderStyle_Solid);//设置边框样式
    frame_format.setPosition(QTextFrameFormat::FloatRight);//右侧
    frame_format.setWidth(QTextLength(
    QTextLength::PercentageLength, 40));//宽度设置
    QTextCursor cursor=dnjr_data->textCursor();



    QByteArray byteArr = file.readAll();
    QJsonParseError err;
    QJsonDocument Doc= QJsonDocument::fromJson(byteArr,&err);
    QJsonArray arr = Doc.array();
    for(int i=0;i<arr.count();i++){
        QJsonValue val=arr.at(i);

        if(val.type()==QJsonValue::Object){
            QJsonObject eve_obj=val.toObject();

            QString month_from_json =eve_obj.value("month").toString();
            QString day_from_json = eve_obj.value("day").toString();
            QString year_from_json = eve_obj.value("year").toString();
            int day_from_calendar = calendar->selectedDate().day();
            int month_from_calendar = calendar->selectedDate().month();
            int year_from_calendar = calendar->selectedDate().year();

            if(month_from_calendar==month_from_json.toInt()&&day_from_calendar==day_from_json.toInt()){

                QJsonValue eveValue = eve_obj.value("data");
                if(eveValue.type()==QJsonValue::String){
                    QString s=eveValue.toString();
                    QString str;
                    str+=year_from_json;
                    str+="年";
                    str+=month_from_json;
                    str+="月";
                    str+=day_from_json;
                    str+="日";
                    str+=s;
                    cursor.insertText(str);
                    cursor.insertText("\r\n");
                }
            }
        }
    }

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
