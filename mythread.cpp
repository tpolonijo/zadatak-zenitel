#include "mythread.h"
#include <QtCore>
#include <QDebug>
#include <unos.h>

MyThread::MyThread()
{

}

void MyThread::run() {
    //QString file_name = ("/home/toni/qt_projects/input_files/a1.txt");
    QTextStream cin(stdin);
    QString file_name = cin.readLine();
    mUnosPtr->citanje_provjera(file_name);
}
