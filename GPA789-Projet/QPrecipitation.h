#ifndef Q_PRECIPITATION_H
#define Q_PRECIPITATION_H

#include "QGlobal.h"

class QPrecipitation : public QGlobal
{

public:
	QPrecipitation();
	~QPrecipitation();
	int getPrecipitation();
	void setPrecipitation(int precipitation);
	bool getIsRaining();

private:
	int mChanceOfPrecipitation;
	bool mIsRaining;

};

#endif //Q_PRECIPITATION_H

