#ifndef Q_ENTITY_H
#define Q_ENTITY_H

#include <QGraphicsItem>

class QEntity : public QGraphicsItem
{

public:
	QEntity(QGraphicsItem * parent = Q_NULLPTR);
	~QEntity();

private:
	int mLifeSpan;
	int mAge;
	int mEnvironment;
	virtual void reproduce();
	virtual void die();

};

#endif //Q_ENTITY_H

