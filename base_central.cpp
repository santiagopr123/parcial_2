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
                x = ofensivo.getPos_x()+ Vx*tiempo;
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
            Vx = Vo*cos((angulo+90)*pi/180);
            Vy = (Vo*sin((angulo+90)*pi/180));
            x = 0.0;
            y = 0.0;
            for(tiempo = 0; ;tiempo++)
            {
                x = defensivo.getPos_x()+Vx*tiempo;
                y = defensivo.getPos_y()+Vy*tiempo-(0.5*gravedad*tiempo*tiempo);
                dista = sqrt(pow((ofensivo.getPos_x()-x),2)+pow(ofensivo.getPos_y()-y,2));
                if(sqrt(pow((ofensivo.getPos_x()-x),2)+pow(ofensivo.getPos_y()-y,2))<defensivo.getDistancia()*0.025)
                {
                    resultados(tiempo,angulo,x,y,Vo,dista);
                    flag += 1;
                    Vo +=20;
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

void base_central::disparo_ofensivo_defensivo(canon defensivo, canon ofensivo, float velocidad_inicial, float velocidad_inicial_2)
{
    float Vx,Vy,Vx_2,Vy_2;
    float x,y,x_2,y_2;
    float dista = 0;
    int flag = 0;
    int Vo = 0,tiempo = 0;
    int angulo = 0;



    Vx_2 = velocidad_inicial_2*cos((ofensivo.getAngulo())*pi/180);
    Vy_2 = (velocidad_inicial_2*sin((ofensivo.getAngulo())*pi/180));

    for(Vo = velocidad_inicial;; Vo+=5)
    {
        for(angulo = 0; angulo<90; angulo++)
        {
            Vx = Vo*cos((angulo+90)*pi/180);
            Vy = (Vo*sin((angulo+90)*pi/180));
            x = 0.0;
            y = 0.0;
            x_2 = 0.0;
            y_2 = 0.0;

            for(tiempo = 0; ;tiempo++)
            {
                x_2 = ofensivo.getPos_x()+Vx_2*(tiempo+2);
                y_2 = ofensivo.getPos_y()+Vy_2*(tiempo+2)-(0.5*gravedad*(tiempo+2)*(tiempo+2));
                x = defensivo.getPos_x()+Vx*tiempo;
                y = defensivo.getPos_y()+Vy*tiempo-(0.5*gravedad*tiempo*tiempo);
                dista = sqrt(pow((x_2-x),2)+pow(y_2-y,2));
                if(sqrt(pow((x_2-x),2)+pow(y_2-y,2)) < defensivo.getDistancia()*0.025)
                {
                    cout<<"*****************************************************"<<endl<<endl;
                    resultados(tiempo+2,ofensivo.getAngulo(),x_2,y_2,velocidad_inicial_2,dista);
                    resultados(tiempo,angulo,x,y,Vo,dista);
                    cout<<endl<<endl;;
                    flag += 1;
                    Vo +=40;
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

void base_central::disparo_ofensivo_defensivo_2(canon defensivo, canon ofensivo, float velocidad_inicial, float velocidad_inicial_2)
{

}


