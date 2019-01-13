#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    QTimer *m_timer;
    int counter = 0;
};

#endif // MAINWINDOW_H
