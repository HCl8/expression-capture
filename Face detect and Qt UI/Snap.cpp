#include "Snap.h"



Snap::Snap()
	:SnapDate()
{
}


Snap::~Snap()
{
}

void Snap::addSnap()
{
	SnapDate.push_back(vector<Mat>());
}

void Snap::addFram(Mat & img)
{
	SnapDate.back().push_back(img.clone());
}

vector<Mat> Snap::operator[](int index)
{
	return SnapDate[index];
}
