#ifndef Q_HAZEL_H
#define Q_HAZEL_H

#include "QTrees.h"

class QHazel : public QTrees
{

public:
	QHazel(QEnvironment const & environment);
	~QHazel();
	void grow();

private:
	QColor mLeafColor;
	QColor mTrunkColor;
	std::array<std::vector<double>, 5> mWeightingGrow;
	std::array<std::vector<double>, 5> mWeightingDryness;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
	//void advance(int phase);
};

#endif //Q_HAZEL_H
