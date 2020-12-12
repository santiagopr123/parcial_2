#include "base_central.h"


base_central::base_central()
{
    pi = 3.1416;
    gravedad = 9.81;
}

void base_central::resultados(int t, float a, float px, float py, float v, float d)
{
    cout<<"**********************************************"<<endl;
    cout<<"impacto en un timepo de--> "<<t<<endl;
    cout<<"impacto en un angulo de--> "<<a<<endl;
    cout<<"impacto en la posicion x--> "<<px<<endl;
    cout<<"impacto en la posicion y--> "<<py<<endl;
    cout<<"la distancia es de--> "<<d<<endl;
}

void base_central::disparo_ofensivo(canon defensivo, canon ofensivo, float velocidad_inicial)
{
    float Vx, Vy, Vo = 0;
    float x,y;
    float angulo = 0,dista = 0;
    int tiempo = 0,flag = 0;

    for(Vo = velocidad_inicial;; Vo+=5)
    {
        for(angulo = 0; angulo<90; angulo++)
        {
            Vx = Vo*cos(angulo*pi/180);
            Vy = Vo*sin(angulo*pi/180);
            x = 0.0;
            y = 0.0;
            for(tiempo = 0; ;tiempo++)
            {
                x = Vx*tiempo;
                y = ofensivo.getPos_y()+Vy*tiempo-(0.5*gravedad*tiempo*tiempo);
                dista = sqrt(pow((defensivo.getPos_x()-x),2)+pow(defensivo.getPos_y()-y,2));
                if(sqrt(pow((defensivo.getPos_x()-x),2)+pow(defensivo.getPos_y()-y,2))<ofensivo.getDistancia()*0.05)
                {
                    resultados(tiempo,angulo,x,y,Vo,dista);
                    flag += 1;
                    Vo +=50;
                    break;

                }
                if(y<0)
                {
                    break;
                }
            }
            if(flag == 3)
            {
                break;
            }
            if(y<0)
            {
                break;
            }
        }
        if(flag == 3)
        {
            break;
        }

    }
    if(flag != 3)
    {
        cout<<"no impacto en los tres disparos. "<<endl;
    }
    else if(flag == 0)
    {
        cout<<"no impacto."<<endl;
    }

}

void base_central::disparo_defensivo(canon defensivo, canon ofensivo, float velocidad_inicial)
{
    float Vx, Vy, Vo = 0;
    float x,y;
    float angulo = 0,dista = 0;
    int tiempo = 0,flag = 0;

    for(Vo = velocidad_inicial;; Vo+=5)
    {
        for(angulo = 0; angulo<90; angulo++)
        {
        }


}


