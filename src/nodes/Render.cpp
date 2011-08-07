#include "Render.h"

using namespace ds;

Render::Render(int _ID, float _x, float _y, string _name)
{
    ID = _ID;
    x = _x;
    y = _y;
    name = _name;
    color.r = 0;
    color.g = 235;
    color.b = 60;

    Spread temp(new SpreadStruct);
    temp->name = "none";
    temp->data.push_back(0.0);
    input.push_back(new Pin(temp, color));

    win = ofxFensterManager::get()->createFenster(740, 100 ,640, 360, OF_WINDOW);
    win->setWindowTitle("Render");
    win->setBackgroundColor(0);
	renderWin = new RenderWindow();
	renderWin->setup();
    win->addListener(renderWin);
}

Render::~Render()
{
    ofxFensterManager::get()->deleteFenster(win);
    delete renderWin;
}

void Render::process()
{
    win->setBackgroundColor(boost::get<float>(input[0]->value->data[0]));
}
