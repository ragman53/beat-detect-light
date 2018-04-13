
#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGlutWindow.h"

int main(){
    
    ofAppGlutWindow window;
    ofSetupOpenGL(&window, 1000,700, OF_WINDOW);
    
    //ofSetupOpenGL(700,580, OF_FULLSCREEN);
    //ofHideCursor();
    
    
    ofRunApp(new ofApp());
    
}

