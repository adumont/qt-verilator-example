#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Vtop.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbA_toggled(bool checked);

    void on_pbB_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QTimer *m_timer;
    int counter;
    Vtop * top;
    void updateUI();
};

#endif // MAINWINDOW_H
