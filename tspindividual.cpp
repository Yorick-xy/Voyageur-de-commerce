#include "tspindividual.h"
#include <QTextStream>
#include "tsp.h"
#include "parameters.h"
#include <QDebug>
#include "city.h"

double TSPIndividual::getFitness() const
{
    return fitness;
}

void TSPIndividual::mutate()
{
    if(Parameters::randomGenerator->getFloat()<Parameters::mutationRate) {
        int index1 = Parameters::randomGenerator->get(genome.size());
        TSPGene *g=genome.at(index1);
        genome.removeAt(index1);
        int index2 = Parameters::randomGenerator->get(genome.size());
        genome.insert(index2, g);
    }
}

double TSPIndividual::evaluate()
{
    int totalKm = 0;
    TSPGene *oldGene=nullptr;
    for(int i=0; i<genome.size(); i++) {
        TSPGene *g=genome.at(i);
        if(oldGene!=nullptr)
            totalKm+=g->getDistance(*oldGene);
        oldGene = g;
    }
    totalKm += oldGene->getDistance(*genome.at(0));
    fitness = totalKm;
    return fitness;
}

QString TSPIndividual::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<fitness<<" km : [";
    foreach (TSPGene *g, genome) {
        buf<<g->toString()<<" ";
    }
    buf<<"]";
    return res;
}

bool TSPIndividual::lessFitnessThan(const TSPIndividual *v1, const TSPIndividual *v2)
{
    return v1->getFitness() < v2->getFitness();
}

TSPIndividual::TSPIndividual()
{
    QList<City *> cities=TSP::getCities();
    while(cities.size()!=0) {
        int index = Parameters::randomGenerator->get(cities.size());
        genome.append(new TSPGene(cities.at(index)));
        cities.removeAt(index);
    }
}

TSPIndividual::TSPIndividual(TSPIndividual *father)
{
    for(int i=0; i<father->genome.size(); i++) {
        genome.append(new TSPGene(*father->genome.at(i)));
    }
    mutate();
}
