#ifndef Q_TREE_OPTIONS_H
#define Q_TREE_OPTIONS_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>

class QTreeOptions : public QWidget
{
	Q_OBJECT

public:
	QTreeOptions(QWidget *parent = Q_NULLPTR);
	QTreeOptions(QString treeName, int minNumbTrees, int maxNumbTrees, int numbTreesInit);
	~QTreeOptions();

private:
	QSlider *mTreeSlider;

	QLabel *mTreeLabel;
	QLabel *mTreeValue;

	QGridLayout *mTreeOptionsGridLayout;

protected slots:
	void updateValues();
};

#endif //Q_TREE_OPTIONS_H
