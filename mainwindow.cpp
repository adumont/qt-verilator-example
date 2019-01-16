#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QTime>

#include "Vtop.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    m_timer->start(1000);
    counter = 0;
    ui->lcdNumber->display(counter);

    top = new Vtop;
    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateTime()
{
    ui->label->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->lcdNumber->display(++counter);
}

void MainWindow::on_pbA_toggled(bool checked)
{
    top->A=checked?1:0;
    updateUI();
}

void MainWindow::on_pbB_toggled(bool checked)
{
    top->B=checked?1:0;
    updateUI();
}

void MainWindow::updateUI()
{
    top->eval();
    ui->lcdC->display(top->C);
}
