// QLuminosity.h
//
// Description:
// Classe représentant un facteur de luminosité généré cycliquement pour une durée donnée.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_LUMINOSITY_H
#define Q_LUMINOSITY_H

#include "QCyclic.h"

class QLuminosity : public QCyclic
{

public:
	QLuminosity(int cycle, int average, int variation);
	~QLuminosity()=default;

};

#endif //Q_LUMINOSITY_H

