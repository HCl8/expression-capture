#include "Pyinterface.h"

int Pyinterface::FindMax(double* in)
{
	//for (int i = 0; i < 7; i++)
	//	cout << in[i] << "\t";
	//cout << endl;
	double max = *in;
	int count = 0;
	for(int i=1;i<7;i++)
		if (in[i] > max) {
			max = in[i];
			count = i;
		}
	return count;
}

Pyinterface::Pyinterface()
{
	faceBuffer = (unsigned char*)malloc(0x20000);
	Py_Initialize();
	this->PyModule = PyImport_ImportModule("CNN");
	this->CNN = PyObject_GetAttrString(this->PyModule,"LoadModel");
	this->CNN = PyObject_Call(this->CNN, PyTuple_New(0), NULL);
	this->CNN_predict = PyObject_GetAttrString(this->PyModule, "model_predict");
	this->Fact = 1;
	this->Unfact = 1;
}

DetectResult Pyinterface::Handle(Mat img)
{
	DetectResult ResultStruct;
	for (int i = 0; i < 7; i++)
		ResultStruct.Percent[i] = 0;
	Mat ImageClone = img.clone();
	cv::resize(ImageClone, ImageClone, cv::Size(), this->Fact, this->Fact);
	int* pResults = facedetect_cnn(this->faceBuffer, ImageClone.ptr(0), ImageClone.cols, ImageClone.rows, ImageClone.step);
	double* result = new double[7];
	int ConfidenceFaceNumber = 0;

	Mat paint = img.clone();
	for (int i = 0; i < *pResults; i++)
	{
	//*	delete result;
		short* p = ((short*)(pResults + 1)) + 142 * i;
		p[0] *= this->Unfact;
		p[1] *= this->Unfact;
		p[2] *= this->Unfact;
		p[3] *= this->Unfact;
		int confidence = p[4];
		if (confidence >= 8) {
			ConfidenceFaceNumber++;
			//处理面部边框越界
			if (p[0] < 0) {
				p[2] += p[0];
				p[0] = 0;
			}
			if (p[1] < 0) {
				p[3] += p[1];
				p[1] = 0;
			}
			if (p[0] + p[2] > paint.cols) {
				p[2] -= (p[0] + p[2] - paint.cols);
			}
			if (p[1] + p[3] > paint.rows) {
				p[3] -= (p[1] + p[3] - paint.rows);
			}
			Mat imageFace(paint, Rect(p[0], p[1], p[2], p[3]));
			cv::resize(imageFace, imageFace, cv::Size(48, 48));
			cv::cvtColor(imageFace, imageFace, cv::COLOR_BGR2GRAY);
			PyObject* Args = PyTuple_New(2);
			PyTuple_SetItem(Args, 0, this->CNN);
			PyTuple_SetItem(Args, 1, Pyinterface::ImageToList(imageFace));
			PyObject* Pyr = PyObject_Call(this->CNN_predict, Args, NULL);
			result = Pyinterface::ResultFromPy(Pyr);
			int LabelNumber = Pyinterface::FindMax(result);
			ResultStruct.Percent[LabelNumber]++;
			putText(paint, this->Lable[LabelNumber], Point(p[0], p[1]), cv::FONT_HERSHEY_COMPLEX, 0.5, Scalar(255, 255, 0));
			rectangle(paint, Rect(p[0], p[1], p[2], p[3]), Scalar(0, 255.255));

			//热点图
			hotPoint point;
			point.x = p[0];
			point.y = p[1];
			point.width = p[2];
			point.heigh = p[3];
			point.degree = result[LabelNumber] * 100;
			point.express = LabelNumber;
			ResultStruct.point.push_back(point);
		}
	}
	ResultStruct.process_img = paint;
	if (ConfidenceFaceNumber == 1) {
		ResultStruct.Count = 100;
		for (int i = 0; i < 7; i++)
			ResultStruct.Percent[i] = result[i] * 100;
	}
	else 
		ResultStruct.Count = ConfidenceFaceNumber;
	delete[](result);
	return ResultStruct;
}

double* Pyinterface::ResultFromPy(PyObject* PyList)
{
	PyList = PyList_GetItem(PyList, 0);
	double* result = new double[7];
	PyObject* numtemp;
	for (int i = 0; i < 7; i++)
		result[i] = PyFloat_AsDouble (PyList_GetItem(PyList, i));
	return result;
}

PyObject* Pyinterface::ImageToList(Mat image)
{
	PyObject* List2D;
	List2D = PyList_New(0);
	for (int i = 0,count=0; i < 48; i++)
	{
		PyObject* List48 = PyList_New(0);
		for (int j = 0; j < 48; j++, count++)
			PyList_Append(List48, PyLong_FromLong(image.data[count]));
		PyList_Append(List2D, List48);
	}
	return List2D;
}

Mat Pyinterface::Handle_ALL(Mat imageFace)
{
	cv::resize(imageFace, imageFace, cv::Size(48, 48));
	cv::cvtColor(imageFace, imageFace, cv::COLOR_BGR2GRAY);
	PyObject* Args = PyTuple_New(2);
	PyTuple_SetItem(Args, 0, this->CNN);
	PyTuple_SetItem(Args, 1, Pyinterface::ImageToList(imageFace));
	PyObject* Pyr = PyObject_Call(this->CNN_predict, Args, NULL);
	double* result = Pyinterface::ResultFromPy(Pyr);
	int LabelNumber = Pyinterface::FindMax(result);
	putText(imageFace, this->Lable[LabelNumber], Point(0,15), cv::FONT_HERSHEY_COMPLEX, 0.5, Scalar(255, 255, 0));
	return imageFace;
}


int mainss()
{
	int test[48][48] = {0};
	test[0][0] = 44;
	test[9][9] = 99;
	test[47][47] = 26;
	
	Mat image(48, 48, CV_8U, test);

	Py_Initialize();

	PyObject* Pymodule = PyImport_ImportModule("CNN");
	PyObject* PyCalc = PyObject_GetAttrString(Pymodule, "MyPrint");
	PyObject* Args = PyTuple_New(1);
	PyTuple_SetItem(Args, 0, Pyinterface::ImageToList(image));
	PyObject_Call(PyCalc,  Args,NULL);
	return 0;
}

int main_test()
{
	Pyinterface aa;
	// VideoCapture camera("F:\\Torrent\\PARASITE.2019.1080p.FHDRip.H264.AAC-NonDRM");
	VideoCapture camera(0);
	Mat fram;
	aa.Fact = 0.25;
	aa.Unfact = 4;
	for (;;)
	{
		camera >> fram;
		//	fram = cv::imread("C:\\Users\\HCl\\Desktop\\timgs.jpg");
		DetectResult a = aa.Handle(fram);
		fram = a.process_img;
		cv::imshow(" ", fram);
		cv::waitKey(1);
	}
}
