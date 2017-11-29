#ifndef Q_SIMULATION_H
#define Q_SIMULATION_H

#include <QWidget>

class QSimulation : public QWidget
{
	Q_OBJECT

public:
	QSimulation(QWidget *parent = Q_NULLPTR);
	~QSimulation();
};
#endif //Q_SIMULATION_H