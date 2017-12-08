#ifndef Q_SIMULATION_H
#define Q_SIMULATION_H

#include <QWidget>
#include "QForestScene.h"
#include "QEnvironment.h"
#include <QTimer>

class QSimulation : public QWidget
{
	Q_OBJECT

public:
	QSimulation(QForestScene & forestScene, QEnvironment & environment, QWidget *parent = Q_NULLPTR);
	~QSimulation();

public slots:
	void Play();
	void Pause();
	void Stop();
	void Step();

private:
	QTimer mTimer{this};
	QEnvironment  & mEnvironment;

};
#endif //Q_SIMULATION_H