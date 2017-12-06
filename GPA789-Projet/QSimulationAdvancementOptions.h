#ifndef Q_SIMULATION_ADVANCEMENT_OPTIONS_H
#define Q_SIMULATION_ADVANCEMENT_OPTIONS_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>

class QSimulationAdvancementOptions : public QWidget
{
	Q_OBJECT

public:
	QSimulationAdvancementOptions(QWidget *parent);
	QSimulationAdvancementOptions(QString caption, QString iconName);
	~QSimulationAdvancementOptions();

private:
	QPixmap mIcon;

	QPushButton *mButton;

	QGridLayout *mLayout;
};

#endif //Q_SIMULATION_ADVANCEMENT_OPTIONS_H
