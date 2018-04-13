//
//  OscSet.cpp
//  Orphe-Beat-Light
//
//  Created by JUNYA KOBAYASHI on 2018/04/12.
//

#include "OscSet.h"


void OscSet::setup(string host, int portSender)
{
    
    sender.setup(host, portSender);

}

void OscSet::update(){

}

void OscSet::triggerLightWithRGBColor(int LorRorBOTH, int lightNum, int r, int g, int b){
    
    ofxOscMessage m;
    
    if(LorRorBOTH==0){
        m.setAddress("/LEFT/triggerLightWithRGBColor");
    }else if(LorRorBOTH==1){
        m.setAddress("/RIGHT/triggerLightWithRGBColor");
    }else if(LorRorBOTH==2){
        m.setAddress("/BOTH/triggerLightWithRGBColor");
    }
    
    m.addIntArg(lightNum);
    
    m.addIntArg(r);
    m.addIntArg(g);
    m.addIntArg(b);
    
    sender.sendMessage(m);
    
}

void OscSet::setLightOn(int LorRorBOTH, int lightNum){
    ofxOscMessage m;
    
    m.setAddress("/BOTH/setLightOn");
    m.addIntArg(lightNum);
    
    sender.sendMessage(m);
}

void OscSet::setLightOff(int LorRorBOTH, int lightNum){
    ofxOscMessage m;
    
    m.setAddress("BOTH/setLightOff");
    m.addIntArg(lightNum);
    
    sender.sendMessage(m);
}
