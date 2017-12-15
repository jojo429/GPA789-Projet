#ifndef Q_OAK_H
#define Q_OAK_H

#include "QTrees.h"

class QOak : public QTrees
{

public:
	QOak(QEnvironment const & environment, QForestScene & forestscene, treeType value);
	~QOak();
	void grow();

	


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

#endif //Q_OAK_H
