#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include<dialog.h>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase mydb;
    bool openConn()
    {
        mydb=QSqlDatabase::addDatabase("QMYSQL");
        mydb.setDatabaseName("qtdatabase");
        mydb.setHostName("localhost");
        mydb.setPort(3306);
        mydb.setUserName("root");
        mydb.setPassword("123456");
        if(mydb.open())
        {
           qDebug()<<"data base connewcted";
            return true;
       }
           else

               qDebug()<<"failed to connect database";
        return false;


    }
    void closeConn()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);

    }

private:
    Ui::MainWindow *ui;
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
