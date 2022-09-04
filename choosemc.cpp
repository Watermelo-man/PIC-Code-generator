#include "choosemc.h"
#include "ui_chooseMC.h"

chooseMC::chooseMC(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chooseMC)
{
    ui->setupUi(this);



    QFile PIClist ("MClist.txt");
    if (!PIClist.open(QIODevice::ReadOnly)) {
        qDebug() << PIClist.errorString();
        //return NULL;
    }
    QStringList wordList;
    while (!PIClist.atEnd()) {
        QByteArray line = PIClist.readLine();
        wordList.append(line.split(',').first());
    }
    for (int i=0;i<=wordList.size()-1;i++)
        ui->MClist->addItem(wordList[i]);
}

chooseMC::~chooseMC()
{
    delete ui;
}

void chooseMC::on_MClist_itemClicked(QListWidgetItem *item)
{
    ui->perlistWidget->clear();
    QString path = item->text();
    path.chop(1);
    QFile perlist (path+".txt");

    qDebug()<<path+".txt";

    nameMC = path;

    if (!perlist.open(QIODevice::ReadOnly)) {
        qDebug() << perlist.errorString();
        //return NULL;
    }
    QStringList wordList;
    while (!perlist.atEnd()) {
        QByteArray line = perlist.readLine();
        wordList.append(line.split(',').first());
    }
    ui->perlistWidget->addItems(wordList);
    perlist.close();

}


void chooseMC::on_chooseMCbutt_clicked()
{
    emit setMCName(nameMC);
    this->close();
}

