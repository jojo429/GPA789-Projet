// QSeeds.h
//
// Description:
// Classe g�rant la cr�ation et le comportement d'une entit� de type semence d'arbre.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#ifndef Q_SEEDS_H
#define Q_SEEDS_H

#include "QDynamic.h"
#include "QTrees.h"
#include <vector>
#include <QPointF>

class QSeeds : public QDynamic
{

public:
	QSeeds(QEnvironment const & environment, QForestScene & forestscene,  int lifeSpan, treeType tree, generalType type,  int height=0);
	~QSeeds()=default;

	void germinate();
	void picked();
	void droped( QPointF coordinate );
	void setCarried(bool status);

private:
	bool mCarriedBySquirrel{false};
	std::array<std::vector<double>, 5> mWeightingGerminate;
	double mMovingFactor;
	double mSeedRadius { 5.0 };
	QPointF mCenter = QPointF(0, 0);
	void move() override;
	QRectF boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = Q_NULLPTR)override;
	void advance(int phase) override;
	int mGerminated{ false };
	static GaussianTable mPrecipitationGrowFactor;
	static GaussianTable mLuminosityGrowFactor;
	static GaussianTable mTemperatureGrowFactor;
	RandomUniform mGenerateTree;
	RandomUniform mGenerateAngle;

};

#endif //Q_SEEDS_H

