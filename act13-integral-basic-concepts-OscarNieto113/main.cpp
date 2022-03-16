// =================================================================
//
// File: main.cpp
// Author: Oscar Eduardo Nieto Espitia
// Date:
//
// =================================================================
#include <iostream>
#include <string.h>
#include "selection.h"
#include "header.h"
#include <vector>

using namespace std;

bool buscar(vector<string> &linea, int i, string &ide){
	size_t found = linea[i].find(ide);
	return ((found != string::npos));
}

//La funcion ordenar toma como parametro un vector por referencia y lo ordenar
//segun 2 condiciones. Este los acomoda tomando como prioridad el mes y despues el dia1
//. No toma en cuenta las horas.
void bubbleSort(vector<string> &ordenar){
	int size = ordenar.size() - 1;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			string dia1=ordenar[j].substr(0,2);
			string dia2=ordenar[j+1].substr(0,2);
			string mes1=ordenar[j].substr(3,2);
			string mes2=ordenar[j+1].substr(3,2);
			if (mes1 == mes2){
				if (dia1 > dia2){
					swap(ordenar, j, j + 1);
				}
			}
			else {
				if (mes1 > mes2){
					swap(ordenar, j, j + 1);
				}
			}
		}
	}
}

int main(int argc, char* argv[]) {
	//Inicializamos las primeras variables de entrada
	int barcos; //Numero de barcos que van a entrar
	string prefijo; //Prefijo a buscar
	cin >> barcos; cin >> prefijo;

	//Entrada de barcos dada por el usuario
	vector <string> barcosFiltrados;
	vector <string> entrada(barcos);
	string registroBarco;
	for (int i=0; i < barcos; i++){
		getline(cin, registroBarco);
		entrada[i]=registroBarco;
	}

	for (int i = 0; i < barcos; i++){
		if (buscar(entrada, i, prefijo)==true){
			barcosFiltrados.push_back(entrada[i]);
		}
	}

	bubbleSort (barcosFiltrados);
	int sizeBarcosFiltrados = barcosFiltrados.size();
	for (int i = 0; i < sizeBarcosFiltrados; i++){
		cout << barcosFiltrados[i]<< endl;
	}

	return 0;
}
