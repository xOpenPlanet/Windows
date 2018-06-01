#ifndef SHADOW_H
#define SHADOW_H

#include <QWidget>
#include <QPainter>
#include <qmath.h>
#include <Windows.h>

class Shadow : public QWidget
{
	Q_OBJECT

public:
	Shadow();
	~Shadow();

private:
	void paintEvent(QPaintEvent * event);
};

#endif // SHADOW_H
