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

	QTrees(QEnvironment const & environment, QForestScene & forestscene, treeType value, int lifeSpan);
	~QTrees();

	
	void reproduce() override;
	void die() override;
	int getHeight();
	int getRadius();
	void adjustDryness();
	void setOnFire();
	void grow();
	void striked() override;
	treeType mTreeType;
	virtual GaussianTable growTable()=0;
	virtual GaussianTable precipirationGrowFactorTable()=0;
	virtual GaussianTable luminosityGrowFactorTable()=0;
	virtual GaussianTable temperatureGrowFactorTable()=0;



protected:
	QColor mLeafColor;
	QColor mTrunkColor;
	double mHeight;
	double mTrunkRadius;
	double mLeafRadius;
	int mDryness;
	enum mState {isAlive, isDead, isOnFire};
	bool mGotHit;
	void advance(int phase);
	QRectF boundingRect() const;
	
	GaussianTable mEmpty;

	static GaussianTable mReproduceTable;
	RandomUniform mGenerateSeed;
	

};


#endif //Q_TREES_H
