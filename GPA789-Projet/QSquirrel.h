#ifndef Q_SQUIRREL_H
#define Q_SQUIRREL_H

#include "QAnimals.h"
#include <list>
#include <QColor>

class QSquirrel : public QAnimals
{

public:
	QSquirrel(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan);
	~QSquirrel();
	enum TargetType {
		NoTarget = 0,
		Trees = 1,
		Squirrel = 2,
		Seed = 3
	};

private:

	TargetType mTargetType{NoTarget};
	QGraphicsItem * mTarget{ Q_NULLPTR };
	int mActionCounter{0};
	QPointF mTargetPos;
	QPointF mTriangle[3] = { QPointF(15, 0), QPointF(0, 7), QPointF(0, -7) };
	QColor mFurColor{204, 144, 24};
	QColor mTailColor{ 232, 157, 6 };
	double mVisionRadius{200};
	int mHunger{100};
	int actionCounter{0};
	QList<QGraphicsItem*> mPastTarget;
	RandomUniform mGenerateAngle;
	QList<QGraphicsItem*> mSeeds;
	const int mSeedsLimit{ 4 };
	const int mPastTargetLimit{ 10 };

	QGraphicsItem* getTarget();
	QList<QGraphicsItem*> compareTargetList(QList<QGraphicsItem*> &newTarget);
	void pickSeed();

	void dropSeed();

	void move() override;
	void setRotationAdjustment();
	qreal getTargetDistance();
	void advance(int phase) override;
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR)override;

};

#endif //Q_SQUIRREL_H