#include "Values.h"
#include <QTimer>
#include <qdatetime.h>

Values::Values(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Values)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);
}

Values::~Values()
{
    delete ui;
}

void Values::timerUpdate(void)
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label->setText(str);
}
