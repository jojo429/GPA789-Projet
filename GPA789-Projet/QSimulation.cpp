// QSimulation.cpp
//
// Description:
// Classe g�rant le d�roulement de la simulation.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#include "QSimulation.h"
#include <QSplitter>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QDebug>
#include <QPointF>
#include <QSizePolicy>


QSimulation::QSimulation(QForestScene & forestScene, QEnvironment & environment, QWidget *parent)
	: QWidget(parent), mEnvironment { environment }, mForestScene { forestScene }
{
	// Envoie le fichier statistique � la For�t
	mForestScene.setStatistic(& mSimulationStatistics);

	// Cr�e les �l�ments visuels de la simulation
	mSimulationMenu = new QSimulationMenu;
	QHBoxLayout * mainLayout = new QHBoxLayout;
	mForestView = new QGraphicsView();
	mForestView->setRenderHint(QPainter::Antialiasing);
	//mForestView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
	mForestView->setCacheMode(QGraphicsView::CacheBackground);
	mForestView->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing);
	mForestView->setDragMode(QGraphicsView::ScrollHandDrag);
	mForestView->setScene(&forestScene);

	//D�finir une taille minimale pour mForestView
	mForestView->setMinimumWidth(800);

	//Ajuster la proportion de la fen�tre de simulation
	QSizePolicy spLeft(QSizePolicy::Preferred, QSizePolicy::Preferred);
	spLeft.setHorizontalStretch(3);
	mForestView->setSizePolicy(spLeft);
	QSizePolicy spRight(QSizePolicy::Preferred, QSizePolicy::Preferred);
	spRight.setHorizontalStretch(1);
	mSimulationMenu->setSizePolicy(spRight);
	mainLayout->addWidget(mForestView);
	mainLayout->addWidget(mSimulationMenu);
	setLayout(mainLayout);

	// Connections requises pour la simulation
	connect(&mTimer, &QTimer::timeout, this, &QSimulation::genAdvance);
	connect(mSimulationMenu, &QSimulationMenu::play, this, &QSimulation::play);
	connect(mSimulationMenu, &QSimulationMenu::pause, this, &QSimulation::pause);
	connect(mSimulationMenu, &QSimulationMenu::stop, this, &QSimulation::stop);
	connect(mSimulationMenu, &QSimulationMenu::step, this, &QSimulation::step);
	connect(this, &QSimulation::updateAdvanceCount, mSimulationMenu, &QSimulationMenu::setAdvanceCounter);
	connect(mSimulationMenu, &QSimulationMenu::windAngle, &mForestScene, &QForestScene::windAngle);
}

void QSimulation::getStatistics()
{
	// R�cup�re les statistiques de l'environment et les envoie 
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
			mZoomLimit++;
		}
		else if(mZoomLimit >= -3){
			// Zooming out
			mForestView->scale(1.0 / scaleFactor, 1.0 / scaleFactor);
			mZoomLimit--;
		}
}

void QSimulation::play()
{
	if (!mStarted)
	{
		// Si la simulation viens de commencer on d�fini les param�tres de la simulation
		mSimulationMenu->getParameters(&mSimulationParameters);
		mEnvironment.setParameters(mSimulationParameters);
		mForestScene.setParameters(mSimulationParameters);
		mStarted = true;
	}
	
	// D�part du timer de la simulation
	mTimer.start(30);
}

void QSimulation::pause()
{
	// Arr�t du timer de la simulation
	mTimer.stop();
}

void QSimulation::stop()
{
	// Arr�t du timer de la simulation
	mTimer.stop();
	// Remise � 0 du compteur et des param�tres de simulations
	mAdvanceCounter = 0;
	emit updateAdvanceCount(mAdvanceCounter);
	mStarted = false;
	// Suppression des items contenus dans la sc�ne
	mForestScene.clear();
	// Recalcul de la fertilit� pour la prochaine simulation
	QPixmap fertilityPixmap = (mEnvironment.mFertility).getFertilityPixmap();
	mEnvironment.mFertility.setFertility(10.0, 100.0);
	mForestScene.setBackgroundBrush(QBrush(fertilityPixmap.scaled(2052, 2052, Qt::KeepAspectRatio)));
}

void QSimulation::step()
{
	if (!mStarted)
	{
		// Si la simulation viens de commencer on d�fini les param�tres de la simulation
		mSimulationMenu->getParameters(&mSimulationParameters);
		mEnvironment.setParameters(mSimulationParameters);
		mForestScene.setParameters(mSimulationParameters);
		mStarted = true;
	}
	// Envoie de 1 advance
	this->generalAdvance(true);

}

void QSimulation::generalAdvance(bool oneStep) 
{

	static bool working{ false };
	if (!working) {
		working = true;

		// Regarde le nombre de advance que la simulation doit faire
		int stepCount = 0;
		if (oneStep)
		{
			stepCount = 1;
		}
		else
		{
			stepCount = mSimulationMenu->getTimeScaleValue();
		}

		// Pas d'affichage durant les calculs
		mForestView->setViewportUpdateMode(QGraphicsView::NoViewportUpdate);
		QElapsedTimer timer;
		timer.start();
		for (int i{ 0 }; i < stepCount; i++) {
			
			// Calcul des facteurs environmentaux
			mEnvironment.advance();
			// D�placement et croissance des entit�s
			mForestScene.advance();
			// Mise � jour des statistiques
			getStatistics();
			// Mise � jour du compteur de Advance
			mAdvanceCounter++;
			emit updateAdvanceCount(mAdvanceCounter);
		}
		ticTime(timer.elapsed());
		// Suppression des entit�s mortes
		mForestScene.destroyDeadEntities();
		// Affichage de la sc�ne
		mForestView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
		advanceDone();
		working = false;

	}
}

void QSimulation::genAdvance()
{
	this->generalAdvance(false);
}

