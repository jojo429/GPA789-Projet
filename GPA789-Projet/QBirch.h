#ifndef Q_BIRCH_H
#define Q_BIRCH_H

#include "QTrees.h"

class QBirch : public QTrees
{

public:
	QBirch();
	~QBirch();
	void grow(int luminosity, int fertility, int age);

};

#endif //Q_BIRCH_H
