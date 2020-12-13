#include "canon.h"
canon::canon(float px, float py, float dis)
{
    pos_x = px;
    pos_y = py;
    distancia = dis;
}

canon::canon(float px, float py, float dis, float angle)
{
    pos_x = px;
    pos_y = py;
    distancia = dis;
    angulo = angle;
}


float canon::getPos_x() const
{
    return pos_x;
}


float canon::getPos_y() const
{
    return pos_y;
}


float canon::getVel_inicial() const
{
    return vel_inicial;
}


float canon::getDistancia() const
{
    return distancia;
}

