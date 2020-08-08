#pragma once
#include <iostream>
#include <vector>

#include <opencv2/core.hpp>

using std::vector;
using cv::Mat;

class Snap
{
public:
	Snap();
	~Snap();
	void addSnap();
	void addFram(Mat &);
	vector<Mat> operator[](int);
private:
	vector< vector<Mat>> SnapDate;
};

