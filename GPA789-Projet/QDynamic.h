#ifndef Q_DYNAMIC_H
#define Q_DYNAMIC_H

#include "QEntity.h"
#include "QEnvironment.h"

class QDynamic : public QEntity
{

public:
	QDynamic(QEnvironment const & environment);
	~QDynamic();
	virtual void move();

};

#endif //Q_DYNAMIC_H

