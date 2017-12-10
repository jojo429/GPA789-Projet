#ifndef Q_SIMULATION_H
#define Q_SIMULATION_H

#include <QWidget>
#include "QForestScene.h"
#include "QEnvironment.h"
#include <QTimer>
#include "SimulationParameters.h"
#include "QSimulationMenu.h"

class QSimulation : public QWidget
{
	Q_OBJECT

public:
	QSimulation(QForestScene & forestScene, QEnvironment & environment, QWidget *parent = Q_NULLPTR);
	~QSimulation();

signals:
	void timerTimeout();

public slots:
	void Play();
	void Pause();
	void Stop();
	void Step();

private:
	QTimer mTimer{ this };
	QEnvironment  & mEnvironment;
	SimulationParameters mSimulationParameters;
	QSimulationMenu *mSimulationMenu;
	
};
#endif //Q_SIMULATION_H