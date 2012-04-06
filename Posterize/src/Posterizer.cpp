#include "Posterizer.h"

using namespace ofxCv;

Posterizer::Posterizer():
	blurMode(PRESERVE_EDGES),
	toGray(false){
}

Posterizer::~Posterizer() {
	// TODO Auto-generated destructor stub
}

Mat Posterizer::segment(Mat src, int K) {
	int cols = src.cols;
	int rows = src.rows;
	int numpix = cols*rows;
	Mat clustered, colored, bestLabels, centers, samples;

	int colors[K];
	for(int i = 0;i < K;i++){
		colors[i] = 255 / (i + 1);
	}

	if(src.channels()==1) {
		samples = Mat::zeros(cols*rows, 1, CV_32F);

		for(int i = 0;i < numpix;i++){
			samples.at<float>(i, 0) = src.data[i] / 255.0;
		}
	}
    if(src.channels()==3) {
    	vector<Mat> bgr;

    	cv::split(src, bgr);
    	samples = Mat::zeros(cols*rows, 3, CV_32F);

    	// i think there is a better way to split pixel bgr color
    	for(int i = 0;i < numpix;i++){
    		samples.at<float>(i, 0) = bgr[0].data[i] / 255.0;
    		samples.at<float>(i, 1) = bgr[1].data[i] / 255.0;
    		samples.at<float>(i, 2) = bgr[2].data[i] / 255.0;
    	}
    }

    cv::kmeans(samples, K, bestLabels,
			TermCriteria( CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 10, 1.0),
			3, KMEANS_PP_CENTERS, centers);

    // i think there is a better way to do this mayebe some Mat::reshape?
    clustered = Mat(rows, cols, CV_32F);
    for(int i = 0;i < numpix;i++){
        int label = bestLabels.at<int>(0, i);
        clustered.at<float>(i / cols, i % cols) = (float)((colors[label]));
    }
    clustered.convertTo(clustered, CV_8U);

    return clustered;
}

ofImage Posterizer::posterize(ofImage image, int K) {
	Mat src, _src = toCv(image);
	Mat clustered, colored;
	ofImage dst;

	if(blurMode == NONE) src = _src;
	else if(blurMode == NORMAL) blur(_src, src, Size(5,5));
	else if(blurMode == PRESERVE_EDGES) bilateralFilter(_src, src, 10, 80, 5);
	else {
		assert(false);
	}

	if(this->toGray) cvtColor(src, src, CV_BGR2GRAY);

	clustered = segment(src, K);

	erode(clustered,clustered, Mat());
	dilate(clustered, clustered, Mat());

	colored = Mat(src.rows, src.cols, CV_8UC3);
	for(int i = 0;i < K;i++){
		Mat mask;
		Scalar meanColor;
		int color = 255 / (i + 1);

		inRange(clustered, color - 1, color + 1, mask);
		meanColor = cv::mean(src, mask);

		if(src.channels() == 1) {
			meanColor = Scalar(meanColor[0], meanColor[0], meanColor[0]);
		}

		colored.setTo(meanColor, mask);
	}

    dst.setFromPixels(colored.data, colored.cols, colored.rows, OF_IMAGE_COLOR);

	return dst;
}

void Posterizer::setBlurMode(int n)
{
	this->blurMode = n;
}




