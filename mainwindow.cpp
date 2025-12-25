#include "math.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QSpacerItem>
#include <iostream>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupOutputOptions();

    ui->widgetZhegalkin->hide();
    ui->tableWidget->hide();
    ui->widgetSDKNF->hide();
    updateOutputVisibility();

    connect(ui->checkBoxZhegalkin, &QCheckBox::stateChanged,
            this, &MainWindow::updateOutputVisibility);
    connect(ui->checkBoxTruthTable, &QCheckBox::stateChanged,
            this, &MainWindow::updateOutputVisibility);
    connect(ui->checkBoxStatistics, &QCheckBox::stateChanged,
            this, &MainWindow::updateOutputVisibility);
}



void MainWindow::setupOutputOptions()
{
    QString boldStyle = "font-weight: bold;";
    ui->checkBoxZhegalkin->setStyleSheet(boldStyle);
    ui->checkBoxTruthTable->setStyleSheet(boldStyle);
    ui->checkBoxStatistics->setStyleSheet(boldStyle);
}

void MainWindow::updateOutputVisibility()
{
    ui->widgetZhegalkin->hide();
    ui->tableWidget->hide();
    ui->widgetSDKNF->hide();

    if (ui->checkBoxZhegalkin->isChecked()) {
        ui->widgetZhegalkin->show();
    }
    if (ui->checkBoxTruthTable->isChecked()) {
        ui->tableWidget->show();
    }
    if (ui->checkBoxStatistics->isChecked()) {
        ui->widgetSDKNF->show();
    }

}



void MainWindow::on_submitInput_clicked()
{
    QString text = ui->functionInput->text();
    std::vector<bool> nullvector = {};
    std::vector<bool> zheg = polynomZhegalkina(QStringTovector(text));

    if (!zheg.empty()){
        ui->stackedWidget->setCurrentIndex(1);
        displayTruthTableFromVector(ui->tableWidget, QStringTovector(text));
        ui->editZhegalkin->setText(QString::fromStdString(zhegalkinToString(zheg)));
    }

}

void MainWindow::on_btnPage1_clicked(){
    ui->stackedWidget->setCurrentIndex(0);
}
MainWindow::~MainWindow()
{
    delete ui;
}
