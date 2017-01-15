#include "dialog.h"
#include "ui_dialog.h"
#include<mainwindow.h>
#include<QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
 MainWindow win;
    if(win.openConn())
    {
       ui->label_6->setText("data base connewcted");

   }
       else
           ui->label_6->setText("failed to connect to database ");

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
QString fname=ui->lineEdit->text();
QString lname=ui->lineEdit_2->text();
QString age=ui->lineEdit_3->text();
QString username=ui->lineEdit_4->text();
QString password=ui->lineEdit_5->text();
QString q="insert into employeeinfo  values (NULL,'"+fname+"','"+lname+"','"+age+"','"+username+"','"+password+"')";
MainWindow win;
qDebug()<<q;
if(!win.openConn())
{
qDebug()<<"failed to open database";
return;
}


QSqlQuery qry;
qry.prepare(q);
if(qry.exec())
{


    QMessageBox::critical(this,tr("title"),tr("data saved"));

win.closeConn();
}

else
    QMessageBox::critical(this,tr("title"),qry.lastError().text());

}


void Dialog::on_pushButton_2_clicked()
{
    QString fname=ui->lineEdit->text();
    QString lname=ui->lineEdit_2->text();
    QString age=ui->lineEdit_3->text();
    QString username=ui->lineEdit_4->text();
    QString password=ui->lineEdit_5->text();
    QString q="update employeeinfo set fname='"+fname+"',lname='"+lname+"',age='"+age+"',pass='"+password+"'where username='"+username+"'";
    MainWindow win;
    qDebug()<<q;
    if(!win.openConn())
    {
    qDebug()<<"failed to open database";
    return;
    }


    QSqlQuery qry;
    qry.prepare(q);
    if(qry.exec())
    {


        QMessageBox::critical(this,tr("title"),tr("data saved"));

    win.closeConn();
    }

    else
        QMessageBox::critical(this,tr("title"),qry.lastError().text());
}
