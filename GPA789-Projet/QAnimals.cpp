#include "QAnimals.h"

QAnimals::QAnimals(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan)
	: QDynamic{ environment , forestscene, lifeSpan }
{

}

QAnimals::~QAnimals()
{

}
