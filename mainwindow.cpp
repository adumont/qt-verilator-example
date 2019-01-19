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

    led_on = QPixmap(":/assets/leds/assets/leds/red.svg");
    led_off = QPixmap(":/assets/leds/assets/leds/red_off.svg");
    ui->ledC->setPixmap(led_off);

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
    ui->clk->setPixmap( (counter%2) ? led_on : led_off );
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

    if(top->C) {
        ui->lcdC->setStyleSheet("background-color: rgb(170, 255, 127);");
        ui->ledC->setPixmap(led_on);
    } else {
        ui->lcdC->setStyleSheet("");
        ui->ledC->setPixmap(led_off);
    }
}
