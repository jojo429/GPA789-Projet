#ifndef Q_BIRCH_H
#define Q_BIRCH_H

#include "QTrees.h"

class QBirch : public QTrees
{

public:
	QBirch(QEnvironment const & environment, QForestScene & forestscene, treeType value, int lifeSpan);
	~QBirch();

	GaussianTable & growTable();
	GaussianTable & precipirationGrowFactorTable();
	GaussianTable & luminosityGrowFactorTable();
	GaussianTable & temperatureGrowFactorTable();

private:
	QColor mLeafColor;
	QColor mTrunkColor;
	std::array<std::vector<double>, 5> mWeightingGrow;
	std::array<std::vector<double>, 5> mWeightingDryness;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
	static GaussianTable mPrecipitationGrowFactor;
	static GaussianTable mLuminosityGrowFactor;
	static GaussianTable mTemperatureGrowFactor;
	static GaussianTable mGrowTable;
	//void advance(int phase);
};

#endif //Q_BIRCH_H
