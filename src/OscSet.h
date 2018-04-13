
#pragma once

#include "ofMain.h"
#include "ofxOsc.h"


class OscSet {
private:
   
public:
    
    OscSet() = default;
    ~OscSet() = default;

    
    void setup(string host, int portSender);
    void update();
    
    void triggerLightWithRGBColor(int LorRorBOTH,int lightNum, int r, int g, int b);
    void setLightOn(int LorRorBOTH,int lightNum);
    void setLightOff(int LorRorBOTH,int lightNum);
    ofxOscSender sender;
};

