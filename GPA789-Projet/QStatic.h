// QStatic.h
//
// Description:
// Classe virtuelle repr�sentant une entit� n'ayant pas la facult� de se d�placer.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Jo� Charest
// F�lixe Girard
// Genevi�ve Dao Phan
//
// Automne 2017

#ifndef Q_STATIC_H
#define Q_STATIC_H

#include "QEntity.h"

class QStatic : public QEntity
{

public:
	QStatic(QEnvironment const & environment, QForestScene & forestscene, int lifeSpan, treeType tree, generalType type);
	virtual ~QStatic();

};
#endif //Q_STATIC_H

