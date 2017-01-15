#ifndef DIALOG_H
#define DIALOG_H
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QDialog>
#include<mainwindow.h>
namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // DIALOG_H
