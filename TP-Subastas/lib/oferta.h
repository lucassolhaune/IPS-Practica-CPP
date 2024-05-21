//
// Created by leand on 4/5/2023.
//

#ifndef TP_SUBASTAS_OFERTA_H
#define TP_SUBASTAS_OFERTA_H

#include <iostream>
#include <utility>
#include "personas.h"

class Oferta {
private:
    int monto;
    Persona persona;
public:
    /**
     * @brief Constructor por defecto para la clase Oferta.
     * 
     * Nota: Aclaracion en el header "lote.h"
     * 
     */
    Oferta() = default;

    /**
     * @brief Constructor para la clase Oferta.
     * 
     * @param persona: Persona que realiza la oferta.
     */
    Oferta(Persona persona) : persona(std::move(persona)) {
        monto = 0;
    }
    
    /**
     * @brief Funcion para ingresar el monto de la oferta.
     * 
     * @param monto: monto a ingresar.
     */
    void setMonto(int monto) {
        if(monto > 0)
            this->monto = monto;
    }
    
    /**
     * @brief Funcion que devuelve el valor de la oferta.
     * 
     * @return Monto de la oferta.
     */
    int getMonto() {
        return monto;
    }
    
    /**
     * @brief Funcion que retorna la persona que realiza la oferta.
     * 
     * @return Persona que realiza la oferta.
     */
    string getOfertante() {
        return persona.getNombre();
    }

    /**
     * @brief Imprime la oferta con el nombre de la persona y el monto.
     */
    void printOferta() {
           cout << getOfertante() << " oferta $" << getMonto() << " " << endl;
    }
};

#endif //TP_SUBASTAS_OFERTA_H
