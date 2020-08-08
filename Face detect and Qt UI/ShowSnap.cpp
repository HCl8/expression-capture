#include "ShowSnap.h"

ShowSnap::ShowSnap(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->buff = new uchar[1];
	playFlag = false;

	ui.slider->setMinimum(0);
	ui.slider->setMaximum(90);

	framPoint = 0;

	connect(ui.slider, SIGNAL(clickValueChange()), this, SLOT(handleSlider()));
}

ShowSnap::~ShowSnap()
{
}

void ShowSnap::handleSlider()
{
	framPoint = ui.slider->value();
	if (!playFlag)
		rePLay();
}

void ShowSnap::Play(vector<Mat>& snap)
{
	playFlag = true;
	ss = &snap;
	for (;framPoint < 90; framPoint++)
	{
		printMat(snap[framPoint]);
		ui.slider->setValue(framPoint);
		cv::waitKey(100);
	}
	playFlag = false;
}

void ShowSnap::printMat(Mat image)
{
		delete buff;
		cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
		buff = new uchar[image.rows * image.cols * image.channels()];
		QImage Qimage(buff, image.cols, image.rows, QImage::Format_RGB888);
		memcpy(Qimage.bits(), image.data, image.rows * image.cols * 3);
		ui.screen->PrintPicture(Qimage);
}

void ShowSnap::rePLay()
{
	playFlag = true;
	for (; framPoint < 90; framPoint++)
	{
		printMat((*ss)[framPoint]);
		ui.slider->setValue(framPoint);
		cv::waitKey(100);
	}
	playFlag = false;
}
