#pragma once

#include <QWidget>
#include <qpainter.h>
#include <qpen.h>
#include <qbrush.h>
#include <QRadialGradient>
#include <qcolor.h>
#include <qvector.h>
#include <QMouseEvent>

#include <iostream>



struct hotPoint {
	int x;
	int y;
	int width;
	int heigh;
	int express;
	int degree;
};

class paintMap : public QWidget
{
	Q_OBJECT

public:
	paintMap(QWidget *parent);
	~paintMap();
	void addPoint(hotPoint p);
	void clearPoint();
	void setGSize(int x, int y);
private:
	double Gwidth;
	double Gheigh;
	QRadialGradient gradient;
	QColor HColor[7];
	QVector<hotPoint> points;
	void paintEvent(QPaintEvent *);
};
