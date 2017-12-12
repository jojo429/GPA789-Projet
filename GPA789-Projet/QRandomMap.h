#ifndef Q_RANDOM_MAP_H
#define Q_RANDOM_MAP_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>

class QRandomMap : public QWidget
{
	Q_OBJECT

public:
	QRandomMap(QWidget *parent = Q_NULLPTR);
	~QRandomMap();

	void setMap(); // Algorithme "Diamond-Square" appliqué
	void scaleValuesRangeMap(double minScaleValue, double maxScaleValue); // Redimensionner les valeurs à chaque point de la carte dans l'intervalle choisie
	void findMinMax(); // Trouver les valeurs min et max de la carte juste après sa génération par l'algorithme "Diamond-Square"
	void drawMap(int rColor, int gColor, int bColor); // Dessiner la carte initiale
	void updateDrawMap(int x, int y, int rColor, int gColor, int bColor); // Redessiner un point de la carte
	double getMapValue(int x, int y); // Obtenir la valeur à un point donné de la carte
	void setMapValue(int x, int y, double value); // Mise à jour de la valeur à un point donné de la carte
	void resizeMap(); // Redimensionner la taille visuelle de la carte et ajuster ses valeurs (Si on veut le rendre plus modulaire -> void resizeMap(int resizeValue)
	void resizeOnePixel(int nextPixelIndexX, int nextPixelIndexY, int pixelIndexX, int pixelIndexY);

private:
	int mMin;
	int mMax;
	double mMap[513][513];
	double mMapResize[2052][2052];
	
	QPixmap mPixelsMap;
	
	QPainter *mPainterMap;
};

#endif //Q_RANDOM_MAP_H
