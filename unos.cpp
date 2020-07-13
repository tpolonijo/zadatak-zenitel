#include "unos.h"
#include <QBuffer>
#include <QTextStream>
#include <QFile>
#include <QRegularExpression>

Unos::Unos()
{

}
int Unos::citanje_provjera(QString file_name) {
    QTextStream stream(stdout);
    stream << "Unos::citanje_provjera " << QThread::currentThread();
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
    //stream << ispis_buffera << Qt::endl;
    return 0;
}

void Unos::ispis() {
    QTextStream stream(stdout);
    stream << "Unos::ispis " << QThread::currentThread();
    stream << ispis_buffera << Qt::endl;
    stream << Qt::endl;
}
