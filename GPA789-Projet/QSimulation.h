#ifndef Q_SIMULATION_H
#define Q_SIMULATION_H

#include <QWidget>
#include "QForestScene.h"

class QSimulation : public QWidget
{
	Q_OBJECT

public:
	QSimulation(QForestScene & forestScene, QWidget *parent = Q_NULLPTR);
	~QSimulation();
};
#endif //Q_SIMULATION_H