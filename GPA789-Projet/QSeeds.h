#ifndef Q_SEEDS_H
#define Q_SEEDS_H

#include "QDynamic.h"
#include <vector>

class QSeeds : public QDynamic
{

public:
	QSeeds(QEnvironment const & environment);
	~QSeeds();
	void germinate();
	void die() override;
	void QSeeds::initialize(QEnvironment const & enviromnent);

private:
	int mHeight;
	int mWeight;
	std::array<std::vector<double>, 5> mWeightingGerminate;

	int mCountFallDown{ 0 };
	double mSeedRadius { 5.0 };
	QPointF mCenter = QPointF(0, 0);
	void move() override;
	QRectF QSeeds::boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = Q_NULLPTR);
	void QSeeds::advance(int phase);
};


#endif //Q_SEEDS_H

