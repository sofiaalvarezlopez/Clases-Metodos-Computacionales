#include <iostream>
#include <math.h>
#include "../inc/animacion.h"

double G = (6.67e-11*pow(6.68e-12,3))/(5e-31*pow(1.15e-5,2));
double Ms = 1.;

void GetAcce(double d, double x, double y, double &ax, double &ay){
    ax = -(G*Ms*x)/pow(d,3);
    ay = -(G*Ms*y)/pow(d,3);
}

double GetDis(double x, double y){
    double d = 0.;
    d = sqrt( pow(x,2) + pow(y,2));
    return d;
}

//Derivada central numérica
double GetVel(double xs, double xa, double deltat){
    double v = 0.;
    v = (xs+xa)/(2.0*deltat);
    return v;
}

double GetPosition(double current_x, double previous_x, double a, double deltat){
    double newx = 0.;
    newx = 2.0*current_x - previous_x + a*pow(deltat, 2);
    return newx;
}

int main(int argc, char *argv[]){
    if(argc==1){
        std::cout << "Su codigo necesita el numero de anios solares" << std::endl;
        exit(1);
    }
    
    int Size = 365*std::stoi(argv[1]);
    
    double t = 0.;
    double deltat = 0.5;
    
    Size = int(Size/deltat);
    
    double x0 = 1; //au
    double y0 = 0;
    double vx0 = 0.;
    double vy0 = 0.01721420632; // au/dias
    double ax = 0.;
    double ay= 0.;
    
    //Necesitamos la segunda posicion
    double x1 = x0 + vx0*deltat;
    double y1 = y0 + vy0*deltat;
    //std::cout << Size << std::endl;
    
    //Reservamos el espacio en memoria con los apuntadores.
    double *X = new double[Size];
    double *Y = new double[Size];
    
    double *Vx = new double[Size];
    double *Vy = new double[Size];
    
    double *time = new double[Size];
    
    double *Energy = new double[Size];
    
    //Llenamos las primeras posiciones
    
    time[0] = 0.;
    X[0] = x0;
    Y[0] = y0;
    X[1] = x1;
    Y[1] = y1;
    
    Vx[0] = vx0;
    Vy[0] = vy0;
    
    Energy[0] = 0.5*sqrt(pow(vx0, 2) + pow(vy0, 2));
    
    // Iterando sobre las posiciones del planeta
    for (int i=2; i < Size; i++){
        
        double d = GetDis(X[i-1], Y[i-1]);
        GetAcce(d,X[i-1], Y[i-1],ax,ay);
        X[i] = GetPosition(X[i-1], X[i-2],ax,deltat);
        Y[i] = GetPosition(Y[i-1], Y[i-2],ay,deltat);
        Vx[i-1] = GetVel(X[i], X[i-2], deltat);
        Vy[i-1] = GetVel(Y[i], Y[i-2], deltat);
        
        Energy[i-1] = 0.5*sqrt(pow(Vx[i-1], 2) + pow(Vy[i-1], 2));
        
        time[i-1] = t;
        t += deltat;
    }
    
    //Generando la animacion
    StartAnim();
    double rsun = 0.3;
    double rearth = 0.05;
    double Xsun[1] = {0.};
    double Ysun[1] = {0.};
    
    for (int i = 0; i < Size; i++){
        
        StartCuadro();
        GetPoint(Xsun[0], Ysun[0], rsun);
        GetPoint(X[i],Y[i], rearth);
        EndCuadro();
        //std::cout << time[i] << " " << Energy[i] << std::endl;
    }
    
    //Borramos el espacio reservado en memoria
    delete[] X;
    delete[] Y;
    delete[] Vx;
    delete[] Vy;
    delete[] time;
    delete[] Energy;
    
    
    return 0;
}
