#include "unos.h"
#include <QBuffer>
#include <QTextStream>
#include <QFile>
#include <QRegularExpression>

Unos::Unos(QObject *parent) : QObject(parent)
{
    TestIspis = "09.07.2020 Louis-John Wood-Smith\n02.07.1994 Toni Polonijo\n11.08.2020 Zachery Jason Doe Keller\n31.10.2000 Dalton Patel\n17.08.1452 Nina Hebert\n12.04.3612 Rafferty Stout\n24.03.2015 Constance Clarke\n";
}

void Unos::setTestIspis(QByteArray test_ispis)
{
    TestIspis = test_ispis;
}

int Unos::citanje_provjera(QString file_name) {
    QTextStream stream(stdout);
    //stream << "Unos::citanje_provjera " << QThread::currentThread();
    QByteArray line;
    QBuffer buffer(&ispis_buffera);
    QRegularExpression re("^\\d\\d\\.\\d\\d\\.\\d\\d\\d\\d ((\\w+-\\w+ \\w+-\\w+)|(\\w+ \\w+ \\w+ \\w+)|([A-Z][a-z]+ [A-Z][a-z]+))$");
    QRegularExpressionMatch match;
    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return 0;
    }
    buffer.open(QBuffer::ReadWrite);
    buffer.seek(0);
    while (!file.atEnd()) {
        line = file.readLine();
        match = re.match(line, 0, QRegularExpression::NormalMatch);
        if (match.hasMatch()) {
            buffer.write(line);
        }
    }
    buffer.close();
    return 0;
}

void Unos::testIspis()
{
    QByteArray value = ispis_buffera;
    QCOMPARE(TestIspis, value);
}

void Unos::ispis() {
    QTextStream stream(stdout);
    //stream << "Unos::ispis " << QThread::currentThread();
    stream << ispis_buffera << Qt::endl;
    stream << Qt::endl;
}
