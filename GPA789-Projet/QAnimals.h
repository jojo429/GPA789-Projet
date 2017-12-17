#ifndef Q_ANIMALS_H
#define Q_ANIMALS_H

#include "QDynamic.h"

class QAnimals : public QDynamic
{

public:
	QAnimals(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type);
	virtual ~QAnimals();

};

#endif //Q_ANIMALS_H

