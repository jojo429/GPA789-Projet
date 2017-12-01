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
	std::list<char> mLeafColor;
	std::array<std::vector<double>, 5> mWeightingGrow;
	std::array<std::vector<double>, 5> mWeightingDryness;

};

#endif //Q_HAZEL_H
