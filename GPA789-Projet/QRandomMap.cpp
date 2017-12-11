#include "QRandomMap.h"

#include "RandomUniform.h"

#include <array>
#include <QDebug>
#include <QPainter>
#include <QColor>
#include <QImage>

QRandomMap::QRandomMap(QWidget *parent)
	: QWidget(parent)
{
	//qDebug() << "Hello";
}

QRandomMap::~QRandomMap()
{

}

void QRandomMap::setMap()
{
	int id, x, y, average, sum, shift, n;
	int h{ 513 };
	int step{ h - 1 };

	RandomUniform randNumberValue = RandomUniform();
	RandomUniform randNumberSideSize = RandomUniform(-h, h);
	// Initialize the corners of the map
	mMap[0][0] = randNumberSideSize.random();
	mMap[0][h - 1] = randNumberSideSize.random();
	mMap[h - 1][h - 1] = randNumberSideSize.random();
	mMap[h - 1][0] = randNumberSideSize.random();
	int test;
	while (step > 1) {
		id = step / 2;

		// Start the diamond phase of the algorithm
		for (x = id; x < h; x = x + step) {
			for (y = id; y < h; y = y + step) {
				average = (mMap[x - id][y - id] + mMap[x - id][y + id]
					+ mMap[x + id][y + id] + mMap[x + id][y - id]) / 4;
				mMap[x][y] = average + randNumberValue.random(-id, id);
			}
		}

		// Start the square phase of the algorithm
		for (x = 0; x < h; x = x + id)
		{
			if (x%step == 0) {
				shift = id;
			}
			else
			{
				shift = 0;
			}

			for (y = shift; y < h; y = y + step) {
				sum = 0;
				n = 0;

				if (x >= id) {
					sum = sum + mMap[x - id][y];
					n = n + 1;
				}

				if (x + id < h) {
					sum = sum + mMap[x + id][y];
					n = n + 1;
				}

				if (y >= id) {
					sum = sum + mMap[x][y - id];
					n = n + 1;
				}

				if ((y + id) < h) {
					sum = sum + mMap[x][y + id];
					n = n + 1;
				}

				mMap[x][y] = sum / n + randNumberValue.random(-id,id);
			}
		}
		step = id;
	}

	/*
	qDebug() << QString::number(mMap[2000][1000]);
	qDebug() << QString::number(mMap[1000][1000]);
	qDebug() << QString::number(mMap[500][1000]);
	qDebug() << QString::number(mMap[200][1000]);
	qDebug() << QString::number(randNumberValue.random(-50,50));*/
}

void QRandomMap::scaleMap()
{
	int i, j;

	for (i = 0; i < 513; ++i) {
		for (j = 0; j < 513; ++j) {
			mMap[i][j] = (((100 - 0)*(mMap[i][j] - mMin)) / (mMax - mMin)) - 0;
		}
	}

	/*
	qDebug() << QString::number(mMapScaled[2000][1000]);
	qDebug() << QString::number(mMapScaled[1000][1000]);
	qDebug() << QString::number(mMapScaled[500][1000]);*/
}

void QRandomMap::findMinMax()
{
	int i, j;
	mMin = mMap[0][0];
	mMax = mMap[0][0];

	for (i = 0; i < 513; ++i) {
		for (j = 0; j < 513; ++j) {
			if (mMap[i][j] < mMin) {
				mMin = mMap[i][j];
			}
			else if (mMap[i][j] >= mMax) {
				mMax = mMap[i][j];
			}
		}
	}
	/*
	qDebug() << QString::number(mMin);
	qDebug() << QString::number(mMax);*/
}

void QRandomMap::drawMap()
{
	int i, j;
	qreal shade;
	
	mPixelsMap = QPixmap(513, 513);

	QColor mapColor;

	QPainter painter(&mPixelsMap);
	//painter.setPen(Qt::red);
	//painter.drawPoint(10, 10);

	for (i = 0; i < 513; ++i) {
		for (j = 0; j < 513; ++j) {
			shade = mMap[i][j] / 150.0;
			mapColor.setRgb(244*shade, 164*shade, 96*shade);
			painter.setPen(mapColor);
			painter.drawPoint(i, j);
		}
	}

	QImage image = mPixelsMap.toImage();
	image.save("C:/Github/GPA789-Projet/GPA789-Projet/Resources/imageTest.png");
}
