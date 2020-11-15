#include "city.h"

QString City::getName() const
{
    return name;
}

QString City::getThumb() const
{
    return thumb;
}

City::City(QString n, QString t) : name(n), thumb(t)
{

}
