#ifndef Q_PRECIPITATION_H
#define Q_PRECIPITATION_H

#include "QGlobal.h"

class QPrecipitation : public QGlobal
{

public:
	QPrecipitation();
	~QPrecipitation();
	int getPrecipitation();
	//enum getCyle();
	void setPrecipitation(int precipitation);
	//int setCycle(enum cycle);
	bool getIsRaining();
	float germinate() override;
	float grow() override;
	float adjustDryness() override;
	//array<double,3> airDisplacement();

private:
	int mChanceOfPrecipitation;
	bool mIsRaining;
	//enum mCycle;

};

#endif //Q_PRECIPITATION_H

