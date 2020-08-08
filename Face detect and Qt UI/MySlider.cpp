#include "MySlider.h"

MySlider::MySlider(QWidget *parent)
	: QSlider(parent)
{
	pressFlag = false;
}

MySlider::~MySlider()
{
}

void MySlider::mouseMoveEvent(QMouseEvent * event)
{
	if (pressFlag)
		refreshPos(event->x());
}

void MySlider::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton) {
		pressFlag = true;
		refreshPos(event->x());
	}
}

void MySlider::mouseReleaseEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton)
		pressFlag = false;
}

void MySlider::refreshPos(double y)
{
	setValue(y * 100 / width());
	emit clickValueChange();
	update();
}
