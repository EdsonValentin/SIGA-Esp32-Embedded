#include <iostream>
#include <memory> 
#include "SensorLDR.h"
#include "Historial.h"
#include "Boton.h"
#include "PantallaVista.h"
#include "BombaRelay.h"   
#include "SensorClima.h"  
#include "SensorSuelo.h" 

using namespace std;

int main() {
    cout << "=====================================================================" << endl;
    cout << "===  SISTEMA SIGA V5.0 - REGLAS DE NEGOCIO IDÉNTICAS AL ESP32     ===" << endl;
    cout << "=====================================================================" << endl;

    // 1. COMPONENTES HARDWARE MODULARES
    SensorLDR sensorLuz(32);       
    Historial historialRiego;
    
    Boton botonModo(13);  // Cambia entre AUTO y MANUAL
    Boton botonBomba(12); // Activa la bomba SOLO en Manual
    Boton botonMenu(14);  // Navega entre pantallas OLED

    auto bombaAgua = make_unique<BombaRelay>(26);   
    auto sensorDht11 = make_unique<SensorDHT11>(4); 
    auto electrodoTierra = make_unique<SensorSuelo>(34); 

    unique_ptr<PantallaVista> vistaActiva = make_unique<VistaMonitoreo>();
    bool modoAuto = true;

    // =================================================================
    // CASO DE USO 1: EVALUACIÓN AUTOMÁTICA CON BLOQUEO POR LLUVIA (DHT11)
    // =================================================================
    cout << "\n>>> [ESCENARIO 1: OPERACIÓN EN AUTOMÁTICO - EVALUANDO LLUVIA Y SUELO] <<<" << endl;
    
    // Simulamos condiciones climáticas (DHT11 detecta 85% de humedad, indicando lluvia)
    float tempAire = sensorDht11->leerTemperatura(); 
    int humedadAmbienteLluvia = 85; // 🚨 Mayor a 80% = Lloviendo
    int lecturaSuelo = electrodoTierra->obtenerLecturaPorcentaje(); // 22% (Suelo Seco)
    
    historialRiego.verificarTemperatura(tempAire);
    historialRiego.verificarSuelo(lecturaSuelo);

    cout << "\n[Analizando Datos]: Tierra en " << lecturaSuelo << "% | Ambiente en " << humedadAmbienteLluvia << "% (Lluvia)" << endl;
    
    // Tu regla exacta: El suelo necesita agua, PERO si hay lluvia, NO se riega
    if (modoAuto && electrodoTierra->necesitaRiego()) {
        if (humedadAmbienteLluvia > 80) {
            cout << "⚠️ [BLOQUEO]: El suelo está seco, pero el DHT11 reporta LLUVIA. Riego cancelado." << endl;
            bombaAgua->apagar();
        } else {
            cout << "💧 [SIGA AUTO]: Condiciones normales de sequía. Activando bomba..." << endl;
            bombaAgua->encender();
            historialRiego.registrarRiego();
            bombaAgua->apagar();
        }
    }
    
    // Simulamos el LDR leyendo que es de noche
    cout << "Monitoreo LDR -> " << (sensorLuz.esNoche(450) ? "LN (Noche)" : "SL (Día)") << endl;
    vistaActiva->dibujar(); 


    // =================================================================
    // CASO DE USO 2: INTENTO DE RIEGO MANUAL (PRIMERO SE CAMBIA A MANUAL)
    // =================================================================
    cout << "\n>>> [ESCENARIO 2: USUARIO PRUEBA PULSADORES DE CONTROL EN MANUAL] <<<" << endl;
    
    // Pulsador 1 (Pin 13) cambia el sistema a MANUAL
    if (botonModo.fuePresionado(false)) {
        modoAuto = false;
        cout << "[EVENTO]: Pulsador Modo presionado. El sistema pasa a MODO: MANUAL" << endl;
    }

    // Pulsador 2 (Pin 12) intenta encender la bomba ahora que SÍ está en manual
    if (!modoAuto) {
        if (botonBomba.fuePresionado(false)) {
            cout << "[EVENTO]: Pulsador Bomba presionado. Permiso CONCEDIDO por estar en Manual." << endl;
            bombaAgua->encender();
            historialRiego.registrarRiego(); // Se acumula en el reporte
            bombaAgua->apagar();
        }
    }


    // =================================================================
    // CASO DE USO 3: TERCER PULSADOR (PIN 14) NAVEGACIÓN OLED
    // =================================================================
    cout << "\n>>> [ESCENARIO 3: NAVEGACIÓN CON EL TERCER PULSADOR AL REPORTE] <<<" << endl;
    
    if (botonMenu.fuePresionado(false)) {
        cout << "[EVENTO]: Pulsador Menú detectado. Renderizando reporte analítico acumulado..." << endl;
        
        auto pantallaHistorial = make_unique<VistaHistorial>(
            historialRiego.obtenerRiegos(), // Mostrará el riego manual ejecutado
            historialRiego.obtenerTempMax(), 
            historialRiego.obtenerSueloMin() 
        );
        vistaActiva = move(pantallaHistorial); 
    }

    vistaActiva->dibujar(); 

    cout << "\n=====================================================================" << endl;
    return 0;
}