// QEvoluationGraph.h
//
// Description:
// Widget gérant les graphiques affichant les statistiques de la simulation.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_EVOLUTION_GRAPH_H
#define Q_EVOLUTION_GRAPH_H

#include <QtWidgets>
#include <QtCharts>
using namespace QtCharts;
#include <QVector>

class QEvolutionGraph : public QWidget
{
	Q_OBJECT

public:
	QEvolutionGraph(size_t nSeries = 1, QWidget *parent = Q_NULLPTR);
	~QEvolutionGraph()=default;

	//Permet d'ajouter un point à une série de donnée
	void addPoint(size_t index, qreal t, qreal value);
	//Permet de ronnomer les axes ainsi que le titre du graphique
	void initializeGraph(QString xAxisName, QString yAxisName, QString graphTitle);
	//Permet de mettre les axes du graphique à jour
	void updateAxis();
	//Permet de rendre visible ou de cacher une série de donnée
	void setDataSerieVisibility(int index, bool setVisible);

private:

	QChart * mChart;
	QChartView * mChartView;
	QVector<QLineSeries*> mDataSeries;
	QValueAxis * mXAxis;
	QValueAxis * mYAxis;
	qreal mXmin{ 0 }, mYmin{ 0 };
	qreal mXmax{ 1 }, mYmax{ 1 };
	QVector<qreal> mYMaxEachSeries;
	QVector<qreal> mYMinEachSeries;
	size_t mNSeries;

	QWidget* initializeTimeScale();
	void updateMinMaxValues(size_t index, int count);

	QRadioButton * mScaleOneWeek;
	QRadioButton * mScaleOneMonth;
	QRadioButton * mScaleFiveMonths;
	QRadioButton * mScaleOneYear;
	QRadioButton * mScaleTwoYears;
	QRadioButton * mScaleFiveYears;
	QRadioButton * mScaleTenYears;
	QRadioButton * mScaleHundredYears;

	int mMaxNbData;
	int mNbDataVisible;
	int mNbAdvanceInOneDay;
	int mNbAdvanceInOneWeek;
	int mNbAdvanceInOneMonth;
	int mNbAdvanceInOneYear;

private slots:
	void setScaleOneWeek();
	void setScaleOneMonth();
	void setScaleFiveMonths();
	void setScaleOneYear();
	void setScaleTwoYears();
	void setScaleFiveYears();
	void setScaleTenYears();
	void setScaleHundredYears();

};

#endif