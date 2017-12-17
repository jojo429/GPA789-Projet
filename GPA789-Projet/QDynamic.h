// QDynamic.h
//
// Description:
// Classe virtuelle représentant une entité ayant la faculté de se déplacer.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
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

