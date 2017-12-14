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

	QTrees(QEnvironment const & environment);
	~QTrees();

	virtual void grow();
	void reproduce() override;
	void die() override;
	int getHeight();
	void adjustDryness();
	void setOnFire();
	void striked() override;
	void setMasterTree(QTrees * tree);
	


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
	

};


#endif //Q_TREES_H
