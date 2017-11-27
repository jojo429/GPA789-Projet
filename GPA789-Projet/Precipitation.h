#ifndef PRECIPITATION_H
#define PRECIPITATION_H

#include "Global.h"

class Precipitation : public Global
{

public:
	Precipitation();
	~Precipitation();
	int getPrecipitation();
	void setPrecipitation(int precipitation);
	bool getIsRaining();

private:
	int mChanceOfPrecipitation;
	bool mIsRaining;

};

#endif //PRECIPITATION_H

