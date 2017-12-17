// QDynamic.h
//
// Description:
// Classe virtuelle repr�sentant une entit� ayant la facult� de se d�placer.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#ifndef Q_DYNAMIC_H
#define Q_DYNAMIC_H

#include "QEntity.h"
#include "QEnvironment.h"

class QDynamic : public QEntity
{

public:
	QDynamic(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type);
	virtual ~QDynamic();

protected:
	virtual void move();

};

#endif //Q_DYNAMIC_H

