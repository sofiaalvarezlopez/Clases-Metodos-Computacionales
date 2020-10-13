#ifndef TVector_H
#define TVector_H

#include <iostream>

class TVector{
  
   public: // accesible en todos los ambitos
    TVector();
    TVector(double, double);
   ~TVector();

   double GetX();
   double GetY();

   void SetX(double);
   void SetY(double);

   void Print() const;

   friend std::ostream & operator << (std::ostream &out, const TVector &V);


   private: // accesible solo por metodos de la misma clase

   protected: // accesible por metodos propios y por clases heredadas.
    double x;
    double y;
  
};

class TVector3 : public TVector { //Heredar todos los metodos publicos y protegidos de la clase madre.

    public:
        TVector3();
        TVector3(double, double, double); //Respetar el orden cronologico.
        ~TVector3();

        void SetZ(double);
        double GetZ();
        void Print() const;
    private:
        double z;

};



#endif