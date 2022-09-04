#include "csvhandler.h"

csvHandler::csvHandler()
{

}

void csvHandler::openPIC(QString path, int perefCount)
{
    RegExpControl reg = RegExpControl("pic[1632]{2}[mxz]{2}\\d{2,3}[a-z]{0,1}\\d{3}[a-z]{0,1}");

    reg.checkRegExp();

    QFile PICbase (path);
    if (!PICbase.open(QIODevice::ReadOnly))
    {
        qDebug() << PICbase.errorString();
        //return NULL;
    }
    QStringList wordList;

    while (!PICbase.atEnd())
    {
        QByteArray line = PICbase.readLine();
        wordList.append(line.split(',').first());
    }
    QFile listMC("MClist.txt");
    listMC.open(QIODevice::WriteOnly);
    QTextStream list(&listMC);

    for (int i =0; i<wordList.size();i++)
    {
        if (reg.match(wordList[i]))
        {
            wordList[i].chop(3);
            list<<wordList[i]+"\n";
            QFile newMC( wordList[i]+".txt");
            newMC.open(QIODevice::WriteOnly);
            for(int j=i+1; j<=i+perefCount;j++)
            {
                QTextStream perefery(&newMC);
                perefery<< wordList[j];
            }
            newMC.flush();
            newMC.close();
        }
    }
    listMC.flush();
    listMC.close();
}
