#ifndef TSP_H
#define TSP_H

#include <QString>
#include <QList>
#include "city.h"

class TSP
{
private:
    static QList<City *> cities;
    static int **distances;
public:
    static void init();
    static int getDistance(City *city1, City *city2);
    static QList<City *> getCities();
    static int tailleVilles();
};

#endif // TSP_H
