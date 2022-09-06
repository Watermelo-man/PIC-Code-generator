#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "spiform.h"

#include "csvhandler.h"

#include <QFileDialog>

#include "choosemc.h"

#include <QChar>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionOpen_PIC_database_triggered();

    void on_actionOpenPIcController_triggered();

    void getMCName(QString name);

signals:
    void setnumSPI(QString);

private:
    Ui::MainWindow *ui;
    chooseMC *MCchoose;
    QString MCName;
    void FillTabs();
};
#endif // MAINWINDOW_H
