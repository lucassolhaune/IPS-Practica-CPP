#include "CacheManager.h"

/**
 * @brief Constructor de la clase CacheManager.
 * @tparam: T Clase
 * @param cap: Capacidad de memoria
*/
template <class T>
CacheManager <T>::CacheManager(int cap) {
    capacity = cap;
}

/**
 * @brief Destructor de la clase CacheManager.
 * @tparam T: Clase
*/
template <class T>
CacheManager <T>::~CacheManager() {}

/**
 * @brief Muestra los objetos almacenados en memoria.
 * @tparam T: Clase
*/
template <class T>
void CacheManager <T>::printCache() {
    for (auto obj : cache_data) {
        cout << "Key: " << obj.first << endl <<
            "\n\tNombre: " << obj.second.first.getData() << endl <<
            "\n\tValor MRU: " << obj.second.second << endl <<
            "\n\tID: " << obj.second.first.getId() << endl;
    }
}

/**
 * @brief Escribe los objetos junto a su clave en un archivo txt.
 * @tparam T: Clase
 * @return True si se escribio correctamente. False en caso contrario.
*/
template <class T>
bool CacheManager <T>::writeFile() {
    //Abre el archivo en modo de escritura.
    ofstream file;
    file.open("cache.txt", ios::out);
    //Mensaje de error en caso de no poder abrirlo.
    if (file.fail()) {
        cerr << "No se pudo abrir el archivo" << endl;
        return false;
    }
    //Escribe en el archivo la key junto a los datos de cada objeto.
    for (auto obj : cache_data) {
        file << obj.first << " - "
            << obj.second.first.getId() << " - "
            << obj.second.first.getData() << " - "
            << obj.second.first.getValue() << endl;
    }
    file.close();
    return true;
}

/**
 * @brief Inserta un objeto en el archivo a partir de una key y, en caso de ser necesario,
 * lo agrega tambien en la memoria.
 * @tparam T: Clase
 * @param key: Clave del objeto
 * @param obj: Objeto
*/
template <class T>
void CacheManager <T>::_insert(string key, T obj) {
    //Si la memoria se encuentra vacia,
    //ingresa el objeto en la misma y en el archivo.
    if (cache_data.empty()) {
        cache_data.insert(make_pair(key, make_pair(obj, MRU)));
        writeFile();
    }
    else {
        //Si la clave ya existe, actualiza el objeto.
        if (isKeyUsed(key)) {
            cache_data.at(key).first = obj;
            cache_data.at(key).second = ++MRU;
            writeFile();
        }
        //Si la memoria se encuentra llena, toma el objeto
        //menos usado recientemente (LRU) y lo reemplaza por el
        //nuevo.
        else if (isCacheFull()) {
            string key = getLruKey();
            cache_data.at(key).first = obj;
            cache_data.at(key).second = ++MRU;
            writeFile();
        }
        //Si el objeto no existe ni la memoria se encuentra llena,
        //lo agrega tanto en el archivo como en la memoria
        else {
            cache_data.insert(make_pair(key, make_pair(obj, ++MRU)));
            writeFile();
        }
    }
}

/**
 * @brief Devuelve el objeto almacenado en la memoria o en el archivo
 * a partir de la key pasada como argumento y, en caso de obtenerlo, actualiza su valor de MRU.
 * @tparam T: Clase
 * @param key: Clave del objeto
 * @return Objeto
*/
template <class T>
T CacheManager <T>::get(string key) {
    //Mensaje de error en caso de no encontrar el objeto con la key indicada.
    if (!isKeyUsed(key)) {
        throw  std::invalid_argument("Error: El obj no existe en cache ni en archivo.");
    }
    //Si se encuentra, se actualiza el MRU y lo devuelve.
    cache_data.at(key).second = ++MRU;
    return cache_data.at(key).first;
}

/**
 * @brief Devuelve la key del elemento almacenado en
 * la cache que tiene el valor de uso mas bajo.
 * @tparam T: Clase
 * @return Key con el MRU mas bajo (LRU).
*/
template <class T>
string CacheManager <T>::getLruKey() {
    string lru_key = "";
    int LRU = MRU;

    //Compara el valor de MRU entre los objetos
    //hasta llegar al valor mas bajo.
    for (auto x : cache_data) {
        auto objAux = x.second;
        if (LRU > objAux.second) {
            lru_key = x.first;
            LRU = objAux.second;
        }
    }
    return lru_key;
}

/**
 * @brief Informa si una clave se encuentra utilizada en un objeto
 * almacenado en cache.
 * @tparam T: Clase
 * @param key: Clave del objeto
 * @return True si se encuentra en uso. False en caso contrario.
*/
template <class T>
bool CacheManager <T>::isKeyUsed(string key) {
    for (auto x : cache_data) {
        if (key == x.first) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Informa si la cache se encuentra llena.
 * @tparam T: Clase
 * @return True si esta llena. False en caso contrario.
*/
template <class T>
bool CacheManager <T>::isCacheFull() {
    return (int)cache_data.size() == capacity;
}

class Student {
private:
	int id;
	int value;
	const char* data;
public:
	static const string class_name;
	Student(int _key, int _value, const char* _data);
	~Student();
	void printStudent();
	const char* getData();
	int getValue();
	int getId();
	friend ostream& operator <<(ostream&, Student);
};

Student::Student(int _key, int _value, const char* _data) : id(_key), value(_value), data(_data) {}

Student::~Student() {}

void Student::printStudent() {
	cout << "\n\tNombre: " << data << endl <<
		"\n\tValor: " << value << endl <<
		"\n\tID: " << id << endl;
}

const char* Student::getData() {
	return data;
}

int Student::getValue() {
	return value;
}

int Student::getId() {
	return id;
}

ostream& operator <<(ostream& os, Student student) {
	os << student.id << " - " << student.value << " - " << student.data;
	return os;
}

const string Student::class_name = "StudentClass";

int main() {
	string get_KeyInput;	//Variable que almacena la key para pasar como parametro en la funcion get().
	CacheManager <Student> my_cache(4);	//Define el tamaño de la cache para 4 objetos.

	//Ingreso de 2 estudiantes a la cache que se encuentra vacia.
	cout << " ---------------------- INSERT ----------------------- " << endl;
	my_cache._insert("1", Student(0, 23, "Lucas"));
	my_cache._insert("2", Student(1, 22, "Juan"));
	cout << "Se agregan los primeros dos estudiantes." << endl;
	my_cache.printCache();

	//Accede a un estudiante con el valor de la key que indique la variable get_KeyInput.
	cout << " ---------------------- GET ----------------------- " << endl;
	get_KeyInput = "1";
	Student returnedStudent = my_cache.get(get_KeyInput);
	cout << "Se accede al estudiante " << get_KeyInput << endl;
	returnedStudent.printStudent();
	cout << "Estado actual de la cache:" << endl;
	my_cache.printCache();

	//Se agregan dos estudiantes mas y la cache queda llena.
	cout << " ---------------------- INSERT ----------------------- " << endl;
	my_cache._insert("3", Student(2, 25, "Leandro"));
	my_cache._insert("4", Student(3, 29, "Veronica"));
	cout << "Se agregan dos estudiantes extra." << endl;
	my_cache.printCache();

	//La cache ya se encuentra ocupada por 4 estudiantes, por lo tanto, reemplazara un estudiante.
	cout << " ---------------------- UPDATE ----------------------- " << endl;
	my_cache._insert("5", Student(4, 22, "Alfonso"));
	cout << "Se agrega un quinto estudiante a la cache que se encuentra llena." << endl;
	my_cache.printCache();

	//Inserta un estudiante que tiene la misma key que uno ya ingresado, por ende,
	//se actualiza la cache.
	cout << " ---------------------- UPDATE ----------------------- " << endl;
	my_cache._insert("3", Student(9, 25, "Pepe"));
	cout << "Se agrega un estudiante a una key existente." << endl;
	my_cache.printCache();

	return 0;
}