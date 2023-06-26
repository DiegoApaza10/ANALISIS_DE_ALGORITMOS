#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Objeto
{
    float peso;
    float beneficio;
};

bool compararRazon(const Objeto& A, const Objeto& B) //Funcion para comparar si uno es mayor que el otro
{
    return (A.beneficio / A.peso) > (B.beneficio / B.peso);
}

void mochila(float capacidad_mochila, vector<Objeto>& objetos)
{	//se usa sort par ordenar los objetos segun la razon
    sort(objetos.begin(), objetos.end(), compararRazon);

    float peso_actual = 0.0;
    float beneficio_total = 0.0;
    vector<float> pesos_elegidos;
	
    for (const auto& objeto : objetos)
    {	//si el peso actual mas el peso del objeto es menor a la capacidad
    	//este entra
        if (peso_actual + objeto.peso <= capacidad_mochila)
        {
            peso_actual += objeto.peso;
            beneficio_total += objeto.beneficio;
            pesos_elegidos.push_back(objeto.peso);
        }
        else
        {
            float peso_restante = capacidad_mochila - peso_actual;
            float fraccion = peso_restante / objeto.peso;
            beneficio_total += objeto.beneficio * fraccion;
            pesos_elegidos.push_back(objeto.peso * fraccion);
            break;
        }
    }

    cout << "Beneficio total obtenido: " << beneficio_total << endl;
    cout << "Pesos elegidos: ";
    for (const auto& peso : pesos_elegidos)
    {
        cout << peso << " ";
    }
    cout << endl;
}


int main()
{
    float capacidad_mochila = 20;
    vector<Objeto> objetos = {{18, 25}, {15, 24}, {10, 15}};
    mochila(capacidad_mochila, objetos);

    return 0;
}


