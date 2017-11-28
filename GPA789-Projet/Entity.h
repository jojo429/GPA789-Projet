#ifndef ENTITY_H
#define ENTITY_H

#include <QGraphicsItem>

class Entity : public QGraphicsItem
{

public:
	Entity(QGraphicsItem * parent = Q_NULLPTR);
	~Entity();

private:
	int mLifeSpan;
	int mAge;
	int mEnvironment;
	virtual void reproduce();
	virtual void die();

};

#endif //ENTITY_H

