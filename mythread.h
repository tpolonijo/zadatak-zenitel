#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>
#include <unos.h>
#include <QObject>
#include <QThread>

class MyThread : public QThread
{
public:
    QString ime;
    QByteArray ispis_buffera;
    Unos *mUnosPtr;
    MyThread();
    MyThread(Unos *mUnosPtr) {
        this->mUnosPtr = mUnosPtr;
    }
    void run();
};

#endif // MYTHREAD_H
