#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetCircleResolution(50);
    c.Create();
    c.Connect("192.168.1.23", 12345);
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
    
    float sendingFloats[9];
    if(ball.ballHit)
    {
        int sendingOtherFloats[9]={ID, static_cast<int>(player[0].x()), static_cast<int>(player[0].y()), static_cast<int>(player[0].velX()), static_cast<int>(player[0].velY()), static_cast<int>(ball.x()), static_cast<int>(ball.y()), static_cast<int>(ball.velX()), static_cast<int>(ball.velY())};
        for(int i=0; i<9; i++)
        {
            sendingFloats[i]=sendingOtherFloats[i];
        }
    } else
    {
        int sendingOtherFloats[9]={ID, static_cast<int>(player[0].x()), static_cast<int>(player[0].y()), static_cast<int>(player[0].velX()), static_cast<int>(player[0].velY()), 0, 0, 0, 0};
        for(int i=0; i<9; i++)
        {
            sendingFloats[i]=sendingOtherFloats[i];
        }
    }
    string send;
    for(int i=0; i<9; i++)
    {
        std::ostringstream add;
        add << sendingFloats[i];
        std::string adder(add.str());
        send=send+adder+"|";
    }
    c.Send(send.c_str(), send.length());
    
    char received[100];
    c.Receive(received, 100);
    string data(received);
    std::cout<<data;
    if(data==""){} else
    {
        std::cout<<"is this even working";
        float receivedData[12];
        for(int i=0; i<12; i++)
        {
            string convert=data.substr(0, data.find_first_of("|"));
            receivedData[i]=std::stof(convert);
            data.erase(0, data.find_first_of("|")+1);
        }
        ball.set(receivedData[0], receivedData[1], receivedData[2], receivedData[3]);
        if(ID==1)
        {
            player[1].setPos(receivedData[4], receivedData[5]);
            player[1].setVel(receivedData[6], receivedData[7]);
        }
        if(ID==0)
        {
            player[1].setPos(receivedData[8], receivedData[9]);
            player[1].setVel(receivedData[10], receivedData[11]);
        }
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
