#include "Particle.h"

Particle::Particle() {

	this->depth = ofGetWidth() > ofGetHeight() ? ofGetWidth() : ofGetHeight();

	int x, y, z;
	int start_surface = ofRandom(6);
	switch (start_surface) 
	{
	case 0:
		// ³–Ê
		x = (int)(ofRandom(ofGetWidth()) / 40) * 40;
		y = (int)(ofRandom(ofGetHeight()) / 40) * 40;
		z = this->depth;
		break;
	case 1: 
		// ”w–Ê
		x = (int)(ofRandom(ofGetWidth()) / 40) * 40;
		y = (int)(ofRandom(ofGetHeight()) / 40) * 40;
		z = 0;
		break;
	case 2: 
		// ã–Ê
		x = (int)(ofRandom(ofGetWidth()) / 40) * 40;
		y = ofGetHeight();
		z = (int)(ofRandom(this->depth) / 40) * 40;
		break;
	case 3: 
		// ’ê–Ê
		x = (int)(ofRandom(ofGetWidth()) / 40) * 40;
		y = 0;
		z = (int)(ofRandom(this->depth) / 40) * 40;
		break;
	case 4: 
		// ‰E–Ê
		x = ofGetWidth();
		y = (int)(ofRandom(ofGetHeight()) / 40) * 40;
		z = (int)(ofRandom(this->depth) / 40) * 40;
		break;
	case 5: 
		// ¶–Ê
		x = 0;
		y = (int)(ofRandom(ofGetHeight()) / 40) * 40;
		z = (int)(ofRandom(this->depth) / 40) * 40;
		break;
	}

	this->location = ofPoint(x, y, z);
}

Particle::~Particle() {

}

void Particle::Upate() {

	if (ofGetFrameNum() % 20 == 0) {

		ofPoint directions[6];
		directions[0] = ofPoint(1, 0, 0);
		directions[1] = ofPoint(-1, 0, 0);
		directions[2] = ofPoint(0, 1, 0);
		directions[3] = ofPoint(0, -1, 0);
		directions[4] = ofPoint(0, 0, 1);
		directions[5] = ofPoint(0, 0, -1);

		if (this->location.x == 0 || this->location.x == ofGetWidth()) {

			if (this->location.y == 0 || this->location.y == ofGetHeight() || this->location.z == 0 || this->location.z == this->depth) {

				this->location.x == ofGetWidth() ? directions[0] = directions[1] : directions[1] = directions[0];
			}
			else {

				directions[0] = this->direction;
				directions[1] = this->direction;
			}
		}

		if (this->location.y == 0 || this->location.y == ofGetHeight()) {

			if (this->location.x == 0 || this->location.x == ofGetWidth() || this->location.z == 0 || this->location.z == this->depth) {

				this->location.y == ofGetHeight() ? directions[2] = directions[3] : directions[3] = directions[2];
			}
			else {

				directions[2] = this->direction;
				directions[3] = this->direction;
			}
		}

		if (this->location.z == 0 || this->location.z == this->depth) {

			if (this->location.x == 0 || this->location.x == ofGetWidth() || this->location.y == 0 || this->location.y == ofGetHeight()) {

				this->location.z == this->depth ? directions[4] = directions[5] : directions[5] = directions[4];
			}
			else {

				directions[4] = this->direction;
				directions[5] = this->direction;
			}
		}

		int r = ofRandom(6);
		this->direction = directions[r];
	}

	this->location += this->direction * 2;

	this->logs.push_front(location - ofPoint(ofGetWidth() * 0.5, ofGetHeight() * 0.5, this->depth * 0.5));
	while (this->logs.size() > 100) { this->logs.pop_back(); }
}

void Particle::Draw() {

	ofFill();
	ofDrawSphere(this->logs.front(), 3);

	ofNoFill();
	ofBeginShape();
	for (ofPoint& log : this->logs) {

		ofVertex(log);
	}
	ofEndShape();
}