#pragma once

#include <QWidget>
#include <vector>
#include <qtimer.h>
#include "ui_ShowSnap.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using std::vector;
using cv::Mat;
using cv::cvtColor;

class ShowSnap : public QWidget
{
	Q_OBJECT

public:
	ShowSnap(QWidget *parent = Q_NULLPTR);
	~ShowSnap();
	void Play(vector<Mat> &snap);

public slots: 
	void handleSlider();

private:
	int framPoint;
	bool playFlag;
	uchar* buff;
	vector<Mat> *ss;
	void printMat(Mat a);
	void rePLay();
	Ui::ShowSnap ui;
};
