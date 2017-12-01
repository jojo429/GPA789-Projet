#ifndef Q_OAK_H
#define Q_OAK_H

#include "QTrees.h"

class QOak : public QTrees
{

public:
	QOak(QEnvironment const & environment);
	~QOak();
	void grow();

private:
	std::list<char> mLeafColor;
	std::array<std::vector<double>, 5> mWeightingGrow;
	std::array<std::vector<double>, 5> mWeightingDryness;
};

#endif //Q_OAK_H
