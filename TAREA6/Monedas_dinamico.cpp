#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Función para resolver el Problema del cambio de monedas utilizando programación dinámica
int cambioMonedas(vector<int>& monedas, int cantidad) {
    vector<int> dp(cantidad + 1, INT_MAX);
    dp[0] = 0;

    // Llenar la tabla dp con los valores óptimos
    for (int i = 1; i <= cantidad; i++) {
        for (int moneda : monedas) {
            // Verificar si la moneda actual puede ser utilizada para formar el valor i
            if (moneda <= i && dp[i - moneda] != INT_MAX) {
                // Si es posible formar el valor i con la moneda actual, actualizar el valor óptimo
                dp[i] = min(dp[i], dp[i - moneda] + 1);
            }
        }
    }

    // El valor en la última celda de la tabla representa la cantidad mínima de monedas necesarias
    return (dp[cantidad] == INT_MAX) ? -1 : dp[cantidad];
}

int main() {
    vector<int> monedas = {1, 2, 5};
    int cantidad = 11;

    int cantMinimaMonedas = cambioMonedas(monedas, cantidad);
    cout << "Cantidad minima de monedas requeridas: " << cantMinimaMonedas << endl;

    return 0;
}
