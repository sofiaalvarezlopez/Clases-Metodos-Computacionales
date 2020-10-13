#include "../inc/TVector.h"

TVector::TVector(){
}

TVector::TVector(double x_, double y_): x(x_), y(y_){
}

void TVector::SetX(double x_){ x = x_; }
void TVector::SetY(double y_){ y = y_; }

double TVector::GetX(){ return x; }
double TVector::GetY(){ return y; }

void TVector::Print() const {
       std::cout << x << " " << y << std::endl;
 } 

std::ostream & operator << (std::ostream &out, const TVector &V){
  out << V.x << " " << V.y << std::endl;
  return out;
}

TVector::~TVector(){
}

//Clase heredada
TVector3::TVector3(){
}

TVector3::TVector3(double x_, double y_, double z_): TVector(x_,y_), z(z_){
}

TVector3::~TVector3(){
}

void TVector3::SetZ(double z_){ z = z_; }
double TVector3::GetZ(){ return z; }

void TVector3::Print() const {
    TVector::Print();
    std::cout << z << std::endl;
 } 
