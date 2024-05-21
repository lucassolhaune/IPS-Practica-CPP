//
// Created by leand on 4/5/2023.
//

#ifndef TP_SUBASTAS_SUBASTA_H
#define TP_SUBASTAS_SUBASTA_H

#include "lote.h"
#include <utility>
#include <list>

class Subasta {
private:
    list <Lote> lotes;
    int cantLotes;
public:
    /**
     * @brief Constructor para la clase subasta.
     * 
     */
    Subasta() = default;

    /**
     * @brief Funcion que almacena lotes a la lista.
     * 
     * @param lote: Lote creado para guardar en la lista.
     */
    void setLoteList(const Lote& lote) {
        this->lotes.push_back(lote);
    }

    /**
     * @brief Funcion para ingresar cantidad de lotes.
     * 
     * @param cant 
     */
    void setCantLotes(int cant) {
        cantLotes = cant;
    }
    
    /**
     * @brief Funcion para obtener la lista de lotes almacenados.
     * 
     * @return lotes: Vector de lotes.
     */
    list <Lote> getLoteList() {
        return lotes;
    }

    /**
     * @brief Funcion para obtener la cantidad de lotes que se
     * encuentran almacenados en el vector.
     * 
     * @return cantLotes: Cantidad de lotes.
     */
    int getCantLotes() {
        return cantLotes;
    }
};

#endif //TP_SUBASTAS_SUBASTA_H
