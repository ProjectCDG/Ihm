#include "mesurerpage.h"
#include "ui_mesurerpage.h"
#include <QLabel>
#include <QMovie>
#include <QMessageBox>
#include <QDebug>
#include <time.h>
mesurerpage::mesurerpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mesurerpage)
{
    ui->setupUi(this);
    ui->labX->hide();
    ui->labY->hide();
    ui->labZ->hide();
    ui->xLcd->hide();
    ui->yLcd->hide();
    ui->zLcd->hide();
    ui->labLogo->setPixmap(QPixmap("logo.svg"));
    srand(time(NULL));
    ui->butSuivant->setEnabled(false);
}

mesurerpage::~mesurerpage()
{
    delete ui;
}

void mesurerpage::on_butMesure_clicked()
{
    ui->labGif->show();
    QMovie *movie = new QMovie("gif.gif");
    ui->labGif->setMovie(movie);
    movie->start();
    ui->labX->show();
    ui->labY->show();
    ui->labZ->show();
    ui->xLcd->show();
    ui->yLcd->show();
    ui->zLcd->show();
    ui->butMesure->setEnabled(false);
    centreDeGravite();
    ui->butSuivant->setEnabled(true);

}
void mesurerpage::centreDeGravite()
{
    x = rand()%1000;
    y = rand()%1000;
    z = rand()%1000;
    ui->xLcd->display(x);
    ui->yLcd->display(y);
    ui->zLcd->display(z);

}

void mesurerpage::on_butSuivant_clicked()
{
    reset();
    emit changePage("sauvegarder");
}

void mesurerpage::on_butDeco_clicked()
{
    QMessageBox msgBox;
   int decoVerif = msgBox.critical(this, "Avertissement", "<FONT COLOR='#ffffff'>Êtes vous sur de vouloir vous deconnecter ? Vous risquer de perdre votre mesure</FONT>", "Oui","Non");
    if (decoVerif == msgBox.result())
    {
        reset();
        emit changePage("login");
    }


}

void mesurerpage::reset()
{
    ui->labX->hide();
    ui->labY->hide();
    ui->labZ->hide();
    ui->xLcd->hide();
    ui->yLcd->hide();
    ui->zLcd->hide();
    ui->labGif->hide();
    ui->butMesure->setEnabled(true);
    ui->butSuivant->setEnabled(false);

}


int mesurerpage::envoieCoordX()
{
    qDebug() << "Load x coord";
    return x;
}

int mesurerpage::envoieCoordY()
{
    qDebug() << "Load y coord";
    return y;
}

int mesurerpage::envoieCoordZ()
{
    qDebug() << "Load z coord";
    return z;
}
