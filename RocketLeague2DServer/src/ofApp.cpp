#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    s.Create();
    s.SetEnableBroadcast(true);
    s.Bind(12345);
    s.SetNonBlocking(true);
}

//--------------------------------------------------------------
void ofApp::update()
{
    char received[100];
    s.Receive(received, 100);
    string data(received);
    if(data==""){} else
    {
        float receivedData[9];
        for(int i=0; i<9; i++)
        {
            string convert=data.substr(0, data.find_first_of("|"));
            receivedData[i]=std::stof(convert);
            data.erase(0, data.find_first_of("|")+1);
        }
        car[(int)receivedData[0]].setPos(receivedData[1], receivedData[2]);
        car[(int)receivedData[0]].setVel(receivedData[3], receivedData[4]);
        if(receivedData[5]!=0&&receivedData[6]!=0)
        {
            ball.set(receivedData[5], receivedData[6], receivedData[7], receivedData[8]);
        }
    }
    
    car[0].Update();
    car[1].Update();
    ball.Update();
    
    int sendingFloats[12]={static_cast<int>(ball.x()), static_cast<int>(ball.y()), static_cast<int>(ball.velX()), static_cast<int>(ball.velY()), static_cast<int>(car[0].x()), static_cast<int>(car[0].y()), static_cast<int>(car[0].velX()), static_cast<int>(car[0].velY()), static_cast<int>(car[1].x()), static_cast<int>(car[1].y()), static_cast<int>(car[1].velX()), static_cast<int>(car[1].velY())};
    string send;
    for(int i=0; i<12; i++)
    {
        std::ostringstream add;
        add << sendingFloats[i];
        std::string adder(add.str());
        send=send+adder+"|";
    }
    std::cout<<send;
    s.Send(send.c_str(), send.length());
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(255);
    car[0].Draw();
    car[1].Draw();
    ball.Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
