#include "testApp.h"

void testApp::setup()
{

    ofBackground(100,0,0);

    int n = 5;
    shape.clear();
    for(int i=0; i<n; i++) {
        float angle = ofMap(i, 0, n, 0, 360);
        float x = cos( DEGREE2RADIANS * angle ) * 150;
        float y = sin( DEGREE2RADIANS * angle ) * 150;
        shape.push_back(ofPoint(x,y));
        
    cout << i << " " << shape[i] << endl;
    }
}

void testApp::update()
{
}

void testApp::draw()
{
    ofTranslate(ofGetViewportWidth()/2, ofGetViewportHeight()/2);
    ofFill();
    int i;

    for(i=0; i<shape.size()-1; i++) {
        ofSetColor(50,50,200);
        ofCircle(shape[i].x, shape[i].y, 5);
        ofLine(shape[i+1].x, shape[i+1].y, shape[i].x, shape[i].y);

        ofSetColor(200);
        ofDrawBitmapString(ofToString(i), shape[i].x+5, shape[i].y+5);
    }
    ofSetColor(50,50,200);
    ofCircle(shape[i].x, shape[i].y, 5);
    ofLine(shape[0].x, shape[0].y, shape[i].x, shape[i].y);

    ofSetColor(200);
    ofDrawBitmapString(ofToString(i), shape[i].x+5, shape[i].y+5);
}

void testApp :: addPoint(int x, int y) {
    shape.push_back(ofPoint(x-ofGetViewportWidth()/2, y-ofGetViewportHeight()/2));
    std::sort(shape.begin(), shape.end(), pred());
}


void testApp :: keyPressed( int key )
{

}

void testApp :: keyReleased( int key )
{

}

void testApp :: mouseMoved( int x, int y )
{

}

void testApp :: mouseDragged( int x, int y, int button )
{
}

void testApp :: mousePressed( int x, int y, int button )
{
    addPoint(x,y);
}

void testApp :: mouseReleased( int x, int y, int button )
{
}

void testApp :: windowResized( int w, int h )
{
}

