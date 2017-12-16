#ifndef Q_BIRCH_H
#define Q_BIRCH_H

#include "QTrees.h"

class QBirch : public QTrees
{

public:
	QBirch(QEnvironment const & environment, QForestScene & forestscene, treeType tree, int lifeSpan, generalType type);
	~QBirch();

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

#endif //Q_BIRCH_H
