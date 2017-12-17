// QPrecipitation.h
//
// Description:
// Classe repr�sentant un facteur de pr�cipitation g�n�r� cycliquement pour une dur�e donn�e.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
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

