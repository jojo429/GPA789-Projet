// QDynamic.cpp
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

#include "QDynamic.h"

QDynamic::QDynamic(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QEntity{ environment , forestscene, lifeSpan, tree, type }
{

}

void QDynamic::move()
{

}

