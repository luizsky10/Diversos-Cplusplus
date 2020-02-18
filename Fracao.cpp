#include <iostream>
#include <stdio.h>
#include "MDC.h"
#include "Fracao.h"
#include <stdlib.h>

using namespace std;
		
		// Sobrecarga de entrada e saida de fluxo
	
		ostream& operator<<(ostream& saida, Fracao& obj){
			obj.Simplifica();	
			saida << obj.getnumerador() <<	"/" << obj.getdenominador()<<endl;
				return saida;
		}
		istream& operator>>(istream& entrada, Fracao& obj){
			printf("Digite o numerador e denominador: \n");
			entrada >> obj.numerador >> obj.denominador;
				return entrada;
		}

		
		Fracao::Fracao(){  // Construtor Padrão
			cout<<"Construtor Padrão"<<endl;
			this->denominador = 1;
			this->numerador=0;
			}
		Fracao::Fracao(int a, int b){	// Construtor Normal
			cout<<"Construtor Normal"<<endl;
			this->denominador = a;
			this->numerador =b;
		}
		Fracao::Fracao(const Fracao &obj){	//	Construtor de cópia
			this->denominador = obj.denominador;
			this->numerador = obj.numerador;
		}
		Fracao::~Fracao(){}	// Destrutor
	
		int Fracao::getnumerador(){
			return this->numerador;
		}
		int Fracao::getdenominador(){
			return this->denominador;
		}
		void Fracao::setnumerador(int a){
			this->numerador = a;
			this->Simplifica();
		}
		void Fracao::setdenominador(int a){
			this->denominador = a;
			this->Simplifica();
		}
		void Fracao::imprimeFracao(){
			this->Simplifica();
			cout<<this->numerador<<"/"<<this->denominador<<endl;;
		}
		void Fracao::imprimeFracaodouble(){
			double result;	
			result =this->numerador / this->denominador;
			cout << "Resultado; "<<result <<endl;
		}
	
		void Fracao::Cria(){
				int d;
				int n;
				n=0;
				d=0;
				cout << "Digite o numerador" <<endl;
				cin >>n;
				setnumerador(n);
				cout << "Digite o denominador" <<endl;
				cin >>d;
				if(d==0)
						d=1;
				setdenominador(d);
		}
		void Fracao::Simplifica(){	
			int mdc;
			mdc = MDC(getnumerador(), getdenominador()) ;
			this->numerador = this->numerador / mdc;
			this->denominador = this->denominador / mdc;
		}	

		// Sobrecargas

			Fracao& Fracao::operator=(const Fracao &obj){
					this->numerador = obj.numerador;
					this->denominador= obj.denominador;
					return *this;
		}
		
		Fracao& Fracao::operator+(Fracao &obj){
			if(this->denominador == obj.denominador){
					this->numerador = this->numerador + obj.numerador;
					this->denominador = obj.denominador;
					this->Simplifica();
					return *this;
			}
			else{
				int sdnum;
				int mmc =	MMC(this->denominador, obj.denominador);
				//cout << "Entrou"<<endl;
				cout <<"TNumerador =: "<< this->numerador<<endl;
				cout <<"TDenominador =: "<< this->numerador<<endl;
				sdnum = (this->getnumerador() * (mmc/this->getdenominador())) + (obj.getnumerador() * (mmc/obj.getdenominador()));
				this->numerador = sdnum;			
				this->denominador = mmc;
				this->Simplifica();
				return *this;
			}
		}
		Fracao& Fracao::operator-(Fracao &obj){
			if(this->denominador == obj.denominador){
					this->numerador = this->numerador - obj.getnumerador();
					this->denominador = obj.denominador;
					this->Simplifica();
					return *this;
			}
			else{
				int sbtdnum;
				int mmc =	MMC(this->denominador, obj.denominador);	
				sbtdnum = (this->getnumerador() * (mmc/this->getdenominador())) - (obj.getnumerador() * (mmc/obj.getdenominador()));
				this->denominador = mmc;
				this->Simplifica();
				return *this;
			}
		}

		Fracao& Fracao::operator*(Fracao &obj){
			this->numerador = this->numerador * obj.getnumerador();
			this->denominador = this->denominador * obj.getdenominador();
			this->Simplifica();
			return *this;
		}
		Fracao& Fracao::operator/(Fracao &obj){
				this->numerador = this->numerador * obj.getdenominador();
				this->denominador = this->denominador * obj.getnumerador();
				this->Simplifica();
				return *this;			
		}
		Fracao& Fracao::operator+=(Fracao  &obj){
				int sdnum;
				int mmc =	MMC(this->denominador, obj.denominador);	
				if(this->denominador == obj.denominador){
					sdnum = (this->numerador +this->numerador) + obj.numerador;
					this->setnumerador(sdnum);
					this->setdenominador(obj.getdenominador());
			}
			else{
				cout <<"TNumerador =: "<< this->numerador<<endl;
				cout <<"TDenominador =: "<< this->numerador<<endl;
				sdnum = (this->getnumerador() * (mmc/this->getdenominador())) + (this->getnumerador() * (mmc/this->getdenominador())) + (obj.getnumerador() * (mmc/obj.getdenominador()));
				this->setnumerador(sdnum);
				this->setdenominador(mmc);
			}
			this->Simplifica();
			return *this;
		}

	Fracao& Fracao::operator-=(Fracao &obj){
				int sdnum;
				int mmc =	MMC(this->denominador, obj.denominador);	
				if(this->denominador == obj.denominador){
					sdnum = (this->numerador - this->numerador) - obj.numerador;
					this->setnumerador(sdnum);
					this->setdenominador(obj.getdenominador());
			}
			else{

				//cout << "Entrou"<<endl;
				cout <<"TNumerador =: "<< this->numerador<<endl;
				cout <<"TDenominador =: "<< this->numerador<<endl;
				sdnum = (this->getnumerador() * (mmc/this->getdenominador())) - (this->getnumerador() * (mmc/this->getdenominador())) - (obj.getnumerador() * (mmc/obj.getdenominador()));
				this->setnumerador(sdnum);
				this->setdenominador(mmc);
			}
			this->Simplifica();
			return *this;
		}
		Fracao& Fracao::operator *=(Fracao& obj){
			int mn, md;
			mn =  this->numerador * obj.getnumerador();
			md =  this->denominador * obj.getdenominador();
			this->setnumerador(mn);
			this->setdenominador(md);
			this->Simplifica();
			return *this;
		}
		Fracao& Fracao::operator /=(Fracao& obj){
			int dm, dd;
			dm = this->numerador * obj.getdenominador();
			dd = this->denominador * obj.getnumerador();
			this->setnumerador(dm);
			this->setdenominador(dd);
			this->Simplifica();
			return *this;
			
		}
		bool Fracao::operator < (Fracao &obj){
				double pd, sd;
				pd = this->numerador / this->denominador;
				sd = obj.getnumerador() / obj.getdenominador();
				if(pd < sd)
					return true;
				else
					return false;
		}
		bool Fracao::operator <=(Fracao &obj){
				double pd, sd;
				pd = this->numerador / this->denominador;
				sd = obj.getnumerador() / obj.getdenominador();
				if(pd <= sd)
					return true;
				else
					return false;
		}		
		bool Fracao::operator >(Fracao &obj){
				double pd, sd;
				pd = this->numerador / this->denominador;
				sd = obj.getnumerador() / obj.getdenominador();
				if(pd > sd)
					return true;
				else
					return false;
		}
		bool Fracao::operator >=(Fracao &obj){
				double pd, sd;
				pd = this->numerador / this->denominador;
				sd = obj.getnumerador() / obj.getdenominador();
				if(pd >= sd)
					return true;
				else
					return false;
		}
		bool Fracao::operator ==(Fracao &obj){
			double pd, sd;
			pd = this->numerador / this->denominador;
			sd = obj.getnumerador() / obj.getdenominador();
			if(pd == sd)
					return true;
			else
					return false;	
		}
		bool Fracao::operator !=(Fracao &obj){
			double pd, sd;
			pd = this->numerador / this->denominador;
			sd = obj.getnumerador() / obj.getdenominador();
			if(pd != sd)
					return true;
			else
					return false;	
		}
			
			
		

			
			
			
			
			
			
				
			
			
			
			
