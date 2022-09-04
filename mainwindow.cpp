#include "mainwindow.h"
#include "ui_mainwindow.h"






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString spitab = QString("SPI%1").arg(ui->SPINum->count());

    ui->SPINum->insertTab(ui->SPINum->count(),new SPIform(),QIcon(QString("")),spitab);

    QMetaObject::Connection m_connection = connect(this,SIGNAL (setnumSPI(QString)),ui->SPINum->widget(ui->SPINum->count()-1),SLOT(getnumSPI(QString)));

    emit setnumSPI(spitab);

    disconnect(m_connection);

    ui->SPINum->setCurrentIndex(ui->SPINum->count()-1);



}


void MainWindow::on_pushButton_2_clicked()
{
    while (ui->SPINum->count())
        ui->SPINum->removeTab(ui->SPINum->count()-1);

    //ui->SPINum->setCurrentIndex(ui->SPINum->count()-1);
}


void MainWindow::on_actionOpen_PIC_database_triggered()
{
    QString full_fname = QFileDialog::getOpenFileName(this, tr("Open File"), "" , tr("*"));
    csvHandler::openPIC(full_fname,3);
}


void MainWindow::on_actionOpenPIcController_triggered()
{
    MCchoose = new chooseMC();
    MCchoose->show();
    connect(MCchoose,SIGNAL(setMCName(QString)),this,SLOT(getMCName(QString)));
}


void MainWindow::getMCName(QString name)
{
    MCName = name;
    QFile perlist(name+".txt");
    qDebug() <<name+".txt";
    ui->label_2->setText(name);
    if (!perlist.open(QIODevice::ReadOnly)) {
    qDebug() << perlist.errorString();
    //return NULL;
    }
    QStringList perefList;
    while (!perlist.atEnd()) {
        QByteArray line = perlist.readLine();
        line.chop(2);
        perefList.append(line.split(',').first());
    }
    qDebug()<<perefList;

    for (int i =0; i<=perefList.size()-1;i++)
    {
        if (perefList[i].contains("spi"))
        {

            ui->SPINum->clear();

            QChar charnum = perefList[i][perefList[i].size()-1];

            int amount = charnum.toLatin1()-48;

            for(int j = 0;j<=amount;j++)
            {

            QString name = "SPI ";
            name += (char)(48+j);
            ui->SPINum->insertTab(ui->SPINum->count(),new SPIform(),QIcon(QString("")),name);

            QMetaObject::Connection m_connection = connect(this,SIGNAL (setnumSPI(QString)),ui->SPINum->widget(ui->SPINum->count()-1),SLOT(getnumSPI(QString)));

            emit setnumSPI(name);

            disconnect(m_connection);
            }
        }
    }

}
