#ifndef CANON_H
#define CANON_H

class canon
{
private:

    float pos_x;
    float pos_y;
    float vel_inicial;
    float distancia;
    float angulo;

public:
    canon(float px, float py, float dis);
    canon(float px, float py, float dis, float angle);

    float getPos_x() const;
    float getPos_y() const;
    float getVel_inicial() const;
    float getDistancia() const;
    float getAngulo() const;
};

#endif // CANON_H
