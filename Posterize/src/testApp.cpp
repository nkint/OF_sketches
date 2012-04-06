#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	cout << "Opencv version " << CV_MAJOR_VERSION << "." << CV_MINOR_VERSION << endl;

	image.loadImage("lena.jpg");

	Posterizer p;
	poster = p.posterize(image, 8);
	cout << "testApp::setup got posterized" << endl;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	image.draw(0,0);
	poster.draw(image.width, 0);
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
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
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
