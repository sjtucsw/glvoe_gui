#include "valuewidget.h"
#include <iostream>

using namespace std;

ValueWidget::ValueWidget(QWidget *parent)
    : QFrame(parent)
{
    timer.start(50, this);

    filein.open("d:/sample.txt", ios::in);

    if (!filein.is_open()){
        cout << "open File Failed." << endl;
    } else {
        cout << "open File succeed." << endl;
    }
}

ValueWidget::~ValueWidget()
{
}

void ValueWidget::paintEvent(QPaintEvent* event)
{

    QPainter painter(this);
    QFont font("Times", 10, QFont::Light, 0);

    painter.setPen(QColor(0x00, 0, 0));
    painter.setFont(font);
    string oneline;
    oneline=glo_state.toStdString();
    stringstream lineHandler;
    string mode;
    lineHandler << oneline;
    for (int i=0; i<6; i++) lineHandler >> mode;
    painter.drawText(0 ,  16, width(), height(), Qt::AlignLeft | Qt::AlignTop, "Current State: "+QString::fromStdString(mode));
    lineHandler >> mode;
    painter.drawText(340, 160, width(), height(), Qt::AlignLeft | Qt::AlignTop, "Air pressure(Pa):");
    painter.drawText(380, 180, width(), height(), Qt::AlignLeft | Qt::AlignTop, QString::fromStdString(mode));
    lineHandler >> mode;
    painter.drawText(340, 200, width(), height(), Qt::AlignLeft | Qt::AlignTop, "Humidity(%):\n");
    painter.drawText(380, 220, width(), height(), Qt::AlignLeft | Qt::AlignTop, QString::fromStdString(mode));
    lineHandler >> mode;
    painter.drawText(340, 240, width(), height(), Qt::AlignLeft | Qt::AlignTop, "Temperature(C):\n");
    painter.drawText(380, 260, width(), height(), Qt::AlignLeft | Qt::AlignTop, QString::fromStdString(mode));
    font.setPixelSize(20);
    painter.drawText(0, 40, width(), height(), Qt::AlignLeft | Qt::AlignTop, glo_hint);
}

void ValueWidget::timerEvent(QTimerEvent *)
{
    filein.clear();
    filein.seekg(0,ios::beg);
    string oneline;
    stringstream lineHandler;
    string mode;
    getline(filein, oneline);
    cout << oneline << endl;
    lineHandler << oneline;
    lineHandler >> mode;
    if (mode.compare("roll:")==0) {
        glo_state=QString::fromStdString(oneline);
        getline(filein, oneline);
        glo_hint=QString::fromStdString(oneline);
        update();
    }
//    std::cout << "ValueWidget!" << std::endl;
}
