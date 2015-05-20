#pragma once

#include "ofMain.h"
#include "ofxEasyFboGlitch.h"
#include "blurShader.h"


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
    
    
    
    ofFbo fbo;
    ofxEasyFboGlitch fboGlitch;
    ofImage img;
    ofVideoGrabber webcam;
    blurShader blur;
    
    
    
    
    
    bool bGlitch = false;
    bool bBlur = false;
    
    
    int imgWidth, imgHeight, snapCounter, timer, offsetTimer, distance, flex;
    
    
    ofArduino ard;
    
private:
    
    void setupArduino(const int & version);
    
    void updateArduino();
    
    
    
};