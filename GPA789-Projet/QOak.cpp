#include "QOak.h"
#include <QBrush>
#include <QPainter>

QOak::QOak(QEnvironment const & environment)
	: QTrees{ environment }
{






}

QOak::~QOak()
{

}

void QOak::grow()
{

}

void QOak::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{

	QBrush brush(Qt::green);
	QPen pen = QPen(Qt::white, 2);
	QColor darkGreen = QColor(100, 186, 63);
	QColor darkBrown = QColor(86, 75, 52);



	//Dessine le tronc
	brush.setColor(darkBrown);
	brush.setStyle(Qt::SolidPattern);
	painter->setOpacity(1);
	painter->setBrush(brush);
	painter->setPen(pen);
	painter->drawEllipse(mCenter, mTrunkRadius, mTrunkRadius);
	//Dessine les feuilles
	brush.setColor(darkGreen);
	brush.setStyle(Qt::Dense5Pattern);
	painter->setBrush(brush);
	painter->drawEllipse(mCenter, mLeafRadius, mLeafRadius);
}

//void QOak::advance(int phase)
//{
//}
