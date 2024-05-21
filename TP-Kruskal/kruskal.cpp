#include "kruskal.h"

/**
 * @brief Guarda los vertices en el conjunto V
 * @param v Vertice
*/
void grafo :: insertar_vertice(const char& v) {
	V.push_back(v);
}

/**
 * @brief Guarda las aristas en el Conjunto E
 * @param u Vertice 1
 * @param v Vertice 2
 * @param costo Costo de la arista
*/
void grafo :: insertar_arista(const char& u, const char& v, const int& costo) {
	E.push_back({ {u,v}, costo });
}
/**
 * @brief Guarda las aristas en el Conjunto E pidiendolas ingresar por teclado
*/
void grafo::insertar_arista() {
	char u, v;
	int costo;

	cout << "Ingrese" << endl << "Vertice 1: ";
	cin >> u;
	cout << "Vertice 2: ";
	cin >> v;
	cout << "Costo: ";
	cin >> costo;

	insertar_arista(u, v, costo);
}

/**
 * @brief Inicializa a las estructuras de conjunto COMBINA - ENCUENTRA
 * @param comp_nombre 
 * @param elem 
*/
void grafo::inicial(const char& comp_nombre, const char& elem) {
	CE.nombres[comp_nombre] = { comp_nombre, NULL };
	CE.encabezados[comp_nombre] = { 1, elem };
}

/**
 * @brief Combina las aristas que se encuentran formando el arbol
 * @param A Conjunto vertice A
 * @param B Conjunto vertice B
*/
void grafo::combina(const char& A, const char& B) {
	int contA = CE.encabezados[A].first;
	int contB = CE.encabezados[B].first;
	int numVertices = CE.encabezados.size();
	char i;

	if (CE.encabezados[A].first > CE.encabezados[B].first) {
		i = CE.encabezados[B].second;
		for (int j = 0; j < numVertices; j++) {
			CE.nombres[i].first = A;
			i = CE.nombres[i].second;
		}
		CE.nombres[i].first = A;
		CE.nombres[i].second = CE.encabezados[A].second;
		CE.encabezados[A].first = CE.encabezados[A].first + CE.encabezados[B].first;
	}
	else {
		i = CE.encabezados[A].second;
		for (int j = 0; j < numVertices; j++) {
			CE.nombres[i].first = B;
			i = CE.nombres[i].second;
		}
		CE.nombres[i].first = B;
		CE.nombres[i].second = CE.encabezados[B].second;
		CE.encabezados[B].first = CE.encabezados[B].first + CE.encabezados[A].first;
	}
}

/**
 * @brief Encuentra los vertices dentro del conjunto COMBINA - ENCUENTRA
 * @param v Vertice
 * @return Nombre del conjunto perteneciente del vertice v
*/
char grafo::encuentra(const char& v) {
	return CE.nombres[v].first;
}

/**
 * @brief Algoritmo generador del arbol recubridor minimo.
 * Dado un arbol con aristas organizadas por sus costos, analiza si es posible
 * incluir la arista de menor peso sin que forme un ciclo.
 *
 * El ciclo se detecta cuando dos vertices pertenecen al mismo conjunto. Es decir, la funcion compara los conjuntos
 * que pertenecen los vertices, si son distintos llama a la funcion combina() y los inserta en arbol_minimo
*/
void grafo::kruskal() {
	arista a;
	conjunto_CE componentes;
	int comp_n = V.size();
	char comp_u, comp_v;

	for (char x: V) {
		inicial(x, x);
	}
	cout << "El subgrafo desarrollado por kruskal es:" << endl;
	inserta();
	while (comp_n > 1) {
		a = grafo_ordenado.top();
		grafo_ordenado.pop();
		comp_u = encuentra(a.first.first);
		comp_v = encuentra(a.first.second);

		if (comp_v != comp_u) {
			combina(comp_u, comp_v);
			comp_n--;
			arbol_minimo.push_back(a);
			cout << a.first.first << " - " << a.first.second << ", " << a.second << endl;
		}
	}
}

/**
 * @brief Guarda al conjunto E dentro de la cola de prioridad teniendo en cuenta los costos.
*/
void grafo::inserta() {
	for (auto i = E.begin(); i != E.end(); i++) {
		char u = (*i).first.first;
		char v = (*i).first.second;
		int costo = (*i).second;

		grafo_ordenado.push({ {u,v}, costo });
	}
}

/**
 * @brief Sobrercarga de la salida estandar para mostrar al grafo.
 * @param os 
 * @param g
 * @return os
*/
ostream& operator <<(ostream& os, grafo g) {
	os << "Grafo" << endl;
	for (auto x : g.E) {
		os << x.first.first << " - " << x.first.second << ", " << x.second << endl;
	}
	return os;
}

int main() {
	grafo grafo1;

	grafo1.insertar_vertice('1');
	grafo1.insertar_vertice('2');
	grafo1.insertar_vertice('3');
	grafo1.insertar_vertice('4');
	grafo1.insertar_vertice('5');
	grafo1.insertar_vertice('6');

	//Ingreso de costos en base al ejemplo del apunte de Kruskal.
	grafo1.insertar_arista('1', '2', 6);
	grafo1.insertar_arista('1', '3', 1);
	grafo1.insertar_arista('1', '4', 5);
	grafo1.insertar_arista('2', '3', 5);
	grafo1.insertar_arista('2', '5', 3);
	grafo1.insertar_arista('3', '4', 5);
	grafo1.insertar_arista('3', '5', 6);
	grafo1.insertar_arista('3', '6', 4);
	grafo1.insertar_arista('4', '6', 2);
	grafo1.insertar_arista('5', '6', 6);

	//Llamada a la funcion kruskal para obtener el subgrafo.
	grafo1.kruskal();

	return 0;
}