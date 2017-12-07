#include "QFertility.h"
#include "RandomUniform.h"

#include <array>

QFertility::QFertility()
{

}

QFertility::~QFertility()
{

}

char QFertility::getFertility(qreal x, qreal y)
{
	return 0;
}

char QFertility::getFertility(QPointF pt2D)
{
	return 0;
}

void QFertility::setFertility(qreal x, qreal y, char fertility)
{

}

void QFertility::setFertility(QPointF pt2D, char fertility)
{

}

void QFertility::setFertility(double maxFertilityValue)
{
	int id, x, y, average, sum, shift, n;
	int h{2049};
	int step{ h - 1 };

	RandomUniform randNumber = RandomUniform(-h, h);
	// Initialize the corners of the map
	mFertilityMap[0][0] = randNumber.random();
	mFertilityMap[0][h - 1] = randNumber.random();
	mFertilityMap[h - 1][h - 1] = randNumber.random();
	mFertilityMap[h - 1][0] = randNumber.random();

	while(step > 1){
		id = step / 2;

		// Start the diamond phase of the algorithm
		for (x = id; x <=h; x + step) {
			for (y = id; y <= h; y + step) {
				average = (mFertilityMap[x - id][y - id] + mFertilityMap[x - id][y + id]
					+ mFertilityMap[x + id][y + id] + mFertilityMap[x + id][y - id]) / 4;
				mFertilityMap[x][y] = average + randNumber.random();
			}
		}

		// Start the square phase of the algorithm
		for (x = 0; x <= h; x + id)
		{
			if (x%step == 0) {
				shift = id;
			}
			else
			{
				shift = 0;
			}

			for (y = shift; y <= h; y + step) {
				sum = 0;
				n = 0;

				if (x >= id) {
					sum = sum + mFertilityMap[x - id][y];
					n = n + 1;
				}

				if (x + id < h) {
					sum = sum + mFertilityMap[x + id][y];
					n = n + 1;
				}

				if (y >= id) {
					sum = sum + mFertilityMap[x][y - id];
					n = n + 1;
				}

				if ((y + id) < h) {
					sum = sum + mFertilityMap[x][y + id];
					n = n + 1;
				}

				mFertilityMap[x][y] = sum / n + randNumber.random();
			}
		}
	}
}

void QFertility::drawFertility()
{

}

void QFertility:: enableFertility()
{

}

void QFertility::disableFertility()
{

}

float QFertility::germinate(QPointF pt2D)
{
	return 0;
}

float QFertility::grow(QPointF pt2D)
{
	return 0;
}