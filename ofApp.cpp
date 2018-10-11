#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetColor(239);
	ofEnableDepthTest();

	for (int i = 0; i < 255; i++) { this->particles.push_back(Particle()); }
}
//--------------------------------------------------------------
void ofApp::update() {

	for (Particle& particle : particles) { particle.Upate(); }
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.25);

	for (Particle& particle : particles) { particle.Draw(); }

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}