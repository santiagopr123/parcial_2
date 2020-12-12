#include <iostream>
#include <canon.h>
#include <base_central.h>

using namespace std;

void problema_1();

int main()
{
    int opcion = 0;

    cout<<"este es el programa para el cual esta diseñado el parcial--> "<<endl<<"escoja la opcion de su preferencia: "<<endl;
    cout<<"ingrese el numero '1' para generar un disparo ofensivo que comprometa al canon defensivo--> "<<endl;
    cin>>opcion;





    if(opcion == 1)
    {
        float velocidad_inicial,distancia;
        float posx_1,posx_2,posy_1,posy_2;
        float angulo;

        cout<<"ingrese la velocidad inicial del proyectil-->"<<endl;

        canon ofensivo(posx_1,posy_1,distancia,angulo);
        canon defensivo(posx_2,posy_2,distancia);
        problema_1();
    }



}


void problema_1()
{

}
