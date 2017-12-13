#ifndef Q_STATIC_H
#define Q_STATIC_H

#include "QEntity.h"

class QStatic : public QEntity
{

public:
	QStatic(const QStatic&) = default;
	QStatic(QEnvironment const & environment);
	~QStatic();

};

#endif //Q_STATIC_H

