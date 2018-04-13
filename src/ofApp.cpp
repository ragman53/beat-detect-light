//
//  ofApp.cpp
//  Orphe-Beat-Light
//
//  Created by JUNYA KOBAYASHI on 2018/04/12.
//
#include "ofApp.h"
#include "ofxbeatdetect.h"


int ofApp_buffer_size = 1024;
int ofApp_fft_size = 512;


bool detect=true;
bool drumVisible = true;
bool snareVisible = true;
bool hihatVisible = true;

void ofApp::setup(){
    ofSetFrameRate(60);
    
    
    ofSoundStreamSetup(0, 1, this, 44100, ofApp_buffer_size, 4);
    
    oset.setup(HOST, PORT_SENDER);
    fbook.loadFont("frabk.ttf", 32, true, false);
    ofBackground(255);
    printf("testApp setup() OK!\n");
}

void ofApp::audioReceived(float* input, int bufferSize, int nChannels) {
    bd.audioReceived(input, bufferSize);
}


void ofApp::keyPressed(int key){
    
    
    if(key == 'a'){
        drumVisible = !drumVisible;
    }
    if(key == 's'){
        snareVisible = !snareVisible;
    }
    if(key == 'd'){
        hihatVisible = !hihatVisible;
    }
}

void ofApp::update() {
    
    bd.updateFFT();
    
    if(hihatVisible){
        
        oset.triggerLightWithRGBColor(0, 1, 255, 255, 255);
        oset.triggerLightWithRGBColor(0, 1, 0, 0, 0);
    }
    if(snareVisible){
        oset.triggerLightWithRGBColor(1, 1, 255, 255, 255);
        oset.triggerLightWithRGBColor(1, 1, 0, 0, 0);
    }
    
    oset.update();
}

void ofApp::draw()
{
    char str[32];
    
    
    ofSetColor(155,155,75);
    for (int i = 1; i < (int)ofApp_fft_size/2; i++){
        if(i % 16 == 0) {
            ofSetColor(200,0,0);
        } else {
            ofSetColor(155,155,75);
        }
        ofLine(10+(i*3),150,  10+(i*3),150-bd.magnitude[i]*10.0f);
        
    }
    // 列をインデックスする
    for (int i = (int)ofApp_fft_size/2,b = 1; i<ofApp_fft_size ; i++){
        if(i % 16 == 0) {
            ofSetColor(200,0,0);
        } else {
            ofSetColor(155,155,75);
        }
        ofLine(10+(b*3),300,  10+(b*3),300-bd.magnitude[i]*10.0f);
        b++;
        
    }
    
    
    
    ofSetColor(134,113,89);
    for (int i = 1; i < (int)ofApp_fft_size/2; i++){
        if(i % 16 == 0) {
            ofSetColor(200,0,0);
        } else {
            ofSetColor(134,113,89);
        }
        ofLine(10+(i*3),500,  10+(i*3),500-bd.magnitude_average[i]*10.0f);
    }
    //列をインデックスする
    for (int i = (int)ofApp_fft_size/2,b = 1; i<ofApp_fft_size ; i++){
        if(i % 16 == 0) {
            ofSetColor(200,0,0);
        } else {
            ofSetColor(134,113,89);
        }
        ofLine(10+(b*3),650,  10+(b*3),650-bd.magnitude_average[i]*10.0f);
        b++;
    }
    
    
    // Analysis Drum sound.
    if(drumVisible){
        if(bd.isBeatRange(0,2,2)){
            ofSetColor(200,0,0);
            fbook.drawString("DRUM!!",100,735);
        }else{
            ofSetColor(0,0,0);
            ofRect(100,700,200,50);
        }
    }
    
    // Analysis Snare sound.
    if(snareVisible){
        if(bd.isBeatRange(12,18,4)){
            ofSetColor(200,0,0);
            fbook.drawString("SNARE!!", 350, 735);
        }else{
            ofSetColor(0,0,0);
            ofRect(350,700,200,50);
        }
    }
    
    // Analysis hihat sound.
    if(hihatVisible){
        if(bd.isBeatRange(27,31,3)){
            ofSetColor(200,0,0);
            fbook.drawString("HiHat!!", 600, 735);
        }else{
            ofSetColor(0,0,0);
            ofRect(600,700,200,50);
        }
    }
    
}

void ofApp::keyReleased(int key){
    
}

void ofApp::mouseMoved(int x, int y){
    
}

void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::mousePressed(int x, int y, int button){
    
}

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::windowResized(int w, int h){
    
}
