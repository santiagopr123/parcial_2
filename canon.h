#ifndef CANON_H
#define CANON_H


class canon
{
private:

    float pos_x;
    float pos_y;
    float vel_inicial;
    float gravedad;
    float pi;
    float distancia;
    float angulo;

public:
    canon(float px, float py, float dis, float angle);

    float getPos_x() const;
    void setPos_x(float value);
    float getPos_y() const;
    void setPos_y(float value);
    float getVel_inicial() const;
    void setVel_inicial(float value);
    float getDistancia() const;
    void setDistancia(float value);
    float getAngulo() const;
    void setAngulo(float value);
};

#endif // CANON_H
