// QPrecipitation.h
//
// Description:
// Classe représentant un facteur de précipitation généré cycliquement pour une durée donnée.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_PRECIPITATION_H
#define Q_PRECIPITATION_H

#include "QCyclic.h"
#include <array>

class QPrecipitation : public QCyclic
{

public:
	QPrecipitation(int cycle, int average, int variation);
	~QPrecipitation();

};

#endif //Q_PRECIPITATION_H

