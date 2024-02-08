#include "mainwindow.h"
#include "ui_mainwindow.h"


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


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text() == "Saddleback College")
    {
        ui->label_collegeName->setText("Saddleback College selected!");
    }
    else if (item->text() == "Arizona State University")
    {
        ui->label_collegeName->setText("Arizona State University");
    }

    /*
    switch(item->text())
    {
        case "Saddleback College":
        {
            ui->label_collegeName->setText("Saddleback College selected!");
        }
        break;

        case "Arizona State University":
        {
            ui->label_collegeName->setText("Arizona State University selected!");
        }
        break;
    }*/
}

