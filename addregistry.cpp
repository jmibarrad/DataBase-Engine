#include "addregistry.h"
#include "ui_addregistry.h"
#include <QtCore>
#include <iostream>
#include <QIntValidator>
#include <stdlib.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdio>

typedef struct Entry{
    int code;
    char name[20];
    char surname[20];
    int age;
    int cellphone;

}Entry;

addRegistry::addRegistry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addRegistry)
{
    ui->setupUi(this);
    ui->corr1->setVisible(false);

}

addRegistry::~addRegistry()
{
    delete ui;
}



void addRegistry::on_btnOK_clicked()
{
    Entry obj;
    ui->corr1->setVisible(true);
    QIntValidator v(0,100,this);
    QString id=ui->leID->text().toLocal8Bit().constData();
    QString name= ui->leName->text().toLocal8Bit().constData();
    QString surname=ui->leSurname->text().toLocal8Bit().constData();
    QString age=ui->leAge->text().toLocal8Bit().constData();
    QString cell=ui->leCell->text().toLocal8Bit().constData();
/*
    MainWindow* obj2 = new MainWindow(this);
    const int lastRow= obj2->ui->tableWidget->rowCount();
    obj2->ui->tableWidget->insertRow(lastRow);
    obj2->ui->tableWidget->setCellWidget(lastRow,0,new QLabel(id));
    obj2->ui->tableWidget->setCellWidget(lastRow,1,new QLabel(name));
    obj2->ui->tableWidget->setCellWidget(lastRow,2,new QLabel(surname));
    obj2->ui->tableWidget->setCellWidget(lastRow,3,new QLabel(age));
    obj2->ui->tableWidget->setCellWidget(lastRow,4,new QLabel(cell));
*/
    int pos=0;
    if(v.validate(id,pos)&&!(ui->leID->text().isEmpty())&&!(ui->leName->text().isEmpty())
       &&!(ui->leAge->text().isEmpty())&&!(ui->leCell->text().isEmpty())
       &&!(ui->leSurname->text().isEmpty())&&v.validate(age,pos)&&v.validate(cell,pos)){

        obj.code=id.toInt();
        strcpy(obj.name,name.toLocal8Bit().data());
        strcpy(obj.surname,surname.toLocal8Bit().data());
        obj.age=age.toInt();
        obj.cellphone=cell.toInt();

        char* c_ID = new char[sizeof(int)];
        char* c_Age = new char [sizeof(int)];
        char* c_Cell = new char[sizeof(int)];
        memcpy(c_ID,&(obj.code),sizeof(int));
        memcpy(c_Age, &(obj.age),sizeof(int));
        memcpy(c_Cell, &(obj.cellphone),sizeof(int));

        //Convirtiendo todo a bytes
        FILE* database;
        char buffer[40+3*sizeof(int)];
        memcpy(buffer,c_ID,sizeof(int));
        memcpy(&buffer[4],obj.name,20);
        memcpy(&buffer[24],obj.surname,20);
        memcpy(&buffer[44],c_Age, sizeof(int));
        memcpy(&buffer[48],c_Cell,sizeof(int));

        database = fopen("db.dat","ab");
        fwrite(buffer,sizeof(char), sizeof(buffer),database);
        fclose(database);
        MainWindow* obj= new MainWindow();
        obj->initTable();
    }

    this->close();

}

int addRegistry::rtnID(QString id){
    return id.toInt();
}


