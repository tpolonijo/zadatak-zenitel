#include <QCoreApplication>
#include <QTextStream>
#include <QtDebug>
#include "mythread.h"
#include <unos.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Application Thread" << a.thread();
    Unos mUnos;
    Unos *ptr = &mUnos;
    MyThread mThread(ptr);
    //QObject::connect(&mThread, SIGNAL(finished()), &a, SLOT(quit()));
    QObject::connect(&mThread, SIGNAL(done()), ptr, SLOT(ispis()));
    mThread.start();
    //mThread.wait();
    //ptr->ispis();
    //QTest::qExec(&mUnos);
    //QTest::qExec(&mThread);
    return a.exec();
}
