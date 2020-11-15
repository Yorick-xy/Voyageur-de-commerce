#ifndef CITIES_H
#define CITIES_H

#include <QString>

class City
{
    QString name;
    QString thumb;
public:
    City(QString n, QString t);
    QString getName() const;
    QString getThumb() const;
};

#endif // CITIES_H
