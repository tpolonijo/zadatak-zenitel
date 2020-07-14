#ifndef UNOS_H
#define UNOS_H
#include <QString>
#include <QObject>
#include <QThread>
#include <QtTest/QtTest>
#include <QTest>


class Unos : public QObject
{
    Q_OBJECT
public:
    QString ime;
    QByteArray ispis_buffera;
    explicit Unos(QObject *parent = nullptr);
    void setTestIspis(QByteArray test_ispis);
signals:

public slots:
    void ispis();
    int citanje_provjera(QString file_name);
private slots:
    void testIspis();
private:
    QByteArray TestIspis;

};


#endif // UNOS_H
