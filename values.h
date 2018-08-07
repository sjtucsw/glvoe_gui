#ifndef VALUES_H
#define VALUES_H


#include <QMainWindow>

namespace Ui {
class Values;
}

class Values : public QMainWindow
{
    Q_OBJECT

public:
    explicit Values(QWidget *parent = 0);
    ~Values();

private:
    Ui::Values *ui;
public slots:
    void timerUpdate(void);
};

#endif // VALUES_H
