#ifndef Q_ENTITY_H
#define Q_ENTITY_H


#include "QEnvironment.h"
#include <QGraphicsItem>
#include <QPointF>

class QEntity : public QGraphicsItem
{

public:
	QEntity(QEnvironment const &environment);
	~QEntity();
	virtual void reproduce();
	virtual void die();
	virtual void striked();

private:
	QPointF mPosition;
	int mLifeSpan;
	int mAge;
	bool mGotHit;
	QEnvironment const & mEnvironment;

};

#endif //Q_ENTITY_H

