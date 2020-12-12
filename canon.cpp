#include "canon.h"
canon::canon(float px, float py, float dis)
{
    pos_x = px;
    pos_y = py;

    gravedad = 9.81;
    pi = 3.1416;
    distancia = dis;
}


float canon::getPos_x() const
{
    return pos_x;
}

void canon::setPos_x(float value)
{
    pos_x = value;
}

float canon::getPos_y() const
{
    return pos_y;
}

void canon::setPos_y(float value)
{
    pos_y = value;
}

float canon::getVel_inicial() const
{
    return vel_inicial;
}

void canon::setVel_inicial(float value)
{
    vel_inicial = value;
}

float canon::getDistancia() const
{
    return distancia;
}

void canon::setDistancia(float value)
{
    distancia = value;
}

float canon::getAngulo() const
{
    return angulo;
}

void canon::setAngulo(float value)
{
    angulo = value;
}


