cmake_minimum_required(VERSION 3.10)
project(SistemaRiego_SIGA LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Compila únicamente main y la lógica de Historial
add_executable(SIGA_App_Fresh 
    main.cpp
    src/Historial.cpp
    src/SensorLDR.cpp
)