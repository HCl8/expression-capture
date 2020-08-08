#include "develop10.h"

develop10::develop10(QWidget *parent)
	: QMainWindow(parent), CNNModdel(), mutex(), snap()
{
	ui.setupUi(this);
	GB = QTextCodec::codecForName("gbk");
	this->CameraFlag = 0;
	this->nowSnapNUmber = 0;
	this->VideoFlag = 1;
	this->PVideo = NULL;
	this->buff = new uchar[1];
	this->isSnap = 0;
	ui.Slider->setMinimum(0);
	ui.Slider->setMaximum(100);

	ui.SnapList->setViewMode(QListView::IconMode);
	ui.SnapList->setIconSize(QSize(150, 80));

	connect(ui.File_Image, SIGNAL(triggered()), this, SLOT(OpenImageFile()));
	connect(ui.File_camera, SIGNAL(triggered()), this, SLOT(OpenCamera()));
	connect(ui.File_Video, SIGNAL(triggered()), this, SLOT(OpenVideo()));
	connect(ui.Slider, SIGNAL(clickValueChange()), this, SLOT(SetVideoFram()));
	connect(ui.SnapList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(PlaySnap(QListWidgetItem*)));
}

void develop10::SetUI(DetectResult result, int All,Mat original_img)
{
	//抓拍
	if (isSnap) {
		isSnap--;
		snap.addFram(original_img);
		if (isSnap == 1)
			ui.SnapList->addItem(item);
	}
	else if (SnapCondition(result))
	{
		isSnap = 90;
		snap.addSnap();
		snap.addFram(original_img);
		item = new QListWidgetItem(QIcon(QPixmap::fromImage(Mat2Qimage(original_img)).scaled(150, 80)),
			QString::number(nowSnapNUmber) + Lable[findMax(result.Percent)]);
		nowSnapNUmber++;
	}

	//设置热点图
	ui.HotMap->clearPoint();
	for (auto i : result.point)
		ui.HotMap->addPoint(i);

	//设置进度条
	int *Percent = result.Percent;
	ui.progressBar0->setMaximum(All);
	ui.progressBar0->setValue(Percent[0]);
	ui.progressBar1->setMaximum(All);
	ui.progressBar1->setValue(Percent[1]);
	ui.progressBar2->setMaximum(All);
	ui.progressBar2->setValue(Percent[2]);
	ui.progressBar3->setMaximum(All);
	ui.progressBar3->setValue(Percent[3]);
	ui.progressBar4->setMaximum(All);
	ui.progressBar4->setValue(Percent[4]);
	ui.progressBar5->setMaximum(All);
	ui.progressBar5->setValue(Percent[5]);
	ui.progressBar6->setMaximum(All);
	ui.progressBar6->setValue(Percent[6]);
}

void develop10::PrintImage(Mat image)
{
	delete buff;
	cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
	buff = new uchar[image.rows * image.cols * image.channels()];
	QImage Qimage(buff, image.cols, image.rows, QImage::Format_RGB888);
	memcpy(Qimage.bits(), image.data, image.rows * image.cols * 3);
	ui.SCREEN->PrintPicture(Qimage);
}

QImage develop10::Mat2Qimage(Mat image)
{
	cv::cvtColor(image, image, cv::COLOR_BGR2RGB);
	buff = new uchar[image.rows * image.cols * image.channels()];
	QImage Qimage(buff, image.cols, image.rows, QImage::Format_RGB888);
	memcpy(Qimage.bits(), image.data, image.rows * image.cols * 3);
	return Qimage;
}

bool develop10::SnapCondition(DetectResult & result)
{
	for (int i = 0; i < 6; i++)
		if ((double)result.Percent[i] / result.Count > 0.95)
			return true;
	return false;
}

int develop10::findMax(int *in)
{
	//for (int i = 0; i < 7; i++)
	//	cout << in[i] << "\t";
	//cout << endl;
	int max = *in;
	int count = 0;
	for (int i = 1; i < 7; i++)
		if (in[i] > max) {
			max = in[i];
			count = i;
		}
	return count;
}

void develop10::OpenCamera()
{
	if (CameraFlag) {
		CameraFlag = 0;
		return;
	}
	CameraFlag = 1;
	VideoCapture camera(0);
	Mat fram;
	this->CNNModdel.Fact = 0.25;
	this->CNNModdel.Unfact = 4;
	int width = camera.get(cv::CAP_PROP_FRAME_WIDTH);
	int heigh = camera.get(cv::CAP_PROP_FRAME_HEIGHT);
	ui.HotMap->setGSize(width, heigh);
	for (;;)
	{
		camera >> fram;
		DetectResult result = this->CNNModdel.Handle(fram);
		this->SetUI(result, result.Count, fram);
		PrintImage(result.process_img);
		cv::waitKey(1);
		if (!CameraFlag)
			break;
	}
	this->CNNModdel.Fact = 1;
	this->CNNModdel.Unfact = 1;
}

void develop10::OpenVideo()
{
	if (!this->VideoFlag) {
		this->VideoFlag = 1;
		return;
	}
	this->VideoFlag = 0;
	this->CNNModdel.Fact = 1;
	this->CNNModdel.Unfact = 1;
	Mat Fram;
	QString tittle = QString::fromLocal8Bit("选择文件");
	QString Path = QFileDialog::getOpenFileName(this, tittle);
	string CPath = GB->fromUnicode(Path);
	VideoCapture Video(CPath);
	this->PVideo = &Video;
	this->AllFram = Video.get(cv::CAP_PROP_FRAME_COUNT);
	this->VideoFramNumber = 0;
	
	int width = Video.get(cv::CAP_PROP_FRAME_WIDTH);
	int heigh = Video.get(cv::CAP_PROP_FRAME_HEIGHT);
	ui.HotMap->setGSize(width, heigh);

	while (!this->VideoFlag)
	{
		Video >> Fram;
		DetectResult result = this->CNNModdel.Handle(Fram);
		this->SetUI(result, result.Count,Fram);
		PrintImage(result.process_img);
		if ((double)this->VideoFramNumber / this->AllFram * 100 != ui.Slider->value())
			ui.Slider->setValue((double)this->VideoFramNumber / this->AllFram * 100);
		VideoFramNumber++;
		cv::waitKey(20);
	}
	this->CNNModdel.Fact = 1;
	this->CNNModdel.Unfact = 1;
	this->PVideo = NULL;
}

void develop10::SetVideoFram()
{
	Mat fram;
	if (this->PVideo) {
		this->VideoFramNumber = this->AllFram * ui.Slider->value() / 100;
		*this->PVideo >> fram;
		VideoFramNumber++;
		PrintImage(fram);
		(*PVideo).set(cv::CAP_PROP_POS_FRAMES, this->VideoFramNumber);
	}
}

void develop10::PlaySnap(QListWidgetItem * item)
{
	QString tex = item->text();
	QStringList par = tex.split(' ');
	int ss = par[0].toInt();
	ShowSnap* ssnap = new ShowSnap();
	ssnap->show();
	ssnap->Play(snap[ss]);
}

void develop10::OpenImageFile()
{
	QString tittle = QString::fromLocal8Bit("选择文件");
	QString Path = QFileDialog::getOpenFileName(this, tittle);
	string CPath = GB->fromUnicode(Path);
	Mat image = cv::imread(CPath);
	ui.HotMap->setGSize(image.cols, image.rows);
	DetectResult result = this->CNNModdel.Handle(image);
	this->SetUI(result, result.Count, image);
	PrintImage(result.process_img);
}
