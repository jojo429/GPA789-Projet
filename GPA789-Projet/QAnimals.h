// QAnimals.h
//
// Description:
// Classe virtuelle représentant une entité dynamique qui est un animal.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_ANIMALS_H
#define Q_ANIMALS_H

#include "QDynamic.h"

class QAnimals : public QDynamic
{

public:
	QAnimals(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type);
	virtual ~QAnimals();

};

#endif //Q_ANIMALS_H

