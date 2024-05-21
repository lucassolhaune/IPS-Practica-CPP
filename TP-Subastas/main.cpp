#include "lib/personas.h"
#include "lib/oferta.h"
#include "lib/lote.h"
#include "lib/subasta.h"

using namespace std;

/**
 * @brief Funcion para saber cual es el mayor monto entre 3 ofertas.
 * 
 * @param o1: Oferta 1.
 * @param o2: Oferta 2.
 * @param o3: Oferta 3.
 * @return Oferta con mayor monto.
 */
Oferta maxOferta3(Oferta o1, Oferta o2, Oferta o3) {
    //Variable que almacena el valor maximo entre las 3 ofertas.
    int maxOfer = max(o1.getMonto(), max(o2.getMonto(), o3.getMonto()));
    
    //Devuelvo la oferta con mayor monto.
    if(maxOfer == o1.getMonto())
        return o1;
    else if(maxOfer == o2.getMonto())
        return o2;
    else
        return o3;
}

int main() {
    //Subasta que va a contener la lista y cantidad de lotes que se ofrecen a continuacion.
    Subasta subasta1;

    //Crea y agrega lotes a la lista de la subasta.
    Lote lote1 = {1, "Maquinas de gimnasio"};
    subasta1.setLoteList(lote1);
    Lote lote2 = {2, "Cajas de vino"};
    subasta1.setLoteList(lote2);

    //Ingresa la cantidad de lotes a la subasta.
    subasta1.setCantLotes(size(subasta1.getLoteList()));

    //Personas que van a participar de la subasta.
    Persona persona1 = {"Lucas"};
    Persona persona2 = {"Alvaro"};
    Persona persona3 = {"Matias"};

    //Muestra en pantalla las personas.
    cout << "Los participantes de esta subasta son: " << persona1.getNombre() << ", "
    << persona2.getNombre() << " y "<< persona3.getNombre() << endl;
    
    //Ofertas realizadas para el lote 1.
    cout << "-----------------" << endl;
    cout << "Ofertas para el lote '" << lote1.getLoteName() << "'" << endl;

    //Crea e ingresa la oferta y monto de cada persona.
    Oferta oferta1 = {persona1};
    oferta1.setMonto(1203128);
    Oferta oferta2 = {persona2};
    oferta2.setMonto(2201200);
    Oferta oferta3 = {persona3};
    oferta3.setMonto(1866455);

    //Imprime las ofertas de cada persona.
    oferta1.printOferta();
    oferta2.printOferta();
    oferta3.printOferta();

    //Variable que almacena la maxima oferta del lote 1. 
    Oferta ofertaMax = maxOferta3(oferta1, oferta2, oferta3);

    //Ingresa la mayor oferta al lote 1.
    lote1.setMaxOferta(ofertaMax);

    //Imprime ganador del lote 1.
    cout << "-----------------" << endl;
    cout << ofertaMax.getOfertante() << " ha ganado el lote '" << lote1.getLoteName() << 
    "' por un monto de $" << ofertaMax.getMonto() << endl;

    //Ofertas realizadas para el lote 2.
    cout << "-----------------" << endl;
    cout << "Ofertas para el lote '" << lote2.getLoteName() << "'" << endl;

    //Ingresa la oferta y monto de cada persona.
    oferta1.setMonto(750440);
    oferta2.setMonto(645040);
    oferta3.setMonto(966481);

    //Imprime las ofertas de cada persona.
    oferta1.printOferta();
    oferta2.printOferta();
    oferta3.printOferta();

    //Almacena la maxima oferta para el lote 2. 
    ofertaMax = maxOferta3(oferta1, oferta2, oferta3);

    //Ingresa la mayor oferta al lote 2.
    lote2.setMaxOferta(ofertaMax);

    //Imprime ganador del lote 2.
    cout << "-----------------" << endl;
    cout << ofertaMax.getOfertante() << " ha ganado el lote '" << lote2.getLoteName() << 
    "' por un monto de $" << ofertaMax.getMonto() << endl;

    //Muestra la cantidad de lotes que se ofertaron.
    cout << "-----------------" << endl;
    cout << "En la subasta se ofertaron " << subasta1.getCantLotes() << " lotes." << endl;

    return 0;
}