#pragma once

#include "ofMain.h"
#include "ofxNetwork.h"
#include "ofxIO.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		int BUFF_SIZE = 65536;
		ofxUDPManager udpClient;
		
	    ofPixels pixels;
        ofTexture texture;		
};
