#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QPixmap pix("/home/hk/qt_workspace/SQL_DB/web.png");
    //ui->label_4->setPixmap(pix);
    if(openConn())
    {
       ui->label->setText("data base connewcted");

   }
       else
           ui->label->setText("failed to connect to database ");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
QString username,password;
username=ui->lineEdit->text();
password=ui->lineEdit_2->text();
if(!openConn())
{
qDebug()<<"failed to open database";
return;
}
QString q="select * from employeeinfo where username='"+username+"'and pass='"+password+"'";

QSqlQuery qry;
qry.prepare(q);
if(qry.exec())
{
    int count=0;
while(qry.next())
    {count++;
}
if(count==1)
{
ui->label->setText("username and password is correct");
closeConn();
this->hide();
Dialog dialog;
dialog.setModal(true);
dialog.exec();


}
else if (count<1)
{
ui->label->setText("username and password is incorrect");
}
else
    ui->label->setText("duplicate username and password ");
}
}
