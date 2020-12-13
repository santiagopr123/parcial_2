#ifndef CANON_H
#define CANON_H

class canon
{
private:

    float pos_x;
    float pos_y;
    float distancia;

public:
    canon(float px, float py, float dis);

    float getPos_x() const;
    float getPos_y() const;
    float getDistancia() const;
};

#endif // CANON_H
