#ifndef SPIFORM_H
#define SPIFORM_H

#include <QWidget>




namespace Ui {
class SPIform;
}

class SPIform : public QWidget
{
    Q_OBJECT

public:
    explicit SPIform(QWidget *parent = nullptr);
    ~SPIform();

private:
    Ui::SPIform *ui;
public slots:
    void getnumSPI(QString name);

};

#endif // SPIFORM_H
