#include "QStatic.h"

QStatic::QStatic(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QEntity(environment, forestscene, lifeSpan, tree, type)
{

}


QStatic::~QStatic()
{

}

