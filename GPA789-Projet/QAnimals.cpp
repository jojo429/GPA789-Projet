// QAnimals.cpp
//
// Description:
// Classe virtuelle repr�sentant une entit� dynamique qui est un animal.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QAnimals.h"

QAnimals::QAnimals(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QDynamic{ environment , forestscene, lifeSpan, tree, type }
{

}
