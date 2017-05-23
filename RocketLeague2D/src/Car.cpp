//
//  Car.cpp
//  RocketLeague2D
//
//  Created by Rana Lulla on 15/5/2017.
//
//

#include "Car.hpp"

Car::Car()
{
    _position.x=ofGetWidth()/4;
    _position.y=ofGetHeight()/2;
}
Car::~Car(){}
void Car::Draw()
{
    ofSetColor(255, 100, 100);
    ofDrawCircle(_position, 50);
    ofSetColor(0);
    ofDrawLine(_position.x, _position.y, _position.x+horizontalAngle*50, _position.y+verticalAngle*50);
}
void Car::Update()
{
    _velocity.x/=1.03;
    _velocity.y/=1.03;
    _position.x+=_velocity.x;
    _position.y+=_velocity.y;
    if(_position.x<50||_position.x>ofGetWidth()-50)
    {
        _velocity.x*=-1;
    }
    if(_position.y<50||_position.y>ofGetHeight()-50)
    {
        _velocity.y*=-1;
    }
}
void Car::CheckCollisions(float x, float y, float velX, float velY, int mass)
{
    ofVec2f otherVel;
    otherVel.x=velX;
    otherVel.y=velY;
    _tempPos=_position;
    _tempVel=_velocity;
    if(ofDist(_position.x, _position.y, x, y)<100)
    {
//        _tempVel.x=(_velocity.x*(_mass-mass)+(2*mass*velX))/(_mass+mass);
//        _tempVel.y=(_velocity.y*(_mass-mass)+(2*mass*velY))/(_mass+mass);
        _tempVel=_position-otherVel;
        _tempVel.normalize();
        
        _tempPos.x+=_tempVel.x;
        _tempPos.y+=_tempVel.y;
    }
}
void Car::setValues()
{
    _position=_tempPos;
    _velocity=_tempVel;
}
void Car::turn(bool keyA)
{
    ofVec2f temp;
    temp.x=horizontalAngle;
    temp.y=verticalAngle;

    //Vertical
    if(horizontalAngle>0)
    {
        if(keyA)
        {
            temp.y+=turnSpeed;
        } else temp.y-=turnSpeed;
    } else if(horizontalAngle<0)
    {
        if(keyA)
        {
            temp.y-=turnSpeed;
        } else temp.y+=turnSpeed;
    } else if(verticalAngle==-1)
    {
        if(keyA)
        {
            temp.y+=turnSpeed;
        } else temp.y-=turnSpeed;
    }

    //Horizontal
    if(verticalAngle>0)
    {
        if(keyA)
        {
            temp.x-=turnSpeed;
        } else temp.x+=turnSpeed;
    } else if(verticalAngle<0)
    {
        if(keyA)
        {
            temp.x+=turnSpeed;
        } else temp.x-=turnSpeed;
    } else if(horizontalAngle==-1)
    {
        if(keyA)
        {
            temp.x+=turnSpeed;
        } else temp.x-=turnSpeed;
    }
    temp.normalize();

    verticalAngle=temp.y;
    horizontalAngle=temp.x;
}
void Car::accel(bool forward)
{
    if(forward)
    {
        _velocity.x+=horizontalAngle;
        _velocity.y+=verticalAngle;
    } else
    {
        _velocity.x-=horizontalAngle;
        _velocity.y-=verticalAngle;
    }
}

float Car::x(){return _position.x;}
float Car::y(){return _position.y;}
float Car::velX(){return _velocity.x;}
float Car::velY(){return _velocity.y;}
int Car::mass(){return _mass;}
















