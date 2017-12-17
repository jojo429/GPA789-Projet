#ifndef Q_FERTILITY_H
#define Q_FERTILITY_H

#include "QPonctual.h"
#include "QRandomMap.h"

class QFertility : public QPonctual
{

public:
	QFertility();
	~QFertility();
	double getFertility(int x, int y) const; // Obtenir la fertilit� � un point(x,y) donn�
	void setFertility(double minValue, double maxValue);  // G�n�rer la carte de fertilit�s initiale
	void updateFertility(int x, int y, double fertility); // Mise � jour de la fertilit� � un point(x,y) donn�
	QPixmap getFertilityPixmap(); // Obtenir le pixmap de la carte de fertilit�s


private:
	QRandomMap *mFertilityMap;

};

#endif //Q_FERTILITY_H
