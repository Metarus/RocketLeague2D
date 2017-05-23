#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update()
{
    if(d&&!a)
    {
        player.turn(true);
    }
    if(!d&&a)
    {
        player.turn(false);
    }
    if(w&&!s)
    {
        player.accel(true);
    }
    if(!w&&s)
    {
        player.accel(false);
    }
    player.Update();
    ball.Update();
    player.CheckCollisions(ball.x(), ball.y(), ball.velX(), ball.velY(), ball.mass());
    ball.CheckCollisions(player.x(), player.y(), player.velX(), player.velY(), player.mass());
    player.setValues();
    ball.setValues();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(255);
    player.Draw();
    ball.Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key=='d')
    {
        d=true;
    }
    if(key=='a')
    {
        a=true;
    }
    if(key=='w')
    {
        w=true;
    }
    if(key=='s')
    {
        s=true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if(key=='d')
    {
        d=false;
    }
    if(key=='a')
    {
        a=false;
    }
    if(key=='w')
    {
        w=false;
    }
    if(key=='s')
    {
        s=false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
