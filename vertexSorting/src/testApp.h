#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"

#define _USE_MATH_DEFINES
#include <cmath>

#include <algorithm>
#include <vector>


#define DEGREE2RADIANS M_PI/180

class testApp : public ofBaseApp
{

public:

	void setup();
	void update();
	void draw();

		
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);

    void addPoint(int x, int y);

    vector<ofPoint> shape;	

    class pred {

    private:
        static 
        float getAngle(ofPoint const & a) {
            ofVec2f origin = ofVec2f(0,0);
            ofVec2f p = ofVec2f(a.x, a.y);

            ofVec2f o_a = p-origin; // vector between origin and p
            ofVec2f xAxis = ofVec2f(0,1);

            float angle = o_a.angle(xAxis);
            return angle;
        }

    public:
        bool operator()(ofPoint const & a, ofPoint const & b) const {
                return getAngle(a) < getAngle(b);
            }
    };

};

#endif
