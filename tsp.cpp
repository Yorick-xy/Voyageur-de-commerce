#include "tsp.h"

QList<City *> TSP::cities;
int **TSP::distances;

void TSP::init()
{
    cities.append(new City("Paris", "Pa"));
    cities.append(new City("Lyon", "Ly"));
    cities.append(new City("Marseille", "Ma"));
    cities.append(new City("Nantes", "Na"));
    cities.append(new City("Bordeaux","Bo"));
    cities.append(new City("Toulouse", "To"));
    cities.append(new City("Lille", "Li"));

    distances = new int* [cities.size()];
    distances[0] = new int[cities.size()] {0,462,772,379,546,678,215};
    distances[1]=new int[cities.size()] {462,0,326,598,842,506,664};
    distances[2]=new int[cities.size()] {772,326,0,909,555,407,1005};
    distances[3]=new int[cities.size()] {379,598,909,0,338,540,584};
    distances[4]=new int[cities.size()] {546,842,555,338,0,250,792};
    distances[5]=new int[cities.size()] {678,506,407,540,250,0,926};
    distances[6]=new int[cities.size()] {215,664,1005,584,792,926,0};
}

int TSP::getDistance(City *city1, City *city2)
{
    return distances[cities.indexOf(city1)][cities.indexOf(city2)];
}

QList<City *> TSP::getCities()
{
    QList<City *> ret(cities);
    return ret;
}

int TSP::tailleVilles()
{
    return cities.size();
}
