// QAnimals.cpp
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

#include "QAnimals.h"

QAnimals::QAnimals(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QDynamic{ environment , forestscene, lifeSpan, tree, type }
{

}
