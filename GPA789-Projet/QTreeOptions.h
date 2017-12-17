// QStatisticAdvanceMenu.h
//
// Description:
// Widget gérant l'affichage des sliders permetant de choisir le nombre d'arbre.
//
//
// Auteurs:
// Alex Gosselin-Pronovost
// Joé Charest
// Félixe Girard
// Geneviève Dao Phan
//
// Automne 2017

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
	~QTreeOptions()=default;
	int getValue();

private:
	QSlider *mTreeSlider;
	QLabel *mTreeLabel;
	QLabel *mTreeValue;
	QGridLayout *mTreeOptionsGridLayout;

protected slots:
	void updateValues(); // Mise à jour de la valeur d'affichage
};

#endif //Q_TREE_OPTIONS_H
