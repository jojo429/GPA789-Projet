#include "QAnimals.h"

QAnimals::QAnimals(QEnvironment const & environment, QForestScene & forestscene)
	: QDynamic{ environment , forestscene}
{

}

QAnimals::~QAnimals()
{

}
