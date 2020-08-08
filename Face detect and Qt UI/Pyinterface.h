#pragma once
#include <opencv2/core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <Python.h>
#include <facenn/facedetectcnn.h>
#include <string>
#include "paintMap.h"

using cv::Mat;
using cv::rectangle;
using cv::Rect;
using cv::imread;
using cv::putText;
using cv::Point;
using cv::Scalar;
using cv::VideoCapture;
using std::string;
struct DetectResult
{
	int Count;
	int Percent[7];
	Mat process_img;
	QVector<hotPoint> point;
};

class Pyinterface
{

private:
	PyObject* CNN;
	PyObject* CNN_predict;
	PyObject* PyModule;
	unsigned char* faceBuffer;
	static int FindMax(double*);
	string Lable[7] = {
		"Angry", " Disgust", "Fear", " Happy", " Sad", " Surprise", " Neutral"
	};

public:
	double Fact;
	double Unfact;
	Pyinterface();
	DetectResult Handle(Mat);
	static double* ResultFromPy(PyObject*);
	static PyObject* ImageToList(Mat image);
	Mat Handle_ALL(Mat);
};

