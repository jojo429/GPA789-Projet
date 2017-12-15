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
	void createTree(QSeeds* parent);
	void setParameters(SimulationParameters &simulationParameters);
	void setStatistic(SimulationStatistics *simulationStatistics);
	void windAngle(int windAngle);
	int mWindAngle{ 0 };

protected:


private:

	void closestTree(QPointF pt2D);
	void lightningStrike(QPointF pt2D);
	QBrush mBackgroundBrush{ QColor(239, 247, 153) };
	RandomUniform mGenerate;
	RandomUniform mGenerateCoordinate;
	QEnvironment const & mEnvironment;
	SimulationStatistics * mSimulationStatistics;
	


};

#endif //Q_FOREST_SCENE_H

