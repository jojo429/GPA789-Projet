#ifndef Q_SIMULATION_H
#define Q_SIMULATION_H

#include <QWidget>
#include "QForestScene.h"
#include "QEnvironment.h"
#include <QTimer>
#include "SimulationParameters.h"
#include "SimulationStatistics.h"
#include "QSimulationMenu.h"
#include <QWheelEvent>

class QSimulation : public QWidget
{
	Q_OBJECT

public:
	QSimulation(QForestScene & forestScene, QEnvironment & environment, QWidget *parent = Q_NULLPTR);
	~QSimulation();
	//ICI advance counter //int getAdvanceCounter();

signals:
	 void sendStatistics(SimulationStatistics stats);
	 void advanceDone();
	 void updateAdvanceCount(int advanceCount);

public slots:
	void play();
	void pause();
	void stop();
	void step();
	void getStatistics();

private slots: 
	void genAdvance();	
	void generalAdvance(bool oneStep);

private:
	QTimer mTimer{ this };
	QEnvironment  & mEnvironment;
	QForestScene & mForestScene;
	SimulationParameters mSimulationParameters;
	SimulationStatistics mSimulationStatistics;
	QSimulationMenu *mSimulationMenu;
	QGraphicsView *mForestView;

	int mAdvanceCounter=0;
	bool mStarted = false;

protected:
	virtual void wheelEvent(QWheelEvent* event);
};
#endif //Q_SIMULATION_H