#include <iostream>
#include <string>
using namespace std;
///////////////////////////
//  ALUMNO: APAZA ANDALUZ DIEGO FRANCISCO 
//  CUI:20210690
///////////////////////////
//Esta es una funcion que imprime e un bucle for 
//de 0 a N veces
// podemos decir que el tiempo de ejecución
// de esta función es depende de  n, lo cual 
// se puede representar como O(n) 
void funcion1(int n)
{
	for(int i = 0; i == n; i++){
		i%2 == 0? cout<<" "<<i<<" "<<endl:cout<<" ";  
	}
	
}


//EN ESTA FUNCION SE USA UN BUCLE FOR QUE SE EJECUTA
// N+1 VECES Y EL BUCLE FOR INTERNO  N VECES
// ENTONCES LA CANTIDAD TOTAL DE OPERACIONES EN TOTAL ES
// N(N+1)
// LO CUAL ES O(N^2) 
void funcion2(int n)
{	
	int cont= 1;
	for(int i=0;i <= n;i++)
	{
		//cout<<"primer contador: "<<i+1<<" veces \n";
		for(int j=1;j <= n;j++)
		{
			cout<<"contador total: "<<cont<<" veces \n";
			cout<<i<<" , "<<j<<endl;
		 	cont++;
		}
		cont++;
	}

}

//ESTA FUNCION DEPENDE DE LAS LONGITUDES DE A Y B
// Y COMO SE ESTAN USANDO BLOQUES ANIDADOS
// LA CANTIDAD TOTAL DE OPERACIONES EN TOTAL ES
// A*B
// O(A*B)

void funcion4(string A,string B)
{
	for(int i = 0; i<= A.size(); i++)
	{
		for(int j = 0;j<=  B.size()  ; j++)
		{
			cout<<A[i] << " , " << B[j]<<endl; 
		}
	}
}

// COMO SON BUCLES CONSECUTIVOS Y AMBOS DEPENDEN DE N
// AMBOS SE VAN A EJECUTAR N+1 VECES DE IGUAL MANERA
// O(n)
void funcion5(int n)
{
	for(int i=0;i <= n;i++)
	{
		i%2 == 0? cout<<" "<<i<<" ":cout<<" "; 
	}
	for(int j=0;j <= n;j++)
	{
		j%2 != 0? cout<<" "<<j<<" "<<endl:cout<<" "; 
	}
	
}

//EN ESTE BUCLE WHILE 
/*
MIENTRAS i SEA MENOR A "N" SE VA MULTIPLICAR POR 2
LO QUE HACE CRECER A i DE MANERA EXPONENCIAL 
PODEMOS CALCULAR EL NUMERO DE ITERACIONES COMO EL LOG EN BASE 2 DE N
ENTONCES LA NOTACION ES O(Log n) 
*/
void funcion6(int n)
{	int i = 1;
	while(i<n)
	{
		cout<<" "<<i<<" "<<endl;
		i=i*2;
	}
}

//ESTA ES UNA OPERACION O(1)
//YA QUE ES CONSTANTE
void funcion7()
{	
	int n=1000;
	n%2 != 0? cout<<" IMPAR "<<endl:cout<<" PAR "<<endl;
}

int main()
{
	//funcion1(10);
	//funcion2(10);
	//funcion4(10);
	//funcion5(10);
	//funcion6(10);
	funcion7();
	return 0;
}