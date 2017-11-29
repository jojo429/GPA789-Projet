#ifndef Q_FOREST_SCENE_H
#define Q_FOREST_SCENE_H

#include <QGraphicsScene>

class QForestScene : public QGraphicsScene
{
	Q_OBJECT

public:
	QForestScene(QGraphicsScene * parent = Q_NULLPTR);
	~QForestScene();
};
#endif //Q_FOREST_SCENE_H

