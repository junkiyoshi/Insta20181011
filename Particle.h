#pragma once
#include "ofMain.h"

class Particle {
public:
	Particle();
	~Particle();
	void Upate();
	void Draw();

private:

	int depth;

	ofPoint location;
	ofPoint direction;
	std::deque<ofPoint> logs;
};