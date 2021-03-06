#pragma once

#include "ofMain.h"
#include "ofxHTTP.h"
#include "ofxJSON.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    
    // Video
    ofVideoPlayer video;
    float ratio;
    ofRectangle screen;
    int videoSpeed;
    
    // Sampling
    int sampleNum;
    int sampleSize;
    ofRectangle sampleGlobal;
    float smoothing;
    vector<ofRectangle> samples; // replace with ofRectangle
    vector<ofColor> sampleColor;
    vector<ofColor> averageColor;
    vector<ofColor> hueColor;
    ofRectangle samplingArea;
    ofRectangle samplingAreaPrevious;
    ofVec2f samplingAreaCenter;
    
    ofColor getAverageColor(ofRectangle sample, ofPixels frame);
    
    // Hue
    bool isHueOn;
    float hueUpdateDecisecond;
    long hueUpdateTimer;
    int hueUpdateLast;
    std::string hueBridgeIP;
    std::string hueUser;
    
    ofx::HTTP::DefaultClient client;
    ofx::HTTP::Context context;
    ofx::HTTP::BaseResponse response;
    
    ofBuffer bodyBuffer;
    
    void hueGet(string hueGetObject);
    void hueSetup(int hueGroupNum);
    void hueSetColor(int bulbNum, ofColor color, int transitionTime);
    void hueOffAll(int hueGroupNum);
};
