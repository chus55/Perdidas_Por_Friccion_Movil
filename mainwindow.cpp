#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/qmath.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->setCurrentIndex(-1);
    this->setWindowTitle("Tuberias");
    setWindowFlags(windowFlags() ^ Qt::WindowMaximizeButtonHint);

    ui->lineEditHF->setValidator(new QDoubleValidator(-1.7*(10^308),1.7*(10^308),12,this));
    ui->lineEditQ->setValidator(new QDoubleValidator(-1.7*(10^308),1.7*(10^308),12,this));
    ui->lineEditC->setValidator(new QDoubleValidator(-1.7*(10^308),1.7*(10^308),12,this));
    ui->lineEditD->setValidator(new QDoubleValidator(-1.7*(10^308),1.7*(10^308),12,this));
    ui->lineEditL->setValidator(new QDoubleValidator(-1.7*(10^308),1.7*(10^308),12,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    ui->lineEditHF->setEnabled(true);
    ui->lineEditQ->setEnabled(true);
    ui->lineEditC->setEnabled(true);
    ui->lineEditD->setEnabled(true);
    ui->lineEditL->setEnabled(true);

    ui->lineEditHF->clear();
    ui->lineEditQ->clear();
    ui->lineEditC->clear();
    ui->lineEditD->clear();
    ui->lineEditL->clear();

    QPalette palette1;
    palette1.setColor(QPalette::Base,Qt::white);
    QPalette palette2;
    palette2.setColor(QPalette::Text,Qt::black);

    ui->lineEditHF->setPalette(palette1);
    ui->lineEditQ->setPalette(palette1);
    ui->lineEditC->setPalette(palette1);
    ui->lineEditD->setPalette(palette1);
    ui->lineEditL->setPalette(palette1);

    ui->lineEditHF->setPalette(palette2);
    ui->lineEditQ->setPalette(palette2);
    ui->lineEditC->setPalette(palette2);
    ui->lineEditD->setPalette(palette2);
    ui->lineEditL->setPalette(palette2);

    palette2.setColor(QPalette::Text,Qt::red);

    switch(index)
    {
    case 0:
            ui->lineEditHF->setEnabled(false);
            ui->lineEditHF->setPalette(palette2);
            break;
    case 1:
            ui->lineEditQ->setEnabled(false);
            ui->lineEditQ->setPalette(palette2);
            break;
    case 2:
            ui->lineEditC->setEnabled(false);
            ui->lineEditC->setPalette(palette2);
            break;
    case 3:
            ui->lineEditD->setEnabled(false);
            ui->lineEditD->setPalette(palette2);
            break;
    case 4:
            ui->lineEditL->setEnabled(false);
            ui->lineEditL->setPalette(palette2);
            break;
    }
}

void MainWindow::on_pushButtonCalcular_clicked()
{
    if(ui->comboBox->currentIndex()!=-1)
    {

        int index = ui->comboBox->currentIndex();
        switch(index)
        {
        case 0:
            if(ui->lineEditQ->text()!="" && ui->lineEditC->text()!="" && ui->lineEditD->text()!="" && ui->lineEditL->text()!="")
            {

                double Q = ui->lineEditQ->text().toDouble();
                double C = ui->lineEditC->text().toDouble();
                double D = ui->lineEditD->text().toDouble();
                double L = ui->lineEditL->text().toDouble();

                double HF = (10.643*(qPow(Q,1.85))*L)/((qPow(C,1.85))*(qPow(D,4.87)));
                ui->lineEditHF->setText(QString::number(HF,'f',11));
            }
                break;
        case 1:
            if(ui->lineEditHF->text()!="" && ui->lineEditC->text()!="" && ui->lineEditD->text()!="" && ui->lineEditL->text()!="")
            {
                double HF = ui->lineEditHF->text().toDouble();
                double C = ui->lineEditC->text().toDouble();
                double D = ui->lineEditD->text().toDouble();
                double L = ui->lineEditL->text().toDouble();

                double Q = qPow((HF*(qPow(C,1.85))*(qPow(D,4.87)))/(10.643*L),(1/1.85));
                ui->lineEditQ->setText(QString::number(Q,'f',11));
            }
                break;
        case 2:
            if(ui->lineEditQ->text()!="" && ui->lineEditHF->text()!="" && ui->lineEditD->text()!="" && ui->lineEditL->text()!="")
            {
                double Q = ui->lineEditQ->text().toDouble();
                double HF = ui->lineEditHF->text().toDouble();
                double D = ui->lineEditD->text().toDouble();
                double L = ui->lineEditL->text().toDouble();

                double C = qPow((10.643*(qPow(Q,1.85))*L)/(HF*(qPow(D,4.87))),(1/1.85));
                ui->lineEditC->setText(QString::number(C,'f',11));
            }
                break;
        case 3:
            if(ui->lineEditQ->text()!="" && ui->lineEditC->text()!="" && ui->lineEditHF->text()!="" && ui->lineEditL->text()!="")
            {
                double Q = ui->lineEditQ->text().toDouble();
                double C = ui->lineEditC->text().toDouble();
                double HF = ui->lineEditHF->text().toDouble();
                double L = ui->lineEditL->text().toDouble();

                double D = qPow((10.643*(qPow(Q,1.85))*L)/((qPow(C,1.85))*HF),(1/4.87));
                ui->lineEditD->setText(QString::number(D,'f',11));
            }
                break;
        case 4:
            if(ui->lineEditQ->text()!="" && ui->lineEditC->text()!="" && ui->lineEditD->text()!="" && ui->lineEditHF->text()!="")
            {
                double Q = ui->lineEditQ->text().toDouble();
                double C = ui->lineEditC->text().toDouble();
                double D = ui->lineEditD->text().toDouble();
                double HF = ui->lineEditHF->text().toDouble();

                double L = (HF*(qPow(C,1.85))*(qPow(D,4.87)))/(10.643*(qPow(Q,1.85)));
                ui->lineEditL->setText(QString::number(L,'f',11));
            }
                break;
        }
    }
}
