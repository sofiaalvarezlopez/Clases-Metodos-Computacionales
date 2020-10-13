#include "../inc/TVector.h"

int main(){
    TVector V1;
	V1.SetX(0.6); V1.SetY(3.8);
	//std::cout << V1.GetX()  << " " << V1.GetY() << std::endl;
    V1.Print();
    TVector3 V2(0.2, 3.3, 6.);
    //std::cout << V2.GetX() << std::endl;
    V2.Print();

    return 0;
}