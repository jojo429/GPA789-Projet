// QTrees.h
//
// Description:
// Classe gérant la création et le comportement d'une entité de type arbre.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

#ifndef Q_TREES_H
#define Q_TREES_H

#include "QStatic.h"
#include <QBrush>
#include <QPen>
#include <QColor>
#include "GaussianTable.h"



class QTrees : public QStatic
{
	
public:

	QTrees(QEnvironment const & environment, QForestScene & forestscene,  int lifeSpan, treeType tree, generalType type);
	virtual ~QTrees()=default;
	
	void reproduce() override;
	double getShadowGrowFactor();
	int getRadius();
	void grow();
	virtual GaussianTable & growTable()=0;
	virtual GaussianTable & precipirationGrowFactorTable()=0;
	virtual GaussianTable & luminosityGrowFactorTable()=0;
	virtual GaussianTable & temperatureGrowFactorTable()=0;

protected:
	QColor mLeafColor;
	QColor mTrunkColor;
	double mTrunkRadius;
	double mLeafRadius;
	double mShadowFactor{1};
	void advance(int phase) override;
	QRectF boundingRect() const;
	QList<QGraphicsItem *> mShadowList;
	GaussianTable mEmpty;
	static RandomUniform mGenerateSeed;
	static RandomUniform mGenerateTime;
	int mReproductiveTime;	

};


#endif //Q_TREES_H
