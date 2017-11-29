#ifndef Q_HAZEL_H
#define Q_HAZEL_H

#include "QTrees.h"

class QHazel : public QTrees
{

public:
	QHazel();
	~QHazel();
	void grow(int luminosity, int fertility, int age);

};

#endif //Q_HAZEL_H
