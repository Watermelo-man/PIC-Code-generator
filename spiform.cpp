#include "spiform.h"
#include "ui_spiform.h"
#include "spiform.h"

SPIform::SPIform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SPIform)
{

    ui->setupUi(this);

    ui->InitSPI->setText("KEK");

    //connect(MainWindow,SIGNAL(setnumSPI(QString)),this,SLOT(getnumSPI(QString)));

}

SPIform::~SPIform()
{
    delete ui;
}

void SPIform::getnumSPI(QString name)
{
    ui->InitSPI->setText(name);
}
