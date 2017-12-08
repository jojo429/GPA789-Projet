#ifndef Q_ENTITY_H
#define Q_ENTITY_H


#include "QEnvironment.h"
#include <QGraphicsItem>
#include <QPointF>
#include <QBrush>
#include <QPen>

class QEntity : public QGraphicsItem
{

public:
	QEntity(QEnvironment const &environment);
	~QEntity();
	virtual void reproduce();
	virtual void die();
	virtual void striked();

protected:
	QPointF mPosition;
	int mLifeSpan;
	int mAge{0};
	bool mGotHit;
	QEnvironment const & mEnvironment;
	QPointF mCenter = QPointF(0, 0);
	QBrush mBrush;
	QPen mPen;

};

#endif //Q_ENTITY_H

