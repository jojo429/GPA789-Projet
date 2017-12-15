#ifndef Q_ENTITY_H
#define Q_ENTITY_H


#include "QEnvironment.h"
#include <QGraphicsItem>
#include <QPointF>
#include <QBrush>
#include <QPen>
#include <QList>
class QForestScene;

enum treeType { Oak, Fir, Hazel, Birch };

class QEntity : public QGraphicsItem
{

public:
	QEntity(QEnvironment const &environment, QForestScene &forestscene);
	~QEntity();
	virtual void reproduce();
	virtual void die();
	virtual bool isItDead();
	virtual void striked();

protected:
	//QList<QGraphicsItem> mInRangeItems; !?!?!?!?!?!?!?!?!
	QPointF mPosition;
	int mLifeSpan;
	int mAge{0};
	bool mGotHit;
	QEnvironment const & mEnvironment;
	QForestScene & mForestScene;
	QPointF mCenter = QPointF(0, 0);
	QBrush mBrush;
	QPen mPen;

};

#endif //Q_ENTITY_H

