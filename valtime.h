#ifndef VALTIME_H
#define VALTIME_H

#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QPalette>
#include <QPainter>
#include <QMessageBox>
#include <QLineEdit>
#include <QSignalMapper>
#include <QTextCodec>
#include <QComboBox>
#include <QTableWidget>
#include <QToolButton>

class ValTime : public QWidget
{
    Q_OBJECT


public:


   ValTime(QWidget *parent = 0);
   ~ValTime();
private:

    QString date_string;
    QString week_string;
    QString time_string;


    QLabel *date_label;
    QLabel *week_label;
    QLabel *time_label;
    //定时器
    QTimer * display_timer;


    QLabel *display_Image;
    QLabel *display_name;


private slots:
    void Update_Time(void);
};


#endif // VALTIME_H
