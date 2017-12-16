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
	QEntity(QEnvironment const &environment, QForestScene &forestscene, int lifeSpan);
	~QEntity();
	virtual void reproduce();
	virtual void die();
	virtual bool isItDead();
	virtual void striked();
	int getHeight();
	


protected:
	QPointF mPosition;
	int mLifeSpan;
	int mAge{0};
	bool mGotHit{ false };
	bool mIsDead{ false };
	int mTime{ 0 };
	QEnvironment const & mEnvironment;
	QForestScene & mForestScene;
	QPointF mCenter = QPointF(0, 0);
	QBrush mBrush;
	QPen mPen;
	int mHeight;
	void advanceTime();
};

#endif //Q_ENTITY_H

