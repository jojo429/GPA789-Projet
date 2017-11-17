#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GPA789Projet.h"

class GPA789Projet : public QMainWindow
{
	Q_OBJECT

public:
	GPA789Projet(QWidget *parent = Q_NULLPTR);

private:
	Ui::GPA789ProjetClass ui;
};
