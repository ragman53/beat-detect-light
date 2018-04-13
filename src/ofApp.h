#ifndef _ON_APP
#define _ON_APP


#include "ofMain.h"
#include "ofxbeatdetect.h"
#include "OscSet.h"

#define HOST "local"
#define PORT_SENDER 4321

#define DEFAULT_LIGHT_NUM 0

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    ofTrueTypeFont  fbook;
    void audioReceived(float* input, int bufferSize, int nChannels);
    
    
    
    
    ofxbeatdetect bd;
    OscSet oset;
};

#endif
