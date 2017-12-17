#include "QDynamic.h"

QDynamic::QDynamic(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QEntity{ environment , forestscene, lifeSpan, tree, type }
{

}


QDynamic::~QDynamic()
{

}

void QDynamic::move()
{

}

