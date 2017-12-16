#ifndef Q_SEEDS_H
#define Q_SEEDS_H

#include "QDynamic.h"
#include "QTrees.h"
#include <vector>
#include <QPointF>




class QSeeds : public QDynamic
{

public:
	QSeeds(QEnvironment const & environment, QForestScene & forestscene, treeType value, int lifeSpan);
	~QSeeds();


	void germinate();
	void picked();
	void droped( QPointF coordinate );
	void setCarried(bool status);

	friend class QForestScene;


private:
	int mWeight;
	bool mCarriedBySquirrel{false};
	std::array<std::vector<double>, 5> mWeightingGerminate;
	double mMovingFactor;
	int mCountFallDown{ 0 };

	double mSeedRadius { 5.0 };
	QPointF mCenter = QPointF(0, 0);
	void move() override;
	QRectF boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = Q_NULLPTR)override;
	void advance(int phase) override;
	treeType mTreeType;
	int mGerminated{ false };
	static GaussianTable mPrecipitationGrowFactor;
	static GaussianTable mLuminosityGrowFactor;
	static GaussianTable mTemperatureGrowFactor;
	RandomUniform mGenerateTree;
	RandomUniform mGenerateAngle;
};


#endif //Q_SEEDS_H

