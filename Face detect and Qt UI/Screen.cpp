#include "Screen.h"

Screen::Screen(QWidget *parent)
	: QWidget(parent),image()
{
}

Screen::~Screen()
{
}

void Screen::paintEvent(QPaintEvent* paintEvent)
{
	QPainter Pen(this);
	Pen.drawImage(QRect(0, 0, this->width(), this->height()), this->image);
}

void Screen::PrintPicture(QImage image)
{
	this->image = image;
	this->update();
}
