// QEntity.h
//
// Description:
// Classe virtuelle repr�sentant un �tre vivant qui sera simul� et les fonctions de bases le contr�lant.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#ifndef Q_ENTITY_H
#define Q_ENTITY_H

#include "QEnvironment.h"
#include <QGraphicsItem>
#include <QPointF>
#include <QBrush>
#include <QPen>
#include <QList>
class QForestScene;

enum treeType { Oak, Fir, Hazel, Birch , Na};
enum generalType { Squirrel, Tree, Seed };

class QEntity : public QGraphicsItem
{

public:
	QEntity(QEnvironment const &environment, QForestScene &forestscene, int lifeSpan, treeType tree, generalType type);
	virtual ~QEntity();

	virtual void reproduce();
	virtual void die();
	int getHeight();
	bool isDead();
	treeType mTreeType;
	generalType mGeneralType;

protected:
	QPointF mPosition;
	int mLifeSpan;
	int mAge{0};
	bool mIsDead{ false };
	int mTime{ 0 };
	QEnvironment const & mEnvironment;
	QForestScene & mForestScene;
	QPointF mCenter = QPointF(0, 0);
	QBrush mBrush;
	QPen mPen;
	int mHeight;
	void advanceTime();
	RandomUniform mDied;
};

#endif //Q_ENTITY_H

