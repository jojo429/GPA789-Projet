#ifndef Q_FOREST_SCENE_H
#define Q_FOREST_SCENE_H

#include <QGraphicsScene>
#include <QPointF>
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

private:
	void closestTree(QPointF pt2D);
	void lightningStrike(QPointF pt2D);
};

#endif //Q_FOREST_SCENE_H

