#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include <QTextStream>
#include <qfile.h>
#include <QStringList>
#include <QDebug>
#include "regexpcontrol.h"

class csvHandler
{
public:
    csvHandler();

    static void openPIC(QString path, int perefCount);
};

#endif // CSVHANDLER_H
