#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetCircleResolution(50);
    c.Create();
    c.Bind(12345);
    c.SetNonBlocking(true);
}

//--------------------------------------------------------------
void ofApp::update()
{
    if(D&&!A)
    {
        player[0].turn(true);
    }
    if(!D&&A)
    {
        player[0].turn(false);
    }
    if(W&&!S)
    {
        player[0].accel(true);
    }
    if(!W&&S)
    {
        player[0].accel(false);
    }
    player[0].Update();
    ball.Update();
    player[0].CheckCollisions(ball.x(), ball.y(), ball.velX(), ball.velY(), ball.mass());
    ball.CheckCollisions(player[0].x(), player[0].y(), player[0].velX(), player[0].velY(), player[0].mass());
    player[0].setValues();
    ball.setValues();
    
    int number;
    float sendingFloats[9];
    if(ball.ballHit)
    {
        float sendingOtherFloats[9]={static_cast<float>(ID), player[0].x(), player[0].y(), player[0].velX(), player[0].velY(), ball.x(), ball.y(), ball.velX(), ball.velY()};
        for(int i=0; i<9; i++)
        {
            sendingFloats[i]=sendingOtherFloats[i];
        }
        number=9;
    } else
    {
        float sendingOtherFloats[5]={static_cast<float>(ID), player[0].x(), player[0].y(), player[0].velX(), player[0].velY()};
        for(int i=0; i<9; i++)
        {
            sendingFloats[i]=sendingOtherFloats[i];
        }
        number=5;
    }
    string sending;
    for(int i=0; i<number; i++)
    {
        std::ostringstream add;
        add << sendingFloats[i];
        std::string adder(add.str());
        sending=sending+"|"+adder;
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(255);
    player[0].Draw();
    ball.Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key=='d')
    {
        D=true;
    }
    if(key=='a')
    {
        A=true;
    }
    if(key=='w')
    {
        W=true;
    }
    if(key=='s')
    {
        S=true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if(key=='d')
    {
        D=false;
    }
    if(key=='a')
    {
        A=false;
    }
    if(key=='w')
    {
        W=false;
    }
    if(key=='s')
    {
        S=false;
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
