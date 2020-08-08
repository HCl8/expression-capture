#pragma once

#include <QtWidgets/QMainWindow>
#include <qfiledialog.h>
#include <qbytearray.h>
#include <qtextcodec.h>
#include <qmutex.h>
#include "ui_develop10.h"
#include "Pyinterface.h"
#include "Snap.h"
#include "ShowSnap.h"

class develop10 : public QMainWindow
{
	Q_OBJECT

public:
	develop10(QWidget *parent = Q_NULLPTR);

private:
	int isSnap;
	int nowSnapNUmber;
	int CameraFlag;
	int VideoFlag;
	int VideoFramNumber;
	int AllFram;
	QListWidgetItem *item;
	QMutex mutex;
	QString Lable[7] = {
		" Angry", " Disgust", " Fear", " Happy", " Sad", " Surprise", " Neutral"
	};
	VideoCapture* PVideo;
	Ui::develop10Class ui;
	Pyinterface CNNModdel;
	Snap snap;
	void SetUI(DetectResult result, int All, Mat original_img);
	void PrintImage(Mat image);
	QImage Mat2Qimage(Mat image);
	bool SnapCondition(DetectResult &result);
	int findMax(int *);

	QTextCodec* GB;
	uchar* buff;

public slots:
	void OpenImageFile();
	void OpenCamera();
	void OpenVideo();
	void SetVideoFram();
	void PlaySnap(QListWidgetItem *item);
};
