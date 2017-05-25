//
//  Car.hpp
//  RocketLeague2D
//
//  Created by Rana Lulla on 15/5/2017.
//
//

#ifndef Car_hpp
#define Car_hpp

#include <stdio.h>
#include "ofMain.h"

class Car
{
    public:
        Car();
        ~Car();
        void Draw();
        void Update();
        void CheckCollisions(float x, float y, float velX, float velY, int mass);
        void setValues();
        void turn(bool keyA);
        void accel(bool forward);
        void setVel(float x, float y);
        float x();
        float y();
        float velX();
        float velY();
        int mass();
    private:
        int _mass=5;
        float verticalAngle=0;
        float horizontalAngle=1;
        float turnSpeed=0.06;
        ofVec2f _velocity;
        ofVec2f _position;
        ofVec2f _tempVel;
        ofVec2f _tempPos;
    
};

#endif /* Car_hpp */
