#ifndef Q_TREES_H
#define Q_TREES_H

#include "QStatic.h"

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

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
	void advance(int phase);

private:
	double mHeight;
	double mTrunkRadius;
	double mLeafRadius;
	int mDryness;
	enum mState {isAlive, isDead, isOnFire};
	bool mGotHit;
	QTrees *mMasterTree;

};


#endif //Q_TREES_H
