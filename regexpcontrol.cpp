#include "regexpcontrol.h"

RegExpControl::RegExpControl()
{

}

RegExpControl::RegExpControl(QString exp)
{
    QRegularExpression re(exp);
    this->exp = re;
}

void RegExpControl::setRegExp (QString exp)
{
    QRegularExpression re(exp);
    this->exp = re;
}

bool RegExpControl::checkRegExp()
{
    if (this->exp.isValid() )
    {
        qDebug() << "right exp";
        return true;
    }
    else
    {
        qDebug() << "something is wrong in reg exp";
        return false;
    }
}
bool RegExpControl::match(QString str)
{
    QRegularExpressionMatch match = exp.match(str);

    if (match.hasMatch())
        return true;
    else
        return false;

}
