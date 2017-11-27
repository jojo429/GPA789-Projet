#ifndef LUMINOSITY_H
#define LUMINOSITY_H

#include "Global.h"

class Luminosity : public Global
{

public:
	Luminosity();
	~Luminosity();
	int getLuminosity();
	void setLuminosity(int luminosity);
	void luminosity();
	void luminosity(int luminosity);

private:
	int mLuminosity;

};

#endif //LUMINOSITY_H

