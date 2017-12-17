// QForestScene.h
//
// Description:
// Classe principale héritant de QGraphicsScene et contrôlant les entités de la simulation.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

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
	QForestScene(QEnvironment & enviromnent, QGraphicsScene * parent = Q_NULLPTR);
	~QForestScene()=default;

	void createSeed(QTrees* parent);
	void createTree(QSeeds* parent);
	void setParameters(SimulationParameters &simulationParameters);
	void setStatistic(SimulationStatistics *simulationStatistics);
	void windAngle(int windAngle);
	int mWindAngle{ 0 };
	void destroyDeadEntities();

private:
	QBrush mBackgroundBrush{ QColor(239, 247, 153) };
	RandomUniform mGenerate;
	RandomUniform mGenerateCoordinate;
	QEnvironment & mEnvironment;
	SimulationStatistics * mSimulationStatistics;
	RandomUniform mGenerateLongLifespan;
	RandomUniform mGenerateShortLifespan;
	QList <QEntity*> mEntities;

};

#endif //Q_FOREST_SCENE_H

