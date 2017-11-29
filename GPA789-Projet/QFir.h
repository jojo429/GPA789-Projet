#ifndef Q_FIR_H
#define Q_FIR_H

#include "QTrees.h"

class QFir : public QTrees
{

public:
	QFir();
	~QFir();
	void grow(int luminosity, int fertility, int age);

};

#endif //Q_FIR_H
