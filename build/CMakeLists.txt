cmake_minimum_required(VERSION 3.10)
project(SistemaRiego_SIGA LANGUAGES CXX)

# Usamos el estándar moderno de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Le decimos a CMake dónde buscar los planos (.h)
include_directories(include)

# Creamos el ejecutable final juntando los archivos de lógica
add_executable(SIGA_App 
    main.cpp
    src/SensorLDR.cpp
)