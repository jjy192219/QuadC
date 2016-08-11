#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //----------------------setting up firmata and arduino--------------------------------------------
    
    //    ard.connect("/dev/tty.usbmodem1411", 57600);
    
//    ard.connect("/dev/tty.usbserial-DA00VPDQ", 57600);
    ard.connect("/dev/cu.usbmodem1411", 9600);
    
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    //------------------------------------------------------------------
    
    blur.setup(ofGetWidth(),ofGetHeight());
    
    fbo.allocate(ofGetWidth(),ofGetHeight());
    
    snapCounter = 0;
    
    webcam.setVerbose(true);
    webcam.setDeviceID(0);
    webcam.initGrabber(ofGetWidth(),ofGetHeight());
    
    ofSetFrameRate(60);
    
    fboGlitch.allocate(ofGetWidth(), ofGetHeight());
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    webcam.update();
    
    //-----------------update arduino-------------------------------------
    
    updateArduino();
    
//    distance = ard.getAnalog(7);
//    flex = ard.getAnalog(8);
//
//    
//    cout<<"distance: " + ofToString(distance) + "CM"<<endl;
//    cout<<"flex: " + ofToString(flex) <<endl;
//    
//    if(flex>=670){
//    
//        offsetTimer = ofGetElapsedTimef();
//        
//        bGlitch = true;
//
//    
//    }

    
//using tilt sensor instead
    distance = ard.getAnalog(7);
    hit = ard.getAnalog(6);
    
    
    cout<<"distance: " + ofToString(distance) + "CM"<<endl;
    cout<<"Hit: " + ofToString(hit) <<endl;
    
    if(hit>500){
        
        offsetTimer = ofGetElapsedTimef();
        
        bGlitch = true;
        
        
    }
}


void ofApp::setupArduino(const int & version) {
    
    
    
}
//--------------------------------------------------------------

void ofApp::updateArduino(){
    
    ard.update();
    
}



//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    timer = ofGetElapsedTimef();
    cout<<"timer is: "+ofToString(timer)<<endl;
    
    
    if (bGlitch == true) {
        
        int offset = timer - offsetTimer;
        if (offset >= 3) {
            bGlitch = false;
            offset = 0;
            
        }
        else{
            
            fbo.begin();
            
            webcam.draw(0,0);
            
            //draw "fboGlitch" image
            
            fbo.end();
            
            fbo.draw(0, 0,ofGetWidth(),ofGetHeight());
            fboGlitch.draw(fbo, 0, 0, ofGetWidth(), ofGetHeight());
            
        }
        
        
        
    }
    else {
        
        //----------------------------- distance mapping-----------------------------
        
        if (distance<=100) {
            blur.begin();
            blur.amount = ofMap((100-distance),0,90,0,10,true);
            cout<<blur.amount<<endl;
            blur.iterations = ofMap((100-distance),0,90,1,10,true);
            webcam.draw(0,0);
            blur.end();
            

        }
        else{
            
            blur.begin();
            blur.amount = (0,true);
            blur.iterations = (1,true);
            webcam.draw(0,0);
            blur.end();
            
            
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'g') {
        offsetTimer = ofGetElapsedTimef();
        
        bGlitch = true;
    }
    if (key == 'c') {
        snapCounter++;
        img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        img.saveImage("screenShot"+ofToString(10000+snapCounter)+".png");
    };
    
}





//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}

