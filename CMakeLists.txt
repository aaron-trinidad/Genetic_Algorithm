cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Genetic_Algorithm)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agregar directorios de búsqueda para archivos de cabecera
include_directories(include)

# Fuentes del proyecto
file(GLOB SOURCES "src/*.cpp")

# Crear el ejecutable
add_executable(gen_alg ${SOURCES})
