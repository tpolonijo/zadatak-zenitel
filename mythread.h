#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>
#include <unos.h>
#include <QObject>
#include <QThread>
#include <QtTest/QtTest>
#include <QTest>

class MyThread : public QThread
{
public:
    QByteArray ispis_buffera;
    Unos *mUnosPtr;
    MyThread();
    MyThread(Unos *mUnosPtr) {
        this->mUnosPtr = mUnosPtr;
    }

signals:

public slots:
    void run();
private slots:

};

#endif // MYTHREAD_H
