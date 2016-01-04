#include "card.h"

Card::Card(QObject* parent, int value)
    : QObject(parent)
{
    ISDN = value;
}

int Card::getISDN() const
{
    return ISDN;
}
