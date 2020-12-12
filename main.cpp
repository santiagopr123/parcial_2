#include <iostream>
#include <canon.h>
#include <base_central.h>

using namespace std;

void problema_1(canon ofe, canon defe, base_central base, float veli);

int main()
{
    int opcion = 0;
    base_central centro;

    cout<<"este es el programa para el cual esta diseñado el parcial--> "<<endl<<"escoja la opcion de su preferencia: "<<endl;
    cout<<"ingrese el numero '1' para generar un disparo ofensivo que comprometa al canon defensivo--> "<<endl;
    cin>>opcion;





    if(opcion == 1)
    {
        float velocidad_inicial,distancia;
        float posx_1 = 0,posx_2,posy_1 = 0,posy_2;

        cout<<"ingrese la velocidad inicial del proyectil--> ";cin>>velocidad_inicial;
        cout<<"\ningrese la distancia entre los cañones--> ";cin>>posx_2;
        cout<<"\ningrese la altura del canon defensivo--> ";cin>>posy_2;
        cout<<"ingrese la altura del canon ofensivo--> ";cin>>posx_1;

        distancia = posx_2;

        canon ofensivo(posx_1,posy_1,distancia);
        canon defensivo(posx_2,posy_2,distancia);
        problema_1(ofensivo,defensivo,centro, velocidad_inicial);
    }

}


void problema_1(canon ofe, canon defe, base_central base, float veli)
{

    base.disparo_ofensivo(defe,ofe,veli);
}
