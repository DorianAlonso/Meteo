#include "meteo.h"

Meteo::Meteo(int i)
{
    i+=i;
}



QByteArray Meteo::get(QUrl url)
{

    QNetworkRequest requete(url);
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setProtocol(QSsl::TlsV1_2);
    requete.setSslConfiguration(config);
    QNetworkReply *reply = m.get(requete);

    while (!reply->isFinished())
    {
        qApp->processEvents();
    }

    QByteArray read = reply->readAll();
    reply->close();
    reply->deleteLater();

    return read;

}
QString Meteo::get_meteo(QString cville){   // fonction
    QString SPN,icon;   //déclaration de variables intermediaires
    qurl = "http://api.openweathermap.org/data/2.5/weather?q="+cville+"&appid=932e3dfa3cff1b7714838f8c9430b99f&units=metric&lang=fr";   //on modifie l'url en foction de la ville choisie
    QUrl url = qurl;
    QJsonDocument documentJSON = QJsonDocument::fromJson(get(url)); //transformation en objet JSON
    QJsonObject objetJSON = documentJSON.object();  //extraction des données souhaitées
    QJsonArray jsonArray = objetJSON["weather"].toArray();
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        SPN.append(obj["description"].toString());
        icon.append(obj["icon"].toString());
    }
    QJsonValue temp1=objetJSON["main"];
    QJsonObject temp2= temp1.toObject();
    QJsonValue temp3 = temp2.value("temp");
    double temp = temp3.toDouble();

    this->meteo=SPN;    //on stocke le temps qu'il fait dans l'attribut "meteo"
    this->temp=temp;    //on stocke la température dans l'attribut "temp"
    this->icon=icon;    //on stocke l'id de l'icon dans l'attribut "icon"


    return 0;
}
