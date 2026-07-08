#include <iostream>
#include "SensorLDR.h"
#include "Historial.h"
#include "Boton.h"
#include "PantallaVista.h"

using namespace std;

int main() {
    cout << "====================================================" << endl;
    cout << "===   SISTEMA DE RIEGO INTELIGENTE SIGA COMPLETO  ===" << endl;
    cout << "====================================================" << endl;

    // 1. INSTANCIACIÓN DE COMPONENTES HARDWARE (MODULARES)
    SensorLDR sensorLuz(32);
    Historial historialRiego;
    Boton botonModo(13);
    Boton botonMenu(14);

    // 2. INSTANCIACIÓN DE VISTAS PARA PANTALLA OLED (HERENCIA)
    VistaMonitoreo pantallaMonitoreo;
    // Pasamos datos iniciales simulados al historial (0 riegos, temp máx inicial, suelo mín inicial)
    VistaHistorial pantallaHistorial(0, 0.0, 100); 

    // 3. VARIABLES DE ESTADO GLOBALES
    bool modoAuto = true;
    int pantallaActual = 0; // 0 = Monitoreo, 1 = Historial
    PantallaVista* vistaActiva = &pantallaMonitoreo; // Puntero Polimórfico inicial

    // =================================================================
    // SIMULACIÓN: ESCENARIO DE OPERACIÓN REAL DE TU MAQUETA
    // =================================================================
    cout << "\n>>> [ESCENARIO 1: OPERACIÓN AUTOMÁTICA DE DÍA] <<<" << endl;
    
    // Variables simuladas del entorno en la PC
    int lecturaLDR_Dia = 1500;      // 1500 > 1000 = Es de Día (SL)
    float temperaturaActual = 28.5; // Temperatura alta
    int humedadSueloActual = 22;    // Menor a 35% = ¡Suelo Seco!

    // El sistema procesa los sensores de forma automática
    historialRiego.verificarTemperatura(temperaturaActual);
    historialRiego.verificarSuelo(humedadSueloActual);

    if (modoAuto && humedadSueloActual < 35) {
        cout << "[ALERTA AUTOMÁTICA]: Humedad crítica en " << humedadSueloActual << "%. ¡Activando Bomba y registrando riego!" << endl;
        historialRiego.registrarRiego();
    }

    // Actualizamos los datos reales del historial dentro de la pantalla 2
    pantallaHistorial = VistaHistorial(historialRiego.obtenerRiegos(), historialRiego.obtenerTempMax(), historialRiego.obtenerSueloMin());
    
    // Dibujamos la pantalla activa actual (Monitoreo)
    vistaActiva->dibujar();


    cout << "\n>>> [ESCENARIO 2: USUARIO PRESIONA BOTÓN DE MENÚ PARA VER DIAGNÓSTICO] <<<" << endl;
    // Simulamos que el usuario presiona físicamente el botón del pin 14 (false = presionado)
    bool pulsacionMenu = false; 

    if (botonMenu.fuePresionado(pulsacionMenu)) {
        cout << "[EVENTO]: Boton Menu presionado. Intercambiando vista dinamicamente..." << endl;
        pantallaActual = 1;
        vistaActiva = &pantallaHistorial; // El puntero polimórfico cambia de dirección de memoria
    }

    // Dibujamos la nueva pantalla activa (Ahora mostrará las estadísticas guardadas)
    vistaActiva->dibujar();


    cout << "\n>>> [ESCENARIO 3: USUARIO CAMBIA A MODO MANUAL] <<<" << endl;
    // Simulamos que el usuario presiona el botón del pin 13 (false = presionado)
    bool pulsacionModo = false;

    if (botonModo.fuePresionado(pulsacionModo)) {
        modoAuto = !modoAuto; // Cambiamos la bandera global
        cout << "[EVENTO]: Boton Modo presionado. El sistema pasa a MODO: " << (modoAuto ? "AUTOMATICO" : "MANUAL") << endl;
    }

    return 0;
}