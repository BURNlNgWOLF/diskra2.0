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

    //int funcLength = HowLongIsBoolFunc(text);
    //std::cout << funcLength << std::endl;
    //std::cout << "^^^" << std::endl;
    std::vector<bool> inputed = QStringTovector(text);
    std::vector<bool> zheg = polynomZhegalkina(inputed);
    std::vector<std::vector<bool>> truth = generateTruthTable(zheg);
    //printBoolMatrix(truth);
    std::cout << "and the zhegalkin is: ";
    printBoolVector(zheg);


}
MainWindow::~MainWindow()
{
    delete ui;
}
