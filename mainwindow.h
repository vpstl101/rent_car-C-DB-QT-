#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "secdialog.h"
#include "join.h"

using namespace  std;

QT_BEGIN_NAMESPACE
namespace Ui
{ class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked();


    void on_join_clicked();

private:
    Ui::MainWindow *ui;
    Database db;
    QSqlQuery sql;
    string query;
    secDialog *Secdialog;
    join *Join;
};
#endif // MAINWINDOW_H
