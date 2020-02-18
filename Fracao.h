#ifndef FRACAO_H
#define FRACAO_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class  Fracao{
  	  friend ostream& operator<<(ostream&, Fracao&);
      friend istream& operator>>(istream&, Fracao&);
	
	public:
				
			Fracao();
			Fracao(int, int);
    		Fracao(const Fracao &);
			~Fracao();
   			int getnumerador();
			int getdenominador();
			void setnumerador(int);
			void setdenominador(int);
			void imprimeFracao();
			void imprimeFracaodouble();
    		void Simplifica();	
			void Cria();
		
			// Sobrecargas
			Fracao& operator=(const Fracao &);
			Fracao& operator+(Fracao &);
			Fracao& operator-(Fracao &);
			Fracao& operator *(Fracao &);
			Fracao& operator/(Fracao &);
			Fracao& operator+=(Fracao &);
			Fracao& operator-=(Fracao &);
			Fracao& operator*=(Fracao &);
			Fracao& operator /=(Fracao &);
			bool operator <(Fracao &);
			bool operator<=(Fracao &);
			bool operator >(Fracao &);
			bool operator >=(Fracao &);
			bool operator ==(Fracao &);
			bool operator !=(Fracao &);
			
			
			
	
    private:
    		int numerador;
        	int denominador;  
};

#endif
