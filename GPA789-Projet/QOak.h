// QOak.h
//
// Description:
// Classe contenant les données particulières à un arbre de type Chêne.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_OAK_H
#define Q_OAK_H

#include "QTrees.h"

class QOak : public QTrees
{

public:
	QOak(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type);
	~QOak()=default;

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

#endif //Q_OAK_H
