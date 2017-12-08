#include "QOak.h"
#include <QBrush>
#include <QPainter>
#include <QColor>

QOak::QOak(QEnvironment const & environment)
	: QTrees{ environment }
{
	mLeafColor.setRgb(100, 186, 63);
	mTrunkColor.setRgb(68, 49, 3);
	mPen.setColor(Qt::white);
	mPen.setWidth(0.1);


}

QOak::~QOak()
{

}

void QOak::grow()
{

}

void QOak::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{


	//Dessine le tronc
	mBrush.setColor(mTrunkColor);
	mBrush.setStyle(Qt::SolidPattern);
	painter->setOpacity(1);
	painter->setBrush(mBrush);
	painter->setPen(mPen);
	painter->drawEllipse(mCenter, mTrunkRadius, mTrunkRadius);
	//Dessine les feuilles
	mBrush.setColor(mLeafColor);
	mBrush.setStyle(Qt::Dense5Pattern);
	painter->setBrush(mBrush);
	painter->drawEllipse(mCenter, mLeafRadius, mLeafRadius);
}

//void QOak::advance(int phase)
//{
//}
