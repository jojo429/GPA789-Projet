#include "QSimulation.h"

#include <QSplitter>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QGraphicsRectItem>
#include <QTimer>

QSimulation::QSimulation(QForestScene & forestScene, QEnvironment & environment, QWidget *parent)
	: QWidget(parent), mEnvironment { environment }, mForestScene { forestScene }
{

	

	mSimulationMenu = new QSimulationMenu;
	QHBoxLayout * mainLayout = new QHBoxLayout;


	mForestView = new QGraphicsView();
	mForestView->setRenderHint(QPainter::Antialiasing);
	mForestView->setScene(&forestScene);


	mainLayout->addWidget(mForestView);
	mainLayout->addWidget(mSimulationMenu);
	
	setLayout(mainLayout);
	connect(&mTimer, &QTimer::timeout, this, &QSimulation::generalAdvance);
	
	connect(mSimulationMenu, &QSimulationMenu::play, this, &QSimulation::play);
	connect(mSimulationMenu, &QSimulationMenu::pause, this, &QSimulation::pause);
	connect(mSimulationMenu, &QSimulationMenu::stop, this, &QSimulation::stop);
	connect(mSimulationMenu, &QSimulationMenu::step, this, &QSimulation::step);


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
	
	mSimulationMenu->getParameters(&mSimulationParameters);
	mEnvironment.setParameters(mSimulationParameters);

	mTimer.start(30);
}

void QSimulation::pause()
{

	mTimer.stop();
}

void QSimulation::stop()
{

	mTimer.stop();
}

void QSimulation::step()
{



}

void QSimulation::generalAdvance() 
{
	for (int i{ 0 }; i < mSimulationMenu->getTimeScaleValue(); i++) {
		mEnvironment.advance();
		mForestScene.advance();
		getStatistics();
	}
	advanceDone();
}