// QRandomMap.h
//
// Description:
// Widget permetant de g�n�rer une carte de valeurs al�atoires et de la transformer en image.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

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

	void setMap(); // Algorithme "Diamond-Square" appliqu�
	void scaleValuesRangeMap(double minScaleValue, double maxScaleValue); // Redimensionner les valeurs � chaque point de la carte dans l'intervalle choisie
	void findMinMax(); // Trouver les valeurs min et max de la carte juste apr�s sa g�n�ration par l'algorithme "Diamond-Square"
	void drawMap(int rColor, int gColor, int bColor); // Dessiner la carte initiale
	void updateDrawMap(int x, int y); // Redessiner un point de la carte
	double getMapValue(int x, int y); // Obtenir la valeur � un point donn� de la carte
	void setMapValue(int x, int y, double value); // Mise � jour de la valeur � un point donn� de la carte
	void resizeMap(); // Redimensionner la taille visuelle de la carte et ajuster ses valeurs (Si on veut le rendre plus modulaire -> void resizeMap(int resizeValue)
	void resizeOnePixel(int nextPixelIndexX, int nextPixelIndexY, int pixelIndexX, int pixelIndexY); // Redimensionner un pixel du tableau d'origine
	QPixmap getPixmap(); // Obtenir le pixmap qui permet de dessiner la carte

private:
	int mMin;
	int mMax;
	int mRColor;
	int mGColor;
	int mBColor;
	double mMap[513][513];
	double mMapResize[2052][2052];
	QPixmap mPixelsMap;
	QPainter *mPainterMap;

};

#endif //Q_RANDOM_MAP_H
