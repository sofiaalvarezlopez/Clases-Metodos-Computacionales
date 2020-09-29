
#include "../inc/TOrder.h"

TOrder::TOrder(){
}

TOrder::TOrder( double A_[], int size_ ): size(size_){

   A = new double[size];
    for(int i = 0; i < size; i++){
    	A[i] = A_[i];
   }

}

void TOrder::SetArray(double A_[], int size_){

  size = size_;
  A = new double[size];
  for(int i = 0; i < size; i++)
	A[i] = A_[i];  

}

void TOrder::PrintArray(){

  if(A == nullptr){
    std::cout << " Array empty " << std::endl;
  } 
  else{
  for(int i = 0; i < size; i++)
 	std::cout << A[i] << std::endl;
  }

}

std::vector<double> TOrder::GetArray(){
  return ArrayOrdenado;
}

void TOrder::FillVector(){

  for(int i = 0; i < size; i++){
	ArrayOrdenado.push_back(A[i]);
  }

}

void TOrder::GetBurbuja(){
  std::cout << "--- Ordenando con metodo de burbuja ---" << std::endl;
  for(int i = 0; i < size; i++){
    for(int j=0; j < size; j++){
      if(A[i] < A[j]){
        auxiliar = A[i];
        A[i] = A[j];
        A[j] = auxiliar;
      }
    }
  }
  TOrder::FillVector();
}

void TOrder::GetBySelection(){

  std::cout << " --- Running by selection --- " << std::endl;

  for(int i = 0; i < size; i++){
   minimum = i; // suponemos que el primero es el menor
   	for(int j = i+1; j < size; j++){
           if(A[j] < A[minimum]){
             minimum = j;
           }		   
   	}
   	auxiliar = A[i];
   	A[i] = A[minimum];
   	A[minimum] = auxiliar;   
  }
  TOrder::FillVector();

}

TOrder::~TOrder(){
}



