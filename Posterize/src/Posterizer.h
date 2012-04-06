#ifndef POSTERIZER_H_
#define POSTERIZER_H_

#include "ofMain.h"
#include "ofxCv.h"

#define NONE 0
#define NORMAL 1
#define PRESERVE_EDGES 2

class Posterizer {
public:
	Posterizer();
	virtual ~Posterizer();

	ofImage posterize(ofImage image, int K);

	void setBlurMode(int n);

private:
	int blurMode;
	bool toGray;

    cv::Mat segment(cv::Mat src, int K);
};

#endif /* POSTERIZER_H_ */
