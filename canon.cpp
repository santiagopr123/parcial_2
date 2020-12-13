#include "canon.h"

canon::canon(float px, float py, float dis)
{
    pos_x = px;
    pos_y = py;
    distancia = dis;
}

float canon::getPos_x() const
{
    return pos_x;
}

float canon::getPos_y() const
{
    return pos_y;
}

float canon::getDistancia() const
{
    return distancia;
}
