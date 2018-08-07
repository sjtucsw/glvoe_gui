#include <QDebug>


#include "valtime.h"
#include <QImage>


Main_Widget::Main_Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(1024,600);   //set interface size
    date_label = new QLabel(this);
    week_label = new QLabel(this);
    time_label = new QLabel(this);
    //设置时间显示的大小


    date_label->setParent(this);
    display_timer = new QTimer(this);


    connect(display_timer,SIGNAL(timeout()),this,SLOT(Update_Time()));


    display_timer->start(1000);      //after 1 S,restart Timer


    date_label->setGeometry(20,100,200,50);
    date_label->setStyleSheet("color:rgb(0, 0, 135);font-size:30px");
    time_label->setGeometry(20,150,200,50);
    time_label->setStyleSheet("color:rgb(0, 0, 135);font-size:50px");
    week_label->setGeometry(20,200,200,50);
    week_label->setStyleSheet("color:rgb(0, 0, 135);font-size:30px");


    Update_Time();
}

//类Widget   //只负责显示背景
class Widget : public QWidget
{
    Q_OBJECT


public:

    Widget(QWidget *parent = 0);
    ~Widget();


private:

    Main_Widget * myMain_Widget;

protected:
    void paintEvent(QPaintEvent *event);


};

#endif // WIDGET_H






//
void Main_Widget::Update_Time(void)
{
//    time_label->clear();
    QDateTime Current_time = QDateTime::currentDateTime();
//    QString String_time = Current_time.toString("yyyy-MM-dd hh:mm:ss dddd");
    date_string = Current_time.toString("yyyy-MM-dd");
    qDebug()<<"date = "<<date_string;
//    date_string = Current_time.toString("dd");
//    qDebug()<<"date2= "<<date_string.toInt();
    week_string = Current_time.toString("dddd");
//    time_string = Current_time.toString("hh:mm:ss");
    time_string = Current_time.toString("hh:mm");
    date_label->setText(date_string);
    week_label->setText(week_string);
    time_label->setText(time_string);
//    qDebug()<<time_label->text();


}


Main_Widget::~Main_Widget()
{
    delete date_label;
    delete week_label;
    delete time_label;
    delete display_timer;
}
