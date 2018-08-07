#include "mainwindow.h"
#include <QApplication>
#include <qpushbutton.h>
#include <qfont.h>

#include <QLabel>
#include <QSurfaceFormat>
#include "mainwidget.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QPushButton quit( "Quit", 0 );
//    quit.resize( 75, 30 );
//    quit.setFont( QFont( "Times", 18, QFont::Bold ) );

//    QObject::connect( &quit, SIGNAL(clicked()), &a, SLOT(quit()) );

//    quit.show();

//    ifstream filein;
//    filein.open("d:/sample.txt", ios::in);

//    if (!filein.is_open()){
//        cout << "open File Failed." << endl;
//    }
//    string oneline;
//    getline(filein, oneline);

    MainWindow mainWindow;

    mainWindow.show();

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

//#ifndef QT_NO_OPENGL
//    MainWidget widget;
//    widget.show();
//#else
//    QLabel note("OpenGL Support required");
//    note.show();
//#endif

    return a.exec();
}

