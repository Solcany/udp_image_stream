#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	udpClient.Create();
	udpClient.Bind(5005);
	udpClient.SetNonBlocking(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	try
		{
			char udpMessage[BUFF_SIZE];
			udpClient.Receive(udpMessage, BUFF_SIZE);
			ofBuffer decodedBuffer;
			decodedBuffer.set(ofxIO::Base64Encoding::decode(udpMessage));
			ofLoadImage(pixels, decodedBuffer);
			texture.loadData(pixels);
	     }
			catch (const std::exception& exc)
		{
			ofLogError("ofApp::setup") << "I/O Exception: " << exc.what();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
	texture.draw(0, 0);
}

