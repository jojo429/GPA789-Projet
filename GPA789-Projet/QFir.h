#ifndef Q_FIR_H
#define Q_FIR_H

#include "QTrees.h"

class QFir : public QTrees
{

public:
	QFir(QEnvironment const & environment);
	~QFir();
	void grow();

private:
	std::list<char> mLeafColor;
	std::array<std::vector<double>, 5> mWeightingGrow;
	std::array<std::vector<double>, 5> mWeightingDryness;

};

#endif //Q_FIR_H
