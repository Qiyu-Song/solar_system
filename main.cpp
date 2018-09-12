#include <iostream>
#include <fstream>
#include <cmath>
#include "Linklist.h"

using namespace std;


#define     G       1.202908470245030000000000000000E-15



double acc(double m, double r)
{
    return  G * m / (r*r);
}

void Init(LinkList Planet)
{
    PNode tail=Planet;
    ifstream in{"input.txt"};
    while(in)
    {
        DataType nPlanet;
        double x,vy,m;
        in>>x>>vy>>m;
        if(in){
            nPlanet.x=x;
            nPlanet.y=0;
            nPlanet.vx=0;
            nPlanet.vy=vy;
            nPlanet.ax=0;
            nPlanet.ay=0;
            nPlanet.m=m;
            insertPost_link(Planet,tail,nPlanet);
            tail=tail->link;
        }
    }
 /*   //����һ��С����
    DataType nPlanet;
    const double theta = 0;
    nPlanet.x=0.586*cos(theta);
    nPlanet.y=0.586*sin(theta);
    nPlanet.vx=0.0000365*sin(theta);
    nPlanet.vy=-0.0000365*cos(theta);
    nPlanet.m=1.676446E-10;
    nPlanet.ax=0;
    nPlanet.ay=0;
    insertPost_link(Planet,tail,nPlanet);
    tail=tail->link;
*/

    //��ʼ�����ٶ�
    PNode p = Planet;
    while (p->link != NULL){
        p = p->link;

        double a , r;
        double ax=0;
        double ay=0;


        PNode q = Planet;
        while (q->link != NULL){
            q = q->link;
            if(q->info.x != p->info.x || q->info.y != p->info.y){
                r =  (p->info.x - q->info.x)*(p->info.x - q->info.x);
                r += (p->info.y - q->info.y)*(p->info.y - q->info.y);
                r =  sqrt(r);
                a =  acc( q->info.m , r);
                ax += a * (q->info.x - p->info.x) / r;
                ay += a * (q->info.y - p->info.y) / r;
            }
        }
        //����̫������
        r = p->info.x * p->info.x + p->info.y * p->info.y;
        r = sqrt(r);
        a = acc(330000 , r);
        ax += -a * p->info.x / r;
        ay += -a * p->info.y / r;
        p->info.ax = ax;
        p->info.ay = ay;
    }
}

void PlanetNewState(LinkList Planet, int dt)
{
    PNode p = Planet;

    while (p->link != NULL){
        p = p->link;
        //��λ��
        p->info.x += p->info.vx * dt + p->info.ax * dt * dt * 0.5;
        p->info.y += p->info.vy * dt + p->info.ay * dt * dt * 0.5;

        //������ٶȣ��������£�
        double a , r , rsun;
        double ax = 0;
        double ay = 0;

        PNode q = Planet;
        while (q->link != NULL){
            q = q->link;
            if(q->info.x != p->info.x || q->info.y != p->info.y){
                r =  (p->info.x - q->info.x)*(p->info.x - q->info.x);
                r += (p->info.y - q->info.y)*(p->info.y - q->info.y);
                r =  sqrt(r);
                a =  acc( q->info.m , r);
                ax += a * (q->info.x - p->info.x) / r;
                ay += a * (q->info.y - p->info.y) / r;
            }
        }
        //����̫������
        rsun = p->info.x * p->info.x + p->info.y * p->info.y;
        rsun = sqrt(rsun);
        a = acc( 330000 , rsun);
        ax += -a * p->info.x / rsun;
        ay += -a * p->info.y / rsun;

        //�����ٶ�
        p->info.vx += (p->info.ax + ax) * dt / 2;
        p->info.vy += (p->info.ay + ay) * dt / 2;

        //���¼��ٶ�
        p->info.ax = ax;
        p->info.ay = ay;
    }
}

void Display(LinkList planet , ofstream& out_1 , ofstream& out_2)
{
    int counter = 0;
    PNode p = planet;
    while(p->link != NULL){
        p = p->link;
        counter += 1;
        if(counter <= 4){out_1<<100*p->info.x<<'\t'<<100*p->info.y<<endl;}      //��100�����������ʵ�����壻�������Ƿֿ�����ֿ���ͼ
        else out_2<<100*p->info.x<<'\t'<<100*p->info.y<<endl;
    }
}


int main()
{

    int t=0;
    int dt=1; //����100s

    ofstream out_1{"output_1.txt"};
    ofstream out_2{"output_2.txt"};
	LinkList Planet = createNullList_link();
	Init(Planet);            //initialize all the planets

	while(t<=100000000)
	{
		t = t+10*dt;
		PlanetNewState(Planet, 10*dt);
        if(t%10000==0){
                if(t%1000000==0){cout<<"x";}
                Display(Planet,out_1,out_2);
        }
	}

    return 0;
}

