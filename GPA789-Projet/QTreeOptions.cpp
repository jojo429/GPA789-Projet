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
#include "QTreeOptions.h"

QTreeOptions::QTreeOptions(QWidget *parent)
	: QWidget(parent)
{

}

QTreeOptions::QTreeOptions(QString treeName, int minNumbTrees, int maxNumbTrees, int numbTreesInit)
{
	// Définir le nom du slider
	mTreeLabel = new QLabel(treeName);

	// Créer le slider
	mTreeSlider = new QSlider(Qt::Horizontal);
	mTreeSlider->setMinimum(minNumbTrees);
	mTreeSlider->setMaximum(maxNumbTrees);
	mTreeSlider->setSliderPosition(numbTreesInit);

	// Afficher la valeur initiale du slider
	mTreeValue = new QLabel(QString::number(numbTreesInit));

	// Assemblage
	mTreeOptionsGridLayout = new QGridLayout;
	mTreeOptionsGridLayout->setContentsMargins(QMargins(0, 0, 0, 0));
	mTreeOptionsGridLayout->addWidget(mTreeLabel, 0, 0);
	mTreeOptionsGridLayout->addWidget(mTreeSlider, 0, 1);
	mTreeOptionsGridLayout->addWidget(mTreeValue, 0, 2);

	// Connection du slider au label d'affichage
	connect(mTreeSlider, &QSlider::valueChanged, this, &QTreeOptions::updateValues);

	setLayout(mTreeOptionsGridLayout);
}

void QTreeOptions::updateValues()
{
	mTreeValue->setText(QString::number(mTreeSlider->value()));
}

int QTreeOptions::getValue()
{
	return mTreeSlider->value();
}