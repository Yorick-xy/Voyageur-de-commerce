#ifndef TSPGENE_H
#define TSPGENE_H

#include <QString>
#include "city.h"

class TSPGene
{
private:
    City *city;
public:
    TSPGene(City *_city);
    TSPGene(TSPGene &g);
    int getDistance(TSPGene &g);
    void mutate();
    QString toString();
};

#endif // TSPGENE_H
