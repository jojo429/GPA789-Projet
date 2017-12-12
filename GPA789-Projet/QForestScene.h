#ifndef Q_FOREST_SCENE_H
#define Q_FOREST_SCENE_H

#include <QGraphicsScene>
#include <QPointF>
#include "QEnvironment.h"
#include <QBrush>
#include <QColor>
#include "QOak.h"
#include "QHazel.h"
#include "QBirch.h"
#include "QFir.h"

class QForestScene : public QGraphicsScene
{
	Q_OBJECT

public:
	QForestScene(QEnvironment const & enviromnent, QGraphicsScene * parent = Q_NULLPTR);
	~QForestScene();




private:
	QOak mMasterOak;
	QBirch mMasterBirch;
	QHazel mMasterHazel;
	QFir mMasterFir;
	void closestTree(QPointF pt2D);
	void lightningStrike(QPointF pt2D);
	QBrush mBackgroundBrush{ QColor(239, 247, 153) };
};

#endif //Q_FOREST_SCENE_H

