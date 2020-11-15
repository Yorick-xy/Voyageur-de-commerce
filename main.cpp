#include "qstd.h"
using namespace qstd;
#include "parameters.h"
#include "evolutionaryprocess.h"

/**
 * // tests sur TSP (#include "tsp.h")
 * TSP::init();
 * cout<<"Bordeaux -> Paris : "<<TSP::getDistance("Bordeaux", "Paris")<<endl;
 * QList<QString> copie=TSP::getCities();
 * copie.removeAt(1);
 * cout<<"Original : "<<TSP::tailleVilles()<<" - copie : "<<copie.size()<<endl;
 *
 * // tests sur tspindividual (#include "tspindividual.h" "tsp.h")
 * TSP::init();
 * TSPIndividual tspi;
 * cout<<tspi.toString()<<endl;
 */

int main()
{
    cout<<"Projet Genetique Voyageur de Commerce :"<<endl;
    // initialisation paramètres spécifiques au voyageur de commerce
    Parameters::crossoverRate = 0.0;
    Parameters::mutationRate = 0.3;
    Parameters::mutationAddRate = 0.0;
    Parameters::mutationDeleteRate = 0.0;
    Parameters::minFitness = 2579;
    // tests sur EvolutionaryProcess
    EvolutionaryProcess evo;
    evo.run();
}
