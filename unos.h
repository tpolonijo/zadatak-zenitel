#ifndef UNOS_H
#define UNOS_H
#include <QString>
#include <QObject>
#include <QThread>

class Unos
{
public:
    QString ime;
    QByteArray ispis_buffera;
    Unos();
    void ispis();
    int citanje_provjera(QString file_name);
};


#endif // UNOS_H
