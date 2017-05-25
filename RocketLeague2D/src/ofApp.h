#pragma once

#include "ofMain.h"
#include "Car.hpp"
#include "Ball.hpp"
#include "ofxNetwork.h"
#include <iostream>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    private:
        bool W, A, S, D;
        Car player[2];
        Ball ball;
        ofxUDPManager c;
        ofxUDPManager s;
        int ID=0;
};
