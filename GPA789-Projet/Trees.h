#ifndef TREES_H
#define TREES_H

#include "Static.h"

class Trees : public Static
{

public:
	Trees();
	~Trees();

	virtual void grow(int luminosity, int fertility, int age);
	void reproduce() override;
	void die() override;
	int getHeight();
	void adjustDryness(bool isRaining);
	void setOnFire(bool gotHit, int dryness);

private:
	int mHeight;
	int mTrunkRadius;
	int mLeafRadius;
	int mDryness;
	bool mGotHit;

};

#endif //TREES_H
