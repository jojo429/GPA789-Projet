#ifndef Q_SEEDS_H
#define Q_SEEDS_H

#include "QDynamic.h"
#include "QTrees.h"
#include <vector>
#include <QPointF>


class QSeeds : public QDynamic
{

public:
	QSeeds(QEnvironment const & environment, QForestScene & forestscene, treeType value);
	~QSeeds();

	friend QForestScene;
	void germinate();
	void die() override;
	bool isItDead() override;
	void picked();
	void droped( QPointF coordinate );

private:
	int mHeight;
	int mWeight;
	std::array<std::vector<double>, 5> mWeightingGerminate;

	double mMovingFactor;
	int mCountFallDown{ 0 };
	double mSeedRadius { 5.0 };
	QPointF mCenter = QPointF(0, 0);
	void move() override;
	QRectF QSeeds::boundingRect() const;
	void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = Q_NULLPTR);
	void QSeeds::advance(int phase);
	treeType mTreeType;


};


#endif //Q_SEEDS_H

