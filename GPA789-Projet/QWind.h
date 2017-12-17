// QWind.h
//
// Description:
// Classe représentant un facteur de vent généré cycliquement pour une durée donnée.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_WIND_H
#define Q_WIND_H

#include "QCyclic.h"
#include <array>

class QWind : public QCyclic
{

public:
	QWind(int cycle, int average, int variation);
	~QWind()=default;

};

#endif //Q_WIND_H

