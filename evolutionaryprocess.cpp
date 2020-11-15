#include "evolutionaryprocess.h"
#include "tsp.h"
#include "parameters.h"
#include <QString>
#include <QDebug>

static QString txt;

TSPIndividual *EvolutionaryProcess::selection()
{
    int totalRanks = Parameters::individualsNb*(Parameters::individualsNb+1)/2;
    int rand=Parameters::randomGenerator->get(totalRanks);
    int indIndex = 0;
    int nbParts = Parameters::individualsNb;
    int totalParts = 0;

    while(totalParts<rand) {
        indIndex++;
        totalParts+=nbParts;
        nbParts--;
    }
    std::sort(population.begin(), population.end(), TSPIndividual::lessFitnessThan);
    return population.at(indIndex);
}

void EvolutionaryProcess::survival(QList<TSPIndividual *> &newGeneration)
{
    population = newGeneration;
}

EvolutionaryProcess::EvolutionaryProcess()
{
    TSP::init();
    for(int i=0; i<Parameters::individualsNb; i++) {
        TSPIndividual *indiv=new TSPIndividual();
        population.append(indiv);
    }
}

void EvolutionaryProcess::run()
{
    bestFitness = Parameters::minFitness + 1;
    //qDebug() <<generationNb<<" < "<<Parameters::generationsMaxNb<<" ; "<<bestFitness<<" > "<<Parameters::minFitness;
    //int nbLoop=0;
    TSPIndividual *bestInd;
    while(generationNb<Parameters::generationsMaxNb && bestFitness>Parameters::minFitness) {
        for(int i=0; i<population.size(); i++) {
            TSPIndividual *ind=population.at(i);
            ind->evaluate();
        }
        // meilleur individu
        std::sort(population.begin(), population.end(), TSPIndividual::lessFitnessThan);
        bestInd = population.at(0);
        bestFitness = bestInd->getFitness();
        // sélection et reproduction
        QList<TSPIndividual *> newGeneration;
        newGeneration.append(bestInd);
        for(int i=0; i<Parameters::individualsNb-1; i++) {
            // crossOverRate=0, donc pas de couple, mais seul un père
            TSPIndividual *father = selection();
            TSPIndividual *indiv = new TSPIndividual(father);
            newGeneration.append(indiv);
        }
        survival(newGeneration);
        generationNb++;
        /*if(nbLoop==1)
            exit(0);
        nbLoop++;*/
    }
    txt.sprintf("\nGeneration %d : Le meilleur est %s !",generationNb, bestInd->toString().toStdString().c_str());
    Parameters::print(txt, 0);
}
