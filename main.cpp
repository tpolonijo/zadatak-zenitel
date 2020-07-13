#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QString>
#include <stdio.h>
#include <QTextStream>
#include <QThread>
#include "mythread.h"
#include <QtCore>
#include <QtDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream stream(stdout);

    qInfo() << "Application Thread" << a.thread();
    QString file_name = ("/home/toni/qt_projects/input_files/a1.txt");
    Unos mUnos;
    Unos *ptr = &mUnos;
    MyThread mThread(ptr);
    mThread.start();
    mThread.wait();
    ptr->ispis();
    return a.exec();
}
