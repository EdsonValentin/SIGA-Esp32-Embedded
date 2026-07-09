# 🌾 Sistema Inteligente de Gestión Agrícola (SIGA)

**SIGA** es un firmware de nivel industrial diseñado para el microcontrolador **ESP32** utilizando **C++ Moderno**. El sistema automatiza el riego agrícola analizando variables climáticas y de suelo en tiempo real, optimizando el recurso hídrico de forma autónoma.

---

## 🚀 Características de la Arquitectura de Software

A diferencia de los bocetos lineales tradicionales, este sistema implementa patrones de diseño profesionales y avanzados exigidos en la industria de sistemas embebidos:

*   **Modularidad Estricta:** Separación de responsabilidades dividida en archivos de definición (`.h`) en la carpeta `include/` y lógica de control (`.cpp`) en la carpeta `src/`.
*   **Programación Genérica y Automatización:** Gestión de compilación y empaquetado multi-archivo utilizando **CMake**.
*   **Polimorfismo Dinámico:** Renderizado de interfaces dinámicas en pantalla OLED mediante clases heredadas administradas por una interfaz abstracta base.
*   **Memoria Dinámica Segura (Smart Pointers):** Mitigación total de fugas de memoria (*Memory Leaks*) y desbordamientos de RAM a través de la implementación de `std::unique_ptr` de C++17 para la destrucción automatizada de recursos gráficos.
*   **Control Concurrente No Bloqueante:** Inicialización y lógica cíclica controlada por tiempos con la función `millis()`, eliminando retardos por `delay()` para garantizar una lectura nativa de periféricos al milisegundo.

---

## 📁 Estructura del Repositorio

```text
├── CMakeLists.txt        # Motor de configuración de compilación de CMake
├── main.cpp              # Ciclo principal de inicialización y simulación de hardware
├── include/              # Planos y cabeceras de clases modulares (.h)
│   ├── Boton.h
│   ├── Historial.h
│   ├── PantallaVista.h
│   └── SensorLDR.h
└── src/                  # Lógica y desarrollo matemático de componentes (.cpp)
    ├── Boton.cpp
    ├── Historial.cpp
    ├── PantallaVista.cpp
    └── SensorLDR.cpp
```

---

## 🛠️ Tecnologías y Herramientas Utilizadas

*   **Lenguaje:** C++ Moderno (Estándar C++17)
*   **Hardware Core:** ESP32 (Arquitectura de 32 bits)
*   **Entorno y Compilación:** CMake, GNU Make, GCC Compiler
*   **Control de Versiones:** Git & GitHub Distributed System
*   **Gestión de RAM:** Smart Pointers (`std::unique_ptr` & `std::move`)