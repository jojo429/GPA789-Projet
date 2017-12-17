// QHazel.h
//
// Description:
// Classe contenant les données particulières à un arbre de type Noisettier.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_HAZEL_H
#define Q_HAZEL_H

#include "QTrees.h"

class QHazel : public QTrees
{

public:
	QHazel(QEnvironment const & environment, QForestScene & forestscene,  int lifeSpan, treeType tree, generalType type);
	~QHazel()=default;

	GaussianTable & growTable() override;
	GaussianTable & precipirationGrowFactorTable() override;
	GaussianTable & luminosityGrowFactorTable() override;
	GaussianTable & temperatureGrowFactorTable() override;
	
private:
	QColor mLeafColor;
	QColor mTrunkColor;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) override;
	static GaussianTable mPrecipitationGrowFactor;
	static GaussianTable mLuminosityGrowFactor;
	static GaussianTable mTemperatureGrowFactor;
	static GaussianTable mGrowTable;

};

#endif //Q_HAZEL_H
