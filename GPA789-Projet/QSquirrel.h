#ifndef Q_SQUIRREL_H
#define Q_SQUIRREL_H

#include "QAnimals.h"
#include <list>
#include <QColor>


class QSquirrel : public QAnimals
{

public:
	QSquirrel(QEnvironment const & environment);
	~QSquirrel();
	enum TargetType {
		NoTarget = 0,
		Trees = 1,
		Squirrel = 2,
		Seeds = 3
	};

private:

	TargetType mTargetType{NoTarget};
	QGraphicsItem * mTarget{ Q_NULLPTR };
	QGraphicsItem * mLastTarget{ Q_NULLPTR };
	int mActionCounter{0};
	QPointF mTargetPos;
	QPointF mTriangle[3] = { QPointF(0, -15), QPointF(7, 0), QPointF(-7, 0) };
	QColor mFurColor{204, 144, 24};
	QColor mTailColor{ 232, 157, 6 };
	double mVisionRadius{100};
	int mHunger{100};
	int actionCounter{0};
	void move() override;
	QGraphicsItem* getTarget();
	void reproduce(int age);
	void die(int age);
	void eat();
	void pickSeed();
	void striked() override;
	void setRotationAdjustment();
	std::list<QSeeds*> mSeeds;	
	void advance(int phase);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

};

#endif //Q_SQUIRREL_H