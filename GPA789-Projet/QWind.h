// QWind.h
//
// Description:
// Classe repr�sentant un facteur de vent g�n�r� cycliquement pour une dur�e donn�e.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
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

