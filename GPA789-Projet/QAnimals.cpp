#include "QAnimals.h"

QAnimals::QAnimals(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type)
	: QDynamic{ environment , forestscene, lifeSpan, tree, type }
{

}

QAnimals::~QAnimals()
{

}
