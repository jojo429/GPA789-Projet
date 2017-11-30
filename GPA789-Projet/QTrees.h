#ifndef Q_TREES_H
#define Q_TREES_H

#include "QStatic.h"

class QTrees : public QStatic
{

public:
	QTrees();
	~QTrees();

	virtual void grow(int luminosity, int fertility, int age);
	void reproduce() override;
	void die() override;
	int getHeight();
	void adjustDryness(bool isRaining);
	void setOnFire(bool gotHit, int dryness);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
	void advance(int phase);


private:
	int mHeight;
	int mTrunkRadius;
	int mLeafRadius;
	int mDryness;
	bool mGotHit;



};

#endif //Q_TREES_H
