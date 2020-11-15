#include "tspgene.h"
#include "tsp.h"

TSPGene::TSPGene(City *_city) : city(_city)
{}

TSPGene::TSPGene(TSPGene &g) : city(g.city)
{}

int TSPGene::getDistance(TSPGene &g)
{
    return TSP::getDistance(city, g.city);
}

void TSPGene::mutate()
{

}

QString TSPGene::toString()
{
    return city->getName();
}
