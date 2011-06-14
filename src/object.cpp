#include "object.h"

object::object()
{
    ofAddListener(ofEvents.draw, this, &object::draw);
}

object::~object()
{
    ofRemoveListener(ofEvents.draw, this, &object::draw);
}

void object::draw(ofEventArgs & args)
{
    ofSetColor(255,230,0,255);
    ofRect(x,y,width,height);
    for(int j = 0; j < input.size(); j++)
    {
        ofSetColor(80,80,80,255);
        ofRect(x+(j*8),y,8,8);
        ofSetColor(255,230,0,255);
        ofRect(x+(j*8),y,7,7);
    }
    ofSetColor(0,0,0,255);
    ofDrawBitmapString(name, x+2, y+20);
    for(int j = 0; j < output.size(); j++)
    {
        ofSetColor(80,80,80,255);
        ofRect(x+(j*8),y+height-8,8,8);
        ofSetColor(255,230,0,255);
        ofRect(x+(j*8),y+height-7,7,7);
    }
}

void object::process()
{
    //STUB
}
