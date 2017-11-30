#ifndef Q_PRECIPITATION_H
#define Q_PRECIPITATION_H

#include "QGlobal.h"
#include <array>

class QPrecipitation : public QGlobal
{

public:
	QPrecipitation();
	~QPrecipitation();
	int getAverage_mm();
	int getVariation_mm();
	int getCycle();
	void setAveragemm(int average_mm);
	void setVariationmm(int variation_mm);
	void setCycle(int cycle);
	float germinate();
	float grow();
	float adjustDryness();
	std::array<double,3> airDisplacement();

private:
	int mAverage_mm;
	int mVariation_mm;
	int mCycle;

};

#endif //Q_PRECIPITATION_H

