#ifndef Q_FIR_H
#define Q_FIR_H

#include "QTrees.h"

class QFir : public QTrees
{

public:
	QFir(QEnvironment const & environment);
	~QFir();
	void grow();

//protected:
//	static GaussianTable mPrecipitationGrowFactor;
//	static GaussianTable mLuminosityGrowFactor;
//	static GaussianTable mTemperatureGrowFactor;


private:
	QColor mLeafColor;
	QColor mTrunkColor;
	std::array<std::vector<double>, 5> mWeightingGrow;
	std::array<std::vector<double>, 5> mWeightingDryness;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

	//void advance(int phase);
};

//GaussianTable QFir::mPrecipitationGrowFactor(28, 6, 25);
//GaussianTable QFir::mLuminosityGrowFactor(200, 50, 10000, -100);
//GaussianTable QFir::mTemperatureGrowFactor(150, 30, 1000, -75);

#endif //Q_FIR_H
