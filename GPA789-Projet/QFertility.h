#ifndef Q_FERTILITY_H
#define Q_FERTILITY_H

#include "QPonctual.h"
#include "QRandomMap.h"

class QFertility : public QPonctual
{

public:
	QFertility();
	~QFertility();
	double getFertility(int x, int y) const; // Obtenir la fertilité à un point(x,y) donné
	void setFertility(double minValue, double maxValue);  // Générer la carte de fertilités initiale
	void updateFertility(int x, int y, double fertility); // Mise à jour de la fertilité à un point(x,y) donné
	QPixmap getFertilityPixmap(); // Obtenir le pixmap de la carte de fertilités


private:
	QRandomMap *mFertilityMap;

};

#endif //Q_FERTILITY_H
