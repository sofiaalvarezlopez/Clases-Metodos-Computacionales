#include <math.h>
#include <iostream>
using namespace std;

void StartAnim();
void StartCuadro();
void EndCuadro();
int main(){
int i = 0;
float pi = 2.0*asin(1.0);

float theta = 0.;

//Coordenadas
float x = 0.;
float y = 0.;

float r = 4.0;

srand48(0.);
    
StartAnim();

for(i=0;i<10000;i++){
  theta = drand48()*2.0*pi;
    x+= cos(theta);
    y += cos(theta);
    StartCuadro();
    std::cout << " , " <<x << "+" << r << "*cos(t)," <<y<<"+"<<r<<"*sin(t)";
    EndCuadro();
}
    return 0;

}
void StartAnim(){
    std::cout << "unset key" << std::endl;
    std::cout << "set xrange [-50:50]" << std::endl;
    std::cout << "set yrange [-50:50]" << std::endl;
    std::cout << "set size ratio -1" << std::endl;
    std::cout << "set parametric" << std::endl;
    std::cout << "set trange [0:7]" << std::endl;
    std::cout << "set isosamples 24" << std::endl;
    
}

void StartCuadro(){
    std::cout<<"plot 0,0 ";
    
}

void EndCuadro(){
    
}




