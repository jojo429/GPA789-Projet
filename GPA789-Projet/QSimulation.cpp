#include "QSimulation.h"

#include <QSplitter>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
#include <QPointF>


QSimulation::QSimulation(QForestScene & forestScene, QEnvironment & environment, QWidget *parent)
	: QWidget(parent), mEnvironment { environment }, mForestScene { forestScene }
{

	mForestScene.setStatistic(& mSimulationStatistics);
	mSimulationMenu = new QSimulationMenu;
	QHBoxLayout * mainLayout = new QHBoxLayout;


	mForestView = new QGraphicsView();
	mForestView->setRenderHint(QPainter::Antialiasing);
	//mForestView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
	mForestView->setCacheMode(QGraphicsView::CacheBackground);
	mForestView->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing);
	mForestView->setDragMode(QGraphicsView::ScrollHandDrag);
	mForestView->setScene(&forestScene);


	mainLayout->addWidget(mForestView);
	mainLayout->addWidget(mSimulationMenu);
	
	setLayout(mainLayout);

	connect(&mTimer, &QTimer::timeout, this, &QSimulation::genAdvance);
	
	connect(mSimulationMenu, &QSimulationMenu::play, this, &QSimulation::play);
	connect(mSimulationMenu, &QSimulationMenu::pause, this, &QSimulation::pause);
	connect(mSimulationMenu, &QSimulationMenu::stop, this, &QSimulation::stop);
	connect(mSimulationMenu, &QSimulationMenu::step, this, &QSimulation::step);
	
	connect(this, &QSimulation::updateAdvanceCount, mSimulationMenu, &QSimulationMenu::setAdvanceCounter);
	connect(mSimulationMenu, &QSimulationMenu::windAngle, &mForestScene, &QForestScene::windAngle);
}

QSimulation::~QSimulation()
{
	
}

void QSimulation::getStatistics()
{
	mEnvironment.getStatistics(&mSimulationStatistics);

	emit sendStatistics(mSimulationStatistics);
}

void QSimulation::wheelEvent(QWheelEvent* event)
{
	mForestView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	// Scale the view / do the zoom
	double scaleFactor = 1.15;
	if (event->delta() > 0) {
		// Zoom in
		mForestView->scale(scaleFactor, scaleFactor);

	}
	else {
		// Zooming out
		mForestView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
	}

}

void QSimulation::play()
{
	if (!mStarted)
	{
		mSimulationMenu->getParameters(&mSimulationParameters);
		mEnvironment.setParameters(mSimulationParameters);
		mForestScene.setParameters(mSimulationParameters);
		mStarted = true;
	}
	

	mTimer.start(30);
}

void QSimulation::pause()
{

	mTimer.stop();
}

void QSimulation::stop()
{

	mTimer.stop();
	mAdvanceCounter = 0;
	emit updateAdvanceCount(mAdvanceCounter);
	mStarted = false;
	mForestScene.clear();
}

void QSimulation::step()
{

	this->generalAdvance(true);

}

void QSimulation::generalAdvance(bool oneStep) 
{

	static bool working{ false };
	if (!working) {
		working = true;

		int stepCount = 0;
		
		if (oneStep)
		{
			stepCount = 1;
		}
		else
		{
			stepCount = mSimulationMenu->getTimeScaleValue();
		}
		mForestView->setViewportUpdateMode(QGraphicsView::NoViewportUpdate);
		QElapsedTimer timer;
		timer.start();
		for (int i{ 0 }; i < stepCount; i++) {
			
			mEnvironment.advance();
			mForestScene.advance();
			getStatistics();
			mAdvanceCounter++;
			emit updateAdvanceCount(mAdvanceCounter);
		}
		ticTime(timer.elapsed());
		mForestView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
		advanceDone();
		working = false;

	}
}

void QSimulation::genAdvance()
{
	this->generalAdvance(false);
}

