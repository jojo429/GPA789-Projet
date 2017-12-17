// QLuminosity.h
//
// Description:
// Classe repr�sentant un facteur de luminosit� g�n�r� cycliquement pour une dur�e donn�e.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
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

