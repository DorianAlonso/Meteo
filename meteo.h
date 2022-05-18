#ifndef METEO_H
#define METEO_H
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QtGui>
#include <QMessageBox>

class Meteo
{
public:
    Meteo(int i);
    QString get_meteo(QString cville);
    QNetworkAccessManager m;
    QString cville,ville,meteo,icon;
    double temp;

private:
    QUrl qurl;
    QByteArray get(QUrl url);
};

#endif // METEO_H
