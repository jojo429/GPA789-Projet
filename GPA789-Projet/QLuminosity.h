#ifndef Q_LUMINOSITY_H
#define Q_LUMINOSITY_H

#include "QGlobal.h"

class QLuminosity : public QGlobal
{

public:
	QLuminosity();
	~QLuminosity();
	int getLuminosity();
	void setLuminosity(int luminosity);
	void luminosity();
	void luminosity(int luminosity);
	float germinate();
	float grow();

private:
	int mLuminosity;

};

#endif //Q_LUMINOSITY_H

