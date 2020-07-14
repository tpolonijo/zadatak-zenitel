#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QString>
#include <stdio.h>
#include <QTextStream>
#include <QThread>
#include <QtCore>
#include <QtDebug>
#include "mythread.h"
#include <unos.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream stream(stdout);

    //qInfo() << "Application Thread" << a.thread();
    Unos mUnos;
    Unos *ptr = &mUnos;
    MyThread mThread(ptr);
    mThread.start();
    mThread.wait();
    ptr->ispis();
    QTest::qExec(&mUnos);
    QTest::qExec(&mThread);
    return a.exec();
}
