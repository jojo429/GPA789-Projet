#include "QSimulationAdvancementOptions.h"

QSimulationAdvancementOptions::QSimulationAdvancementOptions(QWidget *parent)
	: QWidget(parent)
{

}

QSimulationAdvancementOptions::QSimulationAdvancementOptions(QString caption, QString iconName)
{
	mIcon = QPixmap(iconName);

	mButton = new QPushButton;
	mButton->setText(caption);
	mButton->setIcon(mIcon);

	mLayout = new QGridLayout;
	mLayout->addWidget(mButton);
	setLayout(mLayout);
	connect(mButton, &QPushButton::clicked, this, & QSimulationAdvancementOptions::clicked);
}

QSimulationAdvancementOptions::~QSimulationAdvancementOptions()
{

}




