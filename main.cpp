#include <iostream>
#include <canon.h>
#include <base_central.h>

using namespace std;

void problema_1(canon ofe, canon defe, base_central base, float veli);
void problema_2(canon ofe, canon defe, base_central base, float veli);
void problema_3(canon ofe, canon defe, base_central base, float veli);
void problema_4(canon ofe, canon defe, base_central base, float veli);
void problema_5(canon ofe, canon defe, base_central base, float veli);


int main()
{
    int opcion = 0;

    float distancia;
    float velocidad_inicial;
    float posx_1 = 0,posx_2,posy_1,posy_2;

    base_central centro;

    cout<<"este es el programa para el cual esta diseñado el parcial--> "<<endl<<"escoja la opcion de su preferencia: "<<endl;
    cout<<"ingrese el numero '1' para generar un disparo ofensivo que comprometa al canon defensivo--> "<<endl;
    cout<<"ingrese el numero '2' para generar un disparo defensivo que comprometa al canon ofensivo--> "<<endl;
    cout<<"ingrese el numero '3' para Dado un disparo ofensivo, generar (al menos tres) disparos defensivos que impida que el canón defensivo sea destruido sin importar si el canon ofensivo pueda ser destruido."<<endl;
    cout<<"ingresa el numero '4' para Dado un disparo ofensivo, generar (al menos tres) disparo defensivos que impidan que los canones defensivo y ofensivo puedan ser destruidos."<<endl;
    cout<<"ingrese el numero '5' para el nuevo punto< contrarrstar la bala defensiva para ser efectivo el dispao ofensivo."<<endl;
    cin>>opcion;


    cout<<"ingrese la velocidad inicial del proyectil--> ";cin>>velocidad_inicial;
    cout<<"\ningrese la altura del canon ofensivo--> ";cin>>posy_1;
    cout<<"\ningrese la distancia entre los canones--> ";cin>>posx_2;
    cout<<"\ningrese la altura del canon defensivo--> ";cin>>posy_2;
    distancia = posx_2;
    if(opcion == 1)
    {
        canon ofensivo(posx_1,posy_1,distancia);
        canon defensivo(posx_2,posy_2,distancia);
        problema_1(ofensivo,defensivo,centro, velocidad_inicial);
    }
    else if(opcion == 2)
    {
        canon ofensivo(posx_1,posy_1,distancia);
        canon defensivo(posx_2,posy_2,distancia);
        problema_2(ofensivo,defensivo,centro, velocidad_inicial);
    }
    else if(opcion == 3)
    {
        canon ofensivo(posx_1,posy_1,distancia);
        canon defensivo(posx_2,posy_2,distancia);
        problema_3(ofensivo,defensivo,centro, velocidad_inicial);

    }
    else if(opcion == 4)
    {
        canon ofensivo(posx_1,posy_1,distancia);
        canon defensivo(posx_2,posy_2,distancia);
        problema_4(ofensivo,defensivo,centro, velocidad_inicial);
    }
    else if(opcion == 5)
    {
        canon ofensivo(posx_1,posy_1,distancia);
        canon defensivo(posx_2,posy_2,distancia);
        problema_5(ofensivo,defensivo,centro, velocidad_inicial);
    }

    return 0;
}


void problema_1(canon ofe, canon defe, base_central base,float veli)
{
    base.disparo_ofensivo(defe,ofe,veli);
}

void problema_2(canon ofe, canon defe, base_central base, float veli)
{
    base.disparo_defensivo(defe,ofe,veli);
}

void problema_3(canon ofe, canon defe, base_central base, float veli)
{
    base.disparo_defensivo_3(defe,ofe,veli);
}

void problema_4(canon ofe, canon defe, base_central base, float veli)
{
    base.disparo_defensivo_4(defe,ofe,veli);
}

void problema_5(canon ofe, canon defe, base_central base, float veli)
{
    base.parte_uno(defe,ofe,veli);
}
