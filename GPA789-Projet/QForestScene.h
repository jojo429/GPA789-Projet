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
#include "RandomUniform.h"

class QForestScene : public QGraphicsScene
{
	Q_OBJECT

public:
	QForestScene(QEnvironment const & enviromnent, QGraphicsScene * parent = Q_NULLPTR);
	~QForestScene();
	void createSeed(QTrees* parent);
	void setParameters(SimulationParameters &simulationParameters);

protected:


private:

	void closestTree(QPointF pt2D);
	void lightningStrike(QPointF pt2D);
	QBrush mBackgroundBrush{ QColor(239, 247, 153) };
	RandomUniform mGenerate;
	QEnvironment const & mEnvironment;
	/*QOak mMasterOak;
	QBirch mMasterBirch;
	QHazel mMasterHazel;
	QFir mMasterFir;*/
};

#endif //Q_FOREST_SCENE_H

