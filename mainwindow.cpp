#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Vtop.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    top = new Vtop;
    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbA_toggled(bool checked)
{
    top->A=checked;
    updateUI();
}

void MainWindow::on_pbB_toggled(bool checked)
{
    top->B=checked;
    updateUI();
}

void MainWindow::updateUI()
{
    top->eval();
    ui->lcdC->display(top->C);
}
