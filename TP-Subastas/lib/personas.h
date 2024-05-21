//
// Created by leand on 4/5/2023.
//

#ifndef TP_SUBASTAS_PERSONAS_H
#define TP_SUBASTAS_PERSONAS_H

#include <iostream>
#include <utility>

using namespace std;

class Persona {
private:
    string nombre;
public:
    /**
     * @brief Constructor por defecto para la clase Persona.
     * 
     * Nota: Aclaracion en el header "lote.h"
     * 
     */
    Persona() = default;

    /**
     * @brief Constructor para la clase persona.
     * @param nombre: Nombre de la persona.
     */
     Persona(string nombre) {
        this->nombre = std::move(nombre);
    }
    /**
     * @brief Funcion que devuelve el nombre de la persona.
     * 
     * @return Nombre de la persona.
     */
    string getNombre() {
        return nombre;
    }
};
#endif //TP_SUBASTAS_PERSONAS_H
