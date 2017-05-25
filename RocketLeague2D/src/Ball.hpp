//
//  Ball.hpp
//  RocketLeague2D
//
//  Created by Rana Lulla on 19/5/2017.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "ofMain.h"

class Ball
{
    public:
        bool ballHit;
        Ball();
        ~Ball();
        void Update();
        void CheckCollisions(float x, float y, float velX, float velY, int mass);
        void set(float x, float y, float velX, float velY);
        void setValues();
        void Draw();
        float x();
        float y();
        float velX();
        float velY();
        int mass();
    private:
        int _mass=1;
        ofVec2f _velocity;
        ofVec2f _position;
        ofVec2f _tempVel;
        ofVec2f _tempPos;
};

#endif /* Ball_hpp */
