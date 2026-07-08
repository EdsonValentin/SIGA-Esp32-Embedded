#include <iostream>
#include "SensorLDR.h" 

using namespace std;

int main() {
    cout << "=== PROBANDO ARQUITECTURA SIGA EN PC ===" << endl;

    SensorLDR sensorLuz(32); 

    // Simulamos las lecturas de tu cuarto
    int luzCuartoPrendida = 1500;
    int luzCuartoApagada = 400;

    cout << "¿Es de noche con 1500? " << (sensorLuz.esNoche(luzCuartoPrendida) ? "SI" : "NO") << endl;
    cout << "¿Es de noche con 400? " << (sensorLuz.esNoche(luzCuartoApagada) ? "SI" : "NO") << endl;

    return 0;
}