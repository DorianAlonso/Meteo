#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "meteo.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()        //si le boutton est pressé
{
    Meteo m1(0);
    m1.get_meteo(ui->choix->text());            //choix de la ville
    ui->meteo->setText(m1.meteo);               //affiche le temps : nuageux, ensoleillé; etc
    ui->temp->setValue(m1.temp);                //affiche la températures
    if (m1.icon=="01d"||m1.icon=="01n"){        //affiche les differents icon en fonction du temps
        ui->label_3->setPixmap(QPixmap(":images/01d@2x.png"));
    }
    if (m1.icon=="02d"||m1.icon=="02n"){
        ui->label_3->setPixmap(QPixmap(":images/02d@2x.png"));
    }
    if (m1.icon=="03d"||m1.icon=="03n"){
        ui->label_3->setPixmap(QPixmap(":images/03d@2x.png"));
    }
    if (m1.icon=="04d"||m1.icon=="04n"){
        ui->label_3->setPixmap(QPixmap(":images/04d@2x.png"));
    }
    if (m1.icon=="09d"||m1.icon=="09n"){
        ui->label_3->setPixmap(QPixmap(":images/09d@2x.png"));
    }
    if (m1.icon=="10d"||m1.icon=="10n"){
        ui->label_3->setPixmap(QPixmap(":images/10d@2x.png"));
    }
    if (m1.icon=="11d"||m1.icon=="11n"){
        ui->label_3->setPixmap(QPixmap(":images/11d@2x.png"));
    }
    if (m1.icon=="13d"||m1.icon=="13n"){
        ui->label_3->setPixmap(QPixmap(":images/13d@2x.png"));
    }
    if (m1.icon=="50d"||m1.icon=="50n"){
        ui->label_3->setPixmap(QPixmap(":images/50d@2x.png"));
    }
}
