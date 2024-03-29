//
//  Ball.cpp
//  RocketLeague2D
//
//  Created by Rana Lulla on 19/5/2017.
//
//

#include "Ball.hpp"

Ball::Ball()
{
    _position.x=ofGetWidth()/2;
    _position.y=ofGetHeight()/2;
}
Ball::~Ball(){};
void Ball::Update()
{
    _position.x+=_velocity.x;
    _position.y+=_velocity.y;
    _velocity.x/=1.03;
    _velocity.y/=1.03;
    if(_position.x>ofGetWidth()-25)
    {
        _velocity.x*=-1;
        _position.x=ofGetWidth()-25;
    }
    if(_position.x<25)
    {
        _velocity.x*=-1;
        _position.x=25;
    }
    if(_position.y>ofGetHeight()-25)
    {
        _velocity.y*=-1;
        _position.y=ofGetHeight()-25;
    }
    if(_position.y<25)
    {
        _velocity.y*=-1;
        _position.y=25;
    }
}
void Ball::CheckCollisions(float x, float y, float velX, float velY, int mass)
{
    _tempPos=_position;
    _tempVel=_velocity;
    if(ofDist(_position.x, _position.y, x, y)<50)
    {
        _tempVel.x=(_velocity.x*(_mass-mass)+(2*mass*velX))/(_mass+mass);
        _tempVel.y=(_velocity.y*(_mass-mass)+(2*mass*velY))/(_mass+mass);
        _tempPos.x+=_tempVel.x;
        _tempPos.y+=_tempVel.y;
    }
}
void Ball::setValues()
{
    _position=_tempPos;
    _velocity=_tempVel;
}
void Ball::Draw()
{
    ofSetColor(0);
    ofDrawCircle(_position.x, _position.y, 25);
}
void Ball::set(float x, float y, float velX, float velY)
{
    _position.x=x;
    _position.y=y;
    _velocity.x=velX;
    _velocity.y=velY;
}
float Ball::x(){return _position.x;}
float Ball::y(){return _position.y;}
float Ball::velX(){return _velocity.x;}
float Ball::velY(){return _velocity.y;}
int Ball::mass(){return _mass;}
