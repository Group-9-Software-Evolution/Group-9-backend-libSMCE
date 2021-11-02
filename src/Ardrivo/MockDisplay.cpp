//
// Created by ziggy on 2021-10-13.
//

#include "MockDisplay.h"

MockDisplayClass::MockDisplayClass(int width, int height) :
    ArduinoGraphics(width, height),
    screen(width, std::vector<std::vector<uint8_t>>(height, std::vector<uint8_t>(3, 0)))
{
}

MockDisplayClass::~MockDisplayClass() {}

void MockDisplayClass::beginDraw() { ArduinoGraphics::beginDraw(); }

void MockDisplayClass::endDraw() { ArduinoGraphics::endDraw(); }

void MockDisplayClass::set(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
    screen[x][y].clear();
    screen[x][y].push_back(b);
    screen[x][y].push_back(g);
    screen[x][y].push_back(r);
}
