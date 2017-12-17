// QTemperature.h
//
// Description:
// Classe représentant un facteur de température généré cycliquement pour une durée donnée.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_TEMPERATURE_H
#define Q_TEMPERATURE_H

#include "QCyclic.h"

class QTemperature : public QCyclic
{

public:
	QTemperature(int cycle, int average, int variation);
	~QTemperature()=default;
};

#endif //Q_TEMPERATURE_H

