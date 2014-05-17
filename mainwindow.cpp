#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_addregistry.h"
#include <qtcore>
#include <QtGui>
#include <QDebug>
#include <QLabel>
#include <cstdio>
#include <iostream>
#include "addregistry.h"
#include "entries.h"



MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow){

    ui->setupUi(this);
    this->setFixedSize(1366,700);
    initTable();

}

void MainWindow::initTable(){

        int ID;
        char name[20];
        char surname[20];
        int age;
        int cell;


        FILE* rFile;

        rFile = fopen("db.dat","rb");

        fseek (rFile, 0, SEEK_END);
        long size=ftell (rFile);
        rewind(rFile);
        char rBuffer[size];
        int pos=0;
        int posv=0;

        if(rFile){
            fread(rBuffer, 1, sizeof(rBuffer),rFile);

            for(int rows=0; rows<(size/52);rows++){

            const int lastRow= ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(lastRow);

            memcpy(&ID,&rBuffer[pos],sizeof(int));
            QString q_Id=QString::number(ID);
            ui->tableWidget->setCellWidget(rows,0,new QLabel(q_Id,this));
            posv++;
            pos+=4;

            memcpy(name,&rBuffer[pos],20);
            ui->tableWidget->setCellWidget(rows,1,new QLabel(name,this));
            posv++;
            pos+=20;

            memcpy(surname, &rBuffer[pos],20);
            ui->tableWidget->setCellWidget(rows,2,new QLabel(surname,this));
            posv++;
            pos+=20;

            memcpy(&age,&rBuffer[pos],sizeof(int));
            QString q_age =QString::number(age);
            ui->tableWidget->setCellWidget(rows,3,new QLabel(q_age,this));
            pos+=4;
            posv++;

            memcpy(&cell,&rBuffer[pos],sizeof(int));
            QString q_cell=QString::number(cell);
            ui->tableWidget->setCellWidget(rows,4,new QLabel(q_cell,this));
            pos+=4;
            posv++;

            }

        }else{
        std::cout<<"No se pudo";

        }




    fclose(rFile);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updtTable(){

    addRegistry* add =new addRegistry();
    const int lastRow= ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(lastRow);

    QString id =add->ui->leID->text().toLocal8Bit().constData();
    QString name = add->ui->leName->text().toLocal8Bit().constData();
    QString surname = add->ui->leSurname->text().toLocal8Bit().constData();
    QString age = add->ui->leAge->text().toLocal8Bit().constData();
    QString cell = add->ui->leCell->text().toLocal8Bit().constData();

    ui->tableWidget->setCellWidget(lastRow,0,new QLabel(id,this));
    ui->tableWidget->setCellWidget(lastRow,1,new QLabel(name,this));
    ui->tableWidget->setCellWidget(lastRow,2,new QLabel(surname,this));
    ui->tableWidget->setCellWidget(lastRow,3,new QLabel(age,this));
    ui->tableWidget->setCellWidget(lastRow,4,new QLabel(cell,this));


}


void MainWindow::on_actionSave_triggered()
{

}

void MainWindow::on_btnAdd_clicked()
{
    addRegistry* add=new addRegistry();
    add->show();
}

void MainWindow::on_btnSearch_clicked()
{

}
