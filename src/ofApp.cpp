#include "ofApp.h"

void ofApp::setup() {
	ofSetLogLevel(OF_LOG_VERBOSE);
	//cam.initGrabber(640, 480);
    ofSetCircleResolution(64);

    blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 4);
    
    receiver.setup(PORT);
    
    gui.setup();
    gui.add(threshold_1.setup("r", 255, 0, 255));
    gui.add(threshold_2.setup("g", 255, 0, 255));
    gui.add(threshold_3.setup("b", 255, 0, 255));
}

void ofApp::update() {
    // OSCの個数分繰り返す
    int index = 0;
    while(receiver.hasWaitingMessages()) {
        
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        string value = m.getArgAsString(index);
        volume = ofToFloat( m.getArgAsString(index));
        cout << volume << endl;
    }
    
    blur.setScale(ofMap(mouseX, 0, ofGetWidth(), 0, 10));
    blur.setRotation(ofMap(mouseY, 0, ofGetHeight(), -PI, PI));
    
}

void ofApp::draw() {
	ofBackground(0);
	
	blur.begin();
	//ofSetColor(threshold_1, threshold_2, threshold_3);
    ofSetColor(threshold_1,threshold_2,threshold_3);
    //ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    //ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,100  * sin(ofGetFrameNum()*0.01));
    //ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,100 + 10* volume);
    if(flg){
        ofDrawCircle(vec,150 + 50* sin(ofGetFrameNum()*0.01));
        ofDrawCircle(ofGetWidth()/2 + stop, ofGetHeight()/2, 150 + 50* sin(ofGetFrameNum()*0.01));
        if(stop < 300){
            stop+=1;
        }
        
        
    }else{
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,150 + 50* sin(ofGetFrameNum()*0.01));
    }
    blur.end();
    blur.draw();
    
    gui.draw();
	
	
}

void ofApp::keyPressed(int key){
    if (key==' ') {//Inputting optional rotate.
        blur.setup(ofGetWidth(), ofGetHeight(), 10, .2, 4);
    }
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    vec.x = x;
    vec.y = y;
    flg = true;
}
