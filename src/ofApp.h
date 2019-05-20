#pragma once

#include "ofMain.h"
#include "ofxBlur.h"
#include "ofxOsc.h"
#include "ofxGui.h"

#define HOST "127.0.0.1"
#define PORT 5000
//#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    
	ofxBlur blur;
    float volume;
    
    //OSC
    ofxOscReceiver receiver;
    
    bool flg;
    ofVec3f vec;
    int stop;
    
    //GUI
    ofxPanel gui;
    ofxIntSlider threshold_1;
    ofxIntSlider threshold_2;
    ofxIntSlider threshold_3;
    int init_1 = 150;
    int init_2 = 150;
    int rad_1 = 50;
    int rad_2 = 50;

};
