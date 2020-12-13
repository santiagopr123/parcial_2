#ifndef BASE_CENTRAL_H
#define BASE_CENTRAL_H
#include <canon.h>
#include <math.h>
#include <iostream>
using namespace std;

class base_central
{
private:
    float pi;
    float gravedad;

public:
    base_central();

    void resultados(int t,float a,float px, float py, float v,float d);
    void disparo_ofensivo(canon defensivo, canon ofensivo, float velocidad_inicial);
    void disparo_defensivo(canon defensivo, canon ofensivo, float velocidad_inicial);
    void disparo_ofensivo_defensivo(canon defensivo, canon ofensivo, float velocidad_inicial,float velocidad_inicial_2);
    void disparo_ofensivo_defensivo_2(canon defensivo, canon ofensivo, float velocidad_inicial,float velocidad_inicial_2);

};

#endif // BASE_CENTRAL_H
