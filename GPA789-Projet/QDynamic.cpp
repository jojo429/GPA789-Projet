// QDynamic.cpp
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

#include "QDynamic.h"

QDynamic::QDynamic(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QEntity{ environment , forestscene, lifeSpan, tree, type }
{

}

void QDynamic::move()
{

}

