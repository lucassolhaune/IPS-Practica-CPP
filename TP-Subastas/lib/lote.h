//
// Created by leand on 4/5/2023.
//

#ifndef TP_SUBASTAS_LOTE_H
#define TP_SUBASTAS_LOTE_H

#include <utility>
#include "oferta.h"

class Lote {
private:
    int nLote;
    string nombre;
    Oferta ofertaMax;
public:
    /**
     * @brief Constructor para la clase Lote
     *
     * Nota: para poder omitir el argumento oferta en el constructor Lote (y por ende,
     * ingresar el maximo a traves de una funcion que lo haga), se tuvieron que modificar las 
     * clases Oferta y Persona de modo tal que el constructor por defecto de ambos no tengan parametros.
     * 
     * @param nLote: Numero de lote.
     * @param nombre: Nombre del lote.
     * @param oferta: Valor maximo ofertado por el lote.
     */
    Lote(int nLote, string nombre) {
        this->nLote = nLote;
        this->nombre = std::move(nombre);
    }

    /**
     * @brief Funcion que guarda el valor maximo ofertado por el lote.
     *
     * @param ofertaMax: Valor maximo ofertado por el lote.
     */
    void setMaxOferta(Oferta oferta) {
        ofertaMax = std::move(oferta);
    }

    /**
     * @brief Funcion para obtener el nombre del lote.
     * 
     * @return nombre del lote.
     */
    string getLoteName() {
        return nombre;
    }
};

#endif //TP_SUBASTAS_LOTE_H
