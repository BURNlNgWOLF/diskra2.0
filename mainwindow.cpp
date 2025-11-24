#include "mainwindow.h"
#include "math.h"
#include "./ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
//Reads input field, displays length of it in stdout
void MainWindow::on_submitInput_clicked(){
    QString text = ui->functionInput->text();
    std::cout << text.toStdString() << std::endl;

    //ui->functionInput->clear();

    int funcLength = HowLongIsBoolFunc(text);
    std::cout << funcLength << std::endl;
    polynomZhegalkina({false,false,true,true,false,true,true,true,true,false,true,false,true,true,true,true});
}
MainWindow::~MainWindow()
{
    delete ui;
}
