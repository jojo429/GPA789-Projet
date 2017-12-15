#include "QTreeOptions.h"

QTreeOptions::QTreeOptions(QWidget *parent)
	: QWidget(parent)
{

}

QTreeOptions::QTreeOptions(QString treeName, int minNumbTrees, int maxNumbTrees, int numbTreesInit)
{
	mTreeLabel = new QLabel(treeName);

	mTreeSlider = new QSlider(Qt::Horizontal);
	mTreeSlider->setMinimum(minNumbTrees);
	mTreeSlider->setMaximum(maxNumbTrees);

	mTreeValue = new QLabel(QString::number(numbTreesInit));

	mTreeOptionsGridLayout = new QGridLayout;
	mTreeOptionsGridLayout->addWidget(mTreeLabel, 0, 0);
	mTreeOptionsGridLayout->addWidget(mTreeSlider, 0, 1);
	mTreeOptionsGridLayout->addWidget(mTreeValue, 0, 2);

	connect(mTreeSlider, &QSlider::valueChanged, this, &QTreeOptions::updateValues);

	setLayout(mTreeOptionsGridLayout);
}

QTreeOptions::~QTreeOptions()
{

}

void QTreeOptions::updateValues()
{
	mTreeValue->setText(QString::number(mTreeSlider->value()));
}
