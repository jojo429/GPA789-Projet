// QStatic.h
//
// Description:
// Classe virtuelle représentant une entité n'ayant pas la faculté de se déplacer.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#include "QStatic.h"

QStatic::QStatic(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QEntity(environment, forestscene, lifeSpan, tree, type)
{

}
