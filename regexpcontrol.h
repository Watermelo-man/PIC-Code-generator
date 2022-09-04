#ifndef REGEXPCONTROL_H
#define REGEXPCONTROL_H

#include <QRegularExpression>
#include <QDebug>
class RegExpControl
{
public:
    RegExpControl();
    RegExpControl(QString exp);
    bool checkRegExp();
    void setRegExp (QString exp);
    bool match(QString str);
private:
    QRegularExpression exp;
};

#endif // REGEXPCONTROL_H
