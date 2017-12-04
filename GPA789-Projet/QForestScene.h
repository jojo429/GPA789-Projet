#ifndef Q_FOREST_SCENE_H
#define Q_FOREST_SCENE_H

#include <QGraphicsScene>
#include <QPointF>
#include "QEnvironment.h"
/*class QOak;
class QBirch;
class QHazel;
class QFir;*/

class QForestScene : public QGraphicsScene
{
	Q_OBJECT

public:
	QForestScene(QGraphicsScene * parent = Q_NULLPTR);
	~QForestScene();
	/*QOak const & mMasterOak;
	QBirch const & mMasterBirch;
	QHazel const & mMasterHazel;
	QFir const & mMasterFir;*/

	void initialize( QEnvironment const & enviromnent);

private:
	void closestTree(QPointF pt2D);
	void lightningStrike(QPointF pt2D);
};

#endif //Q_FOREST_SCENE_H

