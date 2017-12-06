#ifndef Q_BIRCH_H
#define Q_BIRCH_H

#include "QTrees.h"

class QBirch : public QTrees
{

public:
	QBirch(QEnvironment const & environment);
	~QBirch();
	void grow();

private:
	std::list<char> mLeafColor;
	std::array<std::vector<double>, 5> mWeightingGrow;
	std::array<std::vector<double>, 5> mWeightingDryness;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
	void advance(int phase);
};

#endif //Q_BIRCH_H
