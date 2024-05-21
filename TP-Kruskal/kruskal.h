#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

/**
	* @type arista
	* @brief Tipo definido por un pair de pair y entero
	*
	* Arista esta compuesta por un pair <pair <char , char >, int >
	* ambos char son vertice origen y destino y el int el costo entre ellos
	*/
typedef pair <pair <char, char>, int> arista; /// v1 , v2 y costo entre ellos

/**
	* @struct combina_encuentra
	* @param nombres: es un map cuya key sera un char (nombre del vertice)
	* y un pair con el vertice y el vertice siguiente (adyacente)
	*
	* @param encabezados: map cuya key sera un char (vertice) y un pair que tiene a
	* un entero como indice de cantidad de adyacencias y el primer
	* elemento del conjunto de vertices .
	*/
typedef struct combina_encuentra {
	map <char, pair <char, char>> nombres; /// vertice y vertice siguiente
	map <char, pair <int, char>> encabezados; /// cuenta y primer elemento
} conjunto_CE;

/**
	* @class MenorValor
	* @brief Clase que fija el criterio de ordenamiento a la cola de prioridad
	*
	* La priority_queue definida como tipo arbol guardar las aristas ordenadamente
	* segun su peso de menor a mayor para luego poder ser usada en el algoritmo
	*
	*/
class MenorValor {
public:
	/**
		* @brief sobrecarga al operador () para la ocomparacin de pesos
		* @param e1 de tipo arista
		* @param e2 de tipo arista
		* @return true en caso que el peso de e1 sea mayor al de e2
		*/
	bool operator ()(arista e1, arista e2) {
		return e1.second > e2.second;
	}
};

/**
	* @type arbol
	* @brief lista de prioridad de aristas ordenada de menor a mayor costo
	*
	* Arbol es una priority_queue de aristas .
	* El criterio de ordenamiento lo da MenorValor la cual establece la
	* comparacion de los costos de las aristas.
	*/
typedef priority_queue <arista, vector <arista>, MenorValor> arbol;

class grafo {
private:
	vector <char> V; /// Conjunto de vertices
	vector <arista> E; /// Conjunto de aristas con sus pesos
	conjunto_CE CE; /// Estructura para el analisis de adyacencias
	arbol grafo_ordenado; /// cola de prioridad con los pesos de las aristas
	vector <arista> arbol_minimo; /// Arbol de minimal
public:
	grafo() {} /// constructor
	~grafo() {} /// destructor
	void insertar_vertice(const char&); /// Guarda los evrtices en el conjunto V
	void insertar_arista(const char&, const char&, const int&); /// Guarda las aristas en el Conjunto E
	void insertar_arista(); /// Guarda las aristas en el conjunto E pidiendolas ingresar por Teclado
	void inicial(const char&, const char&); /// inicializa a las estructuras de conjunto COMBINA - ENCUENTRA
	void combina(const char&, const char&); /// Combina las aristas que se encuentran formando el ´arbol
	char encuentra(const char&); /// Encuentra los vertices dentro del conjunto COMBINA - ENCUENTRA
	void kruskal(); /// Algoritmo generador del ´arbol recubridor minimal
	void inserta(); /// Guarda al conjunto E dentro de la cola de prioridad teniendo en cuenta los costos .
	friend ostream& operator <<(ostream&, grafo); /// Sobrercarga de la salida ´aestndar para mostrar al grafo
};