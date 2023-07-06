#include <iostream>
#include <vector>
#include <algorithm>
//TAREA 5
//PLANIFICACION DE TAREAS
struct Tarea {
    int id;
    int plazo;
    int beneficio;
};

// Funcion de comparacion para ordenar las tareas por beneficio de forma descendente
bool compararTareas(const Tarea& t1, const Tarea& t2) {
    return t1.beneficio > t2.beneficio;
}

// Funcion para maximizar el beneficio seleccionando tareas de acuerdo a su plazo y beneficio
int maximizarBeneficio(std::vector<Tarea>& tareas, std::vector<Tarea>& tareasSeleccionadas) {
    // Ordenar las tareas por beneficio de forma descendente
    std::sort(tareas.begin(), tareas.end(), compararTareas);

    int tiempoActual = 0;
    int beneficioTotal = 0;

    // Recorrer las tareas ordenadas y seleccionar aquellas que cumplen con el plazo
    for (const auto& tarea : tareas) {
        if (tiempoActual < tarea.plazo) {
            tareasSeleccionadas.push_back(tarea);
            tiempoActual++;
            beneficioTotal += tarea.beneficio;
        }
    }

    return beneficioTotal;
}

int main() {
    std::vector<Tarea> tareas = {
        {1, 2, 50},
        {2, 1, 10},
        {3, 2, 15},
        {4, 1, 30}
    };

    std::vector<Tarea> tareasSeleccionadas;

    // Maximizar el beneficio seleccionando las tareas adecuadas
    int beneficioTotal = maximizarBeneficio(tareas, tareasSeleccionadas);

    // Imprimir el beneficio total y las tareas seleccionadas
    std::cout << "Beneficio Total: " << beneficioTotal << std::endl;
    std::cout << "Tareas Seleccionadas: " << std::endl;
    for (const auto& tarea : tareasSeleccionadas) {
        std::cout << "Tarea " << tarea.id << ": Beneficio = " << tarea.beneficio << ", Plazo = " << tarea.plazo << std::endl;
    }

    return 0;
}
