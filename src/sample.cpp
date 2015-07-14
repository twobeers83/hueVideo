

#include "sample.h"
#include "ofMain.h"
#include "ofApp.h"

Sample::Sample(){
}

void Sample::setup(){
    x = 200;// ofGetWindowWidth()/2;
    y = 200; // ofGetWindowHeight()/2;
    w = 50;
    h = 50;
    
    number = 1;
    
    color_wireframe.set(0);
    
    int samplePix[3];
}


void Sample::update(){
    
    
    
    
    
}

void Sample::draw(){
    
    ofNoFill();
    ofRect(x, y, w, h);
    ofDrawBitmapString(ofToString(number), x+5, y+15);
    
    
    
}

void Sample::sampling(ofImage frame) {
    
    frame.crop(x, y, w, h);
    
    int newW = w;
    int newH = h;
    
    while(newH > 1) {
        newH = newH/2;
        if(newW > 1) {
            newW = newW/2;
        }
        frame.resize(newW, newH);
        
    }
    
    unsigned char* pixels = frame.getPixels();
    
    color_sample.set(r, g, b);
    r = (int)pixels[15];
    g = (int)pixels[79];
    b = (int)pixels[80];
    
    
     cout << "r=" << r << " g=" << g << " b=" << b << endl;
    
}