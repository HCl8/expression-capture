#pragma once

#include <Qwidget>
#include <qpainter.h>
#include <qimage.h>

class Screen : public QWidget
{
	Q_OBJECT

public:
	Screen(QWidget *parent);
	~Screen();
	void paintEvent(QPaintEvent* paintEvent);
	void PrintPicture(QImage image);

private:
	QImage image;
};
