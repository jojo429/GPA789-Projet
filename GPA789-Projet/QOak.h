#ifndef Q_OAK_H
#define Q_OAK_H

#include "QTrees.h"

class QOak : public QTrees
{

public:
	QOak();
	~QOak();
	void grow(int luminosity, int fertility, int age);
};

#endif //Q_OAK_H
