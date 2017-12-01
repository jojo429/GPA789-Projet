#ifndef Q_SEEDS_H
#define Q_SEEDS_H

#include "QDynamic.h"
#include <vector>

class QSeeds : public QDynamic
{

public:
	QSeeds(QEnvironment const & environment);
	~QSeeds();
	void germinate();
	void die() override;

private:
	int mHeight;
	int mWeight;
	std::array<std::vector<double>, 5> mWeightingGerminate;
	void move() override;

};


#endif //Q_SEEDS_H

