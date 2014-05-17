#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include "addregistry.h"
#include "entries.h"

namespace Ui {
class MainWindow;
}

class addRegistry;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    void updtTable();
    void initTable();

    ~MainWindow();

private slots:
    void on_actionSave_triggered();

    void on_btnAdd_clicked();

    void on_btnSearch_clicked();

public:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
