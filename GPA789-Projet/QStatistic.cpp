#include "QStatistic.h"


#include <QVBoxLayout>

QStatistic::QStatistic(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout * mainLayout = new QVBoxLayout;
	mTestGraph1 = new QEvolutionGraph;
	mTestGraph2 = new QEvolutionGraph;
	mainLayout->addWidget(mTestGraph1);
	mainLayout->addWidget(mTestGraph2);
	
	setLayout(mainLayout);


}

QStatistic::~QStatistic()
{
}

void QStatistic::updateData() 
{
		y++;
		mTestGraph1->addPoint(y);
}