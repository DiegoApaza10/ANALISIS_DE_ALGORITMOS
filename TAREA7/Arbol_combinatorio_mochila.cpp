#include <iostream>
#include <vector>

using namespace std;

int mochila_combinatoria(vector<int>& valores, vector<int>& pesos, int capacidad, int n) {
    int mejor_valor = 0;
    vector<int> mejor_seleccion(n, 0);
    
    // Iteramos a través de todas las combinaciones posibles de objetos
    for (int i = 0; i < (1 << n); ++i) {
        int valor_actual = 0;
        int peso_actual = 0;
        vector<int> seleccion_actual(n, 0);
        
        // Verificamos qué objetos están incluidos en la combinación actual
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                valor_actual += valores[j];
                peso_actual += pesos[j];
                seleccion_actual[j] = 1;
            }
        }
        
        // Si la combinación es válida y mejora el valor máximo, actualizamos
        if (peso_actual <= capacidad && valor_actual > mejor_valor) {
            mejor_valor = valor_actual;
            mejor_seleccion = seleccion_actual;
        }
    }
    
    return mejor_valor;
}

int main() {
    vector<int> valores = {10, 4, 7, 3};
    vector<int> pesos = {5, 3, 2, 1};
    int capacidad = 5;
    int n = valores.size();
    
    int mejor_valor = mochila_combinatoria(valores, pesos, capacidad, n);
    cout << "Mejor valor: " << mejor_valor << endl;
    
    return 0;
}
