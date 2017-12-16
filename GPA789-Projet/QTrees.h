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

	QTrees(QEnvironment const & environment, QForestScene & forestscene, treeType value, int lifeSpan, generalType type);
	virtual ~QTrees();

	
	void reproduce() override;

	int getRadius();
	void grow();

	treeType mTreeType;
	generalType mGeneralType;
	virtual GaussianTable & growTable()=0;
	virtual GaussianTable & precipirationGrowFactorTable()=0;
	virtual GaussianTable & luminosityGrowFactorTable()=0;
	virtual GaussianTable & temperatureGrowFactorTable()=0;



protected:
	QColor mLeafColor;
	QColor mTrunkColor;

	double mTrunkRadius;
	double mLeafRadius;

	void advance(int phase) override;
	QRectF boundingRect() const;
	
	GaussianTable mEmpty;
	RandomUniform mGenerateSeed;
	RandomUniform mGenerateTime;
	int mReproductiveTime;

	

};


#endif //Q_TREES_H
