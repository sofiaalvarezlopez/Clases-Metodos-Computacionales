#include "../inc/TOrder.h"

int main(){

	double MyArray[] = {3.,5.,11.,6.,12.,9.,1.};

	int size = sizeof(MyArray)/sizeof(MyArray[0]);

        // Creamos el objeto
	//
	TOrder MyOrdenamiento(MyArray, size);
	//MyOrdenamiento.PrintArray();

        //MyOrdenamiento.GetBurbuja();
        MyOrdenamiento.GetBySelection();

	std::vector<double> Ordenado = MyOrdenamiento.GetArray();


	//std::cout << MyOrdenamiento.A << std::endl;

	srand48(8);

	double RandomArray[10000];
	for(int i = 0; i < 10000; i++){
		RandomArray[i] = 2.*drand48();
	}
	int sizer = sizeof(RandomArray)/sizeof(RandomArray[0]);

	TOrder RandomObj(RandomArray, sizer);
//	RandomObj.PrintArray();

//	RandomObj.GetBurbuja();
	RandomObj.GetBySelection();

        std::vector<double> Ordenado1 = RandomObj.GetArray();

        for(int i = 0; i < 10000; i++){
          std::cout << Ordenado1[i] << std::endl;
        }
	return 0;
}
