#pragma once

#include <QSlider>
#include <qevent.h>

class MySlider : public QSlider
{
	Q_OBJECT

public:
	MySlider(QWidget *parent);
	~MySlider();

signals:
	void clickValueChange();

private:
	bool pressFlag;
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void refreshPos(double y);
};
