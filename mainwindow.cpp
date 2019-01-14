#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_timer = new QTimer(this);
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    m_timer->start(1000);
    ui->lcdNumber->display(counter);


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
