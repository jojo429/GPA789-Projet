#ifndef GPA789_PROJET_H
#define GPA789_PROJET_H

#include <QtWidgets/QMainWindow>
#include "ui_GPA789Projet.h"
#include "QForestScene.h"
#include "QEnvironment.h"

class GPA789Projet : public QMainWindow
{
	Q_OBJECT

public:
	GPA789Projet(QWidget *parent = Q_NULLPTR);

private:
	QForestScene mForestScene;
	QEnvironment mEnvironment;


private:
	Ui::GPA789ProjetClass ui;
};

#endif //GPA789_PROJET_H
