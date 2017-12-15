#ifndef Q_TREES_H
#define Q_TREES_H

#include "QStatic.h"
#include <QBrush>
#include <QPen>
#include <QColor>
#include "GaussianTable.h"



class QTrees : public QStatic
{
	
public:

	QTrees(QEnvironment const & environment, QForestScene & forestscene, treeType value);
	~QTrees();

	
	void reproduce() override;
	void die() override;
	int getHeight();
	int getRadius();
	void adjustDryness();
	void setOnFire();
	void striked() override;
	void setMasterTree(QTrees * tree);
	treeType mTreeType;



protected:
	QColor mLeafColor;
	QColor mTrunkColor;
	double mHeight;
	double mTrunkRadius;
	double mLeafRadius;
	int mDryness;
	enum mState {isAlive, isDead, isOnFire};
	bool mGotHit;
	QTrees *mMasterTree;
	void advance(int phase);
	QRectF boundingRect() const;
	int mTime{ 0 };
	static GaussianTable mPrecipitationGrowFactor;
	static GaussianTable mLuminosityGrowFactor;
	static GaussianTable mTemperatureGrowFactor;
	static GaussianTable mGrowTable;
	static GaussianTable mReproduceTable;
	RandomUniform mGenerateSeed;
	

};


#endif //Q_TREES_H
