// QEnvironmentalFactor.h
//
// Description:
// Classe virtuelle repr�sentant un facteur environnemental.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#ifndef Q_ENVIRONMENTAL_FACTOR_H
#define Q_ENVIRONMENTAL_FACTOR_H

#include <QGraphicsItem>
#include <array>

class QEnvironmentalFactor
{

public:
	QEnvironmentalFactor();
	virtual ~QEnvironmentalFactor()=default;
	
	virtual float getFactor(int Time);
	virtual void setTable(int cycle, int average, int variation);
};

#endif //Q_ENVIRONMENTAL_FACTOR_H
