#ifndef Q_ANIMAL_OPTIONS_H
#define Q_ANIMAL_OPTIONS_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>

class QAnimalOptions : public QWidget
{
	Q_OBJECT

public:
	QAnimalOptions(QWidget *parent = Q_NULLPTR);
	QAnimalOptions(QString animalName, int minNumbAnimals, int maxNumbAnimals, int numbAnimalsInit);
	~QAnimalOptions();

private:
	QSlider *mAnimalSlider;

	QLabel *mAnimalLabel;
	QLabel *mAnimalValue;

	QGridLayout *mAnimalOptionsGridLayout;

protected slots:
	void updateValues();
};

#endif //Q_ANIMAL_OPTIONS_H
