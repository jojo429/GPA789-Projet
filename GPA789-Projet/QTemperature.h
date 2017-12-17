// QTemperature.h
//
// Description:
// Classe repr�sentant un facteur de temp�rature g�n�r� cycliquement pour une dur�e donn�e.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
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

