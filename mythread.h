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
    Q_OBJECT
public:
    QByteArray ispis_buffera;
    Unos *mUnosPtr;
    MyThread();
    MyThread(Unos *mUnosPtr) {
        this->mUnosPtr = mUnosPtr;
    }
    //~MyThread();

signals:
    void done();

public slots:

private slots:

protected:
    void run();
};

#endif // MYTHREAD_H
