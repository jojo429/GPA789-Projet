#ifndef Q_STATISTIC_H
#define Q_STATISTIC_H

#include "QEvolutionGraph.h"

#include <QWidget>


class QStatistic : public QWidget
{
	Q_OBJECT

public:
	QStatistic(QWidget *parent = Q_NULLPTR);
	~QStatistic();

public slots:
	void updateData();

private: 
	QEvolutionGraph * mTestGraph1;
	QEvolutionGraph * mRainGraph;
	//TEST/////
	long int x{ 0 }, y{ 0 };
	///////////
};
#endif //Q_STATISTIC_H