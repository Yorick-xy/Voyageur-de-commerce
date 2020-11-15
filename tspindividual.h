#ifndef TSPINDIVIDUAL_H
#define TSPINDIVIDUAL_H

#include <QList>
#include "tspgene.h"

class TSPIndividual
{
private:
    double fitness=-1;
public:
    QList<TSPGene *> genome;
    TSPIndividual();
    TSPIndividual(TSPIndividual *father);
    double getFitness() const;
    void mutate();
    double evaluate();
    QString toString();
    static bool lessFitnessThan(const TSPIndividual *v1, const TSPIndividual *v2);
};

#endif // TSPINDIVIDUAL_H
