#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
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
    void UpdateTime();

    void on_pbA_toggled(bool checked);

    void on_pbB_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QTimer *m_timer;
    bool clk = true;
    int counter;
    Vtop * top;
    QPixmap led_on;
    QPixmap led_off;

    QTableWidget* m_pTableWidget;
    QStringList m_TableHeader;


    void updateUI();
};

#endif // MAINWINDOW_H
