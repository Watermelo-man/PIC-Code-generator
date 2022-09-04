#ifndef CHOOSEMC_H
#define CHOOSEMC_H

#include <QWidget>

#include <QFile>

#include <QDebug>

#include <QListWidget>
namespace Ui {
class chooseMC;
}

class chooseMC : public QWidget
{
    Q_OBJECT

public:
    explicit chooseMC(QWidget *parent = nullptr);
    ~chooseMC();

private slots:
    void on_MClist_itemClicked(QListWidgetItem *item);

    void on_chooseMCbutt_clicked();

private:
    Ui::chooseMC *ui;

    QString nameMC;

signals:
    void setMCName(QString);
};

#endif // CHOOSEMC_H
