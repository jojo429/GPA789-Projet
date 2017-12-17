#ifndef Q_STATIC_H
#define Q_STATIC_H

#include "QEntity.h"

class QStatic : public QEntity
{

public:
	QStatic(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type);
	virtual ~QStatic();

};
#endif //Q_STATIC_H

