#include "testApp.h"

bool _compare_min_x(ofPoint const &p1, ofPoint const &p2) { return p1.x < p2.x; }
bool _compare_min_y(ofPoint const &p1, ofPoint const &p2) { return p1.y < p2.y; }

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(225,255,255);
	ofNoFill();
	//ofEnableAlphaBlending ();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255,0,0);
	ofBeginShape();
	int size = this->points.size();
	for (int i = 0; i < size; ++i) {
		ofPoint p = points[i];
		ofVertex(p.x, p.y);
	}
	ofEndShape();

	ofSetColor(0,0,0);
	float min_x=0, min_y=0, max_x=0, max_y=0;
	if(points.size()>1) {
		min_x = (*std::min_element(points.begin(), points.end(), &_compare_min_x)).x;
		min_y = (*std::min_element(points.begin(), points.end(), &_compare_min_y)).y;
		max_x = (*std::max_element(points.begin(), points.end(), &_compare_min_x)).x;
		max_y = (*std::max_element(points.begin(), points.end(), &_compare_min_y)).y;

		ofEllipse(min_x, min_y, 5,5);
		ofEllipse(max_x, max_y, 5,5);
		ofDrawBitmapString("min_x, min_y", min_x-45, min_y-8);
		ofDrawBitmapString("max_x, max_y", max_x-45, max_y+8);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	this->points.push_back(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	this->points.clear();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
