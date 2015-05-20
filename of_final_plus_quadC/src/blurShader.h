//
//  blurShader.h
//  of_final_plus_quadC
//
//  Created by Eric Jiang on 5/17/15.
//
//

#pragma once

#include "ofMain.h"


class blurShader {
public:
    
    void setup(float w, float h);
    void begin(int amount=5, int iterations=2);
    void end();
    void draw(float x=0, float y=0, float w=0, float h=0);
    
    int iterations, amount;
    
    ofFbo fbo1,fbo2;
    ofShader hShader, vShader;
};