#include "QStatistic.h"


#include <QVBoxLayout>

QStatistic::QStatistic(QWidget *parent)
	: QWidget(parent)
{
	QVBoxLayout * mainLayout = new QVBoxLayout;
	mTestGraph1 = new QEvolutionGraph;
	mRainGraph = new QEvolutionGraph;
	mRainGraph->initializeGraph("Time","Rain level (mm)","Rain level graphic");
	mainLayout->addWidget(mTestGraph1);
	mainLayout->addWidget(mRainGraph);
	
	setLayout(mainLayout);


}

QStatistic::~QStatistic()
{
}

void QStatistic::updateData() 
{
		y++;
		mRainGraph->addPoint(y);
}