#ifndef ADDREGISTRY_H
#define ADDREGISTRY_H

#include <QDialog>

namespace Ui {
class addRegistry;
}

class addRegistry : public QDialog
{
    Q_OBJECT

public:
    explicit addRegistry(QWidget *parent = 0);
    int rtnID(QString id);
    ~addRegistry();

private slots:


    void on_btnOK_clicked();

public:
    Ui::addRegistry *ui;
};

#endif // ADDREGISTRY_H
