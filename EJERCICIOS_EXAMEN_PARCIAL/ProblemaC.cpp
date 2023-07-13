#include <iostream>
#include <vector>

using namespace std;

// calcula el numero maximo de monedas que se pueden recolectar en una sola transacción
int maxCoins(vector<int>& monedas) {
    int numMonedas = 0;
    int index = monedas.size() - 1;

    while (index >= 0) {
        int valorMoneda = monedas[index];

        if (valorMoneda <= numMonedas + 1) {
            numMonedas += valorMoneda;
        } else {
            break;
        }

        index--;
    }

    return numMonedas;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        vector<int> monedas(n);
        for (int i = 0; i < n; i++) {
            cin >> monedas[i];
        }

        int maxNumMonedas = maxCoins(monedas);

        cout << maxNumMonedas << endl;
    }

    return 0;
}
