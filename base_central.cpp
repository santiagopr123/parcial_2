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
    cout<<"la velocidad fue de-->"<<v<<endl;
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
                    //Vo +=50;
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
                    //Vo +=20;
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

void base_central::disparo_defensivo_3(canon defensivo, canon ofensivo, float velocidad_inicial)
{

    int angulo_2,V0oo;
    cout<<"ingrese el angulo 2--> ";cin>>angulo_2;
    cout<<"\ningrese la velocidad inicial 2--> ";cin>>V0oo;


    float Vxo,Vyo,Vxoo,Vyoo;
    float x,y,x2,y2;
    int flag = 0;
    bool flag_2 = 0;
    int V0o = 0,tiempo = 0;
    int angulo = 0;
    float aux,auy;

    Vxoo = V0oo*cos((angulo_2)*pi/180);
    Vyoo = (V0oo*sin((angulo_2)*pi/180));

    for(V0o = velocidad_inicial;; V0o+=5)
    {
        for(angulo = 0; angulo<90; angulo++)
        {
            Vxo = V0o*cos((angulo+90)*pi/180);
            Vyo = (V0o*sin((angulo+90)*pi/180));
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;

            for(tiempo = 0; ;tiempo++)
            {
                x2 = ofensivo.getPos_x()+Vxoo*(tiempo+2);
                y2 = ofensivo.getPos_y()+Vyoo*(tiempo+2)-(0.5*gravedad*(tiempo+2)*(tiempo+2));
                x = defensivo.getPos_x()+Vxo*tiempo;
                y = defensivo.getPos_y()+Vyo*tiempo-(0.5*gravedad*tiempo*tiempo);

                for(int tiempo_2 = tiempo; ; tiempo_2++)
                {
                    aux = defensivo.getPos_x()+Vxo*tiempo_2;
                    auy = defensivo.getPos_y()+Vyo*tiempo_2-(0.5*gravedad*tiempo_2*tiempo_2);
                    if(sqrt(pow((ofensivo.getPos_x()-aux),2)+pow(ofensivo.getPos_y()-auy,2))<defensivo.getDistancia()*0.025)
                    {
                        flag_2 = 1;
                        break;

                    }
                    if(auy<0)
                    {
                        break;
                    }
                }
                if(flag_2)
                {
                    flag_2 = 0;
                    break;
                }
                if(sqrt(pow((defensivo.getPos_x()-x2),2)+pow(defensivo.getPos_y()-y2,2))<ofensivo.getDistancia()*0.05)
                {
                    break;

                }
                if(sqrt(pow((x2-x),2)+pow(y2-y,2))<defensivo.getDistancia()*0.025)
                {
                    float dista = sqrt(pow((x2-x),2)+pow(y2-y,2));
                    cout<<"--------------------------------------"<<endl<<endl;
                    resultados(tiempo+2,angulo_2,x2,y2,V0oo,dista);
                    resultados(angulo,V0o,x,y,tiempo,dista);
                    cout<<endl<<endl;;
                    flag += 1;
                    V0o +=50;
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

void base_central::parte_uno(canon defensivo, canon ofensivo, float velocidad_inicial)
{

    //int angulo_2,Voo;
    //cout<<"ingrese el angulo 2--> ";cin>>angulo_2;
    //cout<<"\ningrese la velocidad inicial 2--> ";cin>>Voo;

    float Vx, Vy;
    float x,y;
    float dista;
    int angulo,Vo,tiempo;

    for(Vo = velocidad_inicial;;Vo+=5)
    {
        for(angulo = 0;angulo<90;angulo++)
        {
            Vx = Vo*cos(angulo*pi/180);
            Vy = Vo*sin(angulo*pi/180);
            x = 0.0;
            y = 0.0;
            for(tiempo = 0;;tiempo++)
            {
                x = ofensivo.getPos_x()+ Vx*tiempo;
                y = ofensivo.getPos_y()+Vy*tiempo-(0.5*gravedad*tiempo*tiempo);
                dista = sqrt(pow((defensivo.getPos_x()-x),2)+pow(defensivo.getPos_y()-y,2));
                if(sqrt(pow((defensivo.getPos_x()-x),2)+pow(defensivo.getPos_y()-y,2))<ofensivo.getDistancia()*0.05)
                {
                    resultados(tiempo,angulo,x,y,Vo,dista);
                    break;

                }
                if(y<0)
                {
                    break;
                }
            }
            if(y<0)
            {
                break;
            }
        }
    }

}

void base_central::parte_dos(canon defensivo, canon ofensivo, float velocidad_inicial, int angul, int time)
{

    float Vx, Vy,Vx_2,Vy_2;
    float x,y,x_2,y_2;
    float dista;
    int angulo,Vo,tiempo;


    Vx_2 = velocidad_inicial*cos(angul*pi/180);
    Vy_2 = velocidad_inicial*sin(angul*pi/180);



    for(Vo = 50;;Vo+=5)
    {
        for(angulo = 0;angulo<90;angulo++)
        {

        }
    }

}
