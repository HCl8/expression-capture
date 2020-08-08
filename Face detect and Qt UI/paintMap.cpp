#include "paintMap.h"

paintMap::paintMap(QWidget *parent)
	: QWidget(parent), gradient(0, 0, 0, 0, 0)
{
	HColor[0] = QColor(227,7,7);
	HColor[1] = QColor(242,150,3);
	HColor[2] = QColor(245,231,0);
	HColor[3] = QColor(7,230,2);
	HColor[4] = QColor(4,217,233);
	HColor[5] = QColor(9,41,248);
	HColor[6] = QColor(223,0,244);
	gradient.setColorAt(1, QColor::fromRgb(0,0,0,0));
}

paintMap::~paintMap()
{
}

void paintMap::paintEvent(QPaintEvent *)
{
	QPainter pen(this);
	pen.drawRect(0, 0, this->width()-1, this->height()-1);
	double scala = this->width() / 1000.0;
	int aLength = this->width() > this->height() ? this->width() / 5 : this->height() / 5;
	for (auto i : points)
	{
		int centerX = i.x + i.width / 2;
		int centerY = i.y + i.heigh / 2;
		gradient.setCenter(centerX, centerY);
		gradient.setFocalPoint(centerX, centerY);
		gradient.setRadius(scala*i.degree);
		HColor[i.express].setAlpha(i.degree * 255 / 100);
		gradient.setColorAt(0, HColor[i.express]);
		pen.fillRect(centerX-aLength/2, centerY-aLength/2, centerX + aLength / 2, centerY + aLength / 2, gradient);
	}
}

void paintMap::addPoint(hotPoint p)
{
	p.x *= Gwidth;
	p.y *= Gwidth;
	p.width *= Gheigh;
	p.heigh *= Gheigh;
	points.push_back(p);
	update();
}

void paintMap::clearPoint()
{
	points.clear();
}

void paintMap::setGSize(int x, int y)
{
	Gwidth = x;
	Gwidth = this->width() / Gwidth;
	Gheigh = y;
	Gheigh = this->height() / Gheigh;
}

