cmake_minimum_required(VERSION 3.25)
project(TP_Subastas)

set(CMAKE_CXX_STANDARD 23)

add_executable(TP_Subastas main.cpp lib/personas.h lib/oferta.h lib/lote.h lib/subasta.h)
