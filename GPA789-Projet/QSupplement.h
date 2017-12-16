#ifndef Q_SUPPLEMENT_H
#define Q_SUPPLEMENT_H

#include <QString>
#include <QWidget>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

class QSupplement : public QWidget
{
	Q_OBJECT

public:
	QSupplement(QWidget * parent = Q_NULLPTR);

protected:
	QPushButton * mButtonAbout;

	QMessageBox * mMesBoxExec;

	QGridLayout * mLayout;
	QHBoxLayout * mHLayout;
	QVBoxLayout * mVLayout;

	QPushButton * setPushButton(QString const & caption);

protected slots:
	void setMesBoxAbout(); // Configurer la fenêtre "À propos de XtractCom"
};

#endif // Q_SUPPLEMENT_H

