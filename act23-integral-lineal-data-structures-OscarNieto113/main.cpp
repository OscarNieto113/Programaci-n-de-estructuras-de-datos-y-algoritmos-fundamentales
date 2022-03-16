// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <string>
#include <vector>
#include "list.h"

using namespace std;

// =================================================================
// Search a prefix on a vector.
//
// @param linea, a vector of string elements.
// @param i, position of the element in vector.
// @param ide, prefix to search.
// =================================================================
bool buscar(vector<string> &linea, int i, string &ide){
	size_t found = linea[i].find(ide);	//O(1)
	return ((found != string::npos));		//O(1)
}


// =================================================================
// Performs Bubble Sort algorithm on a vector.
//
// @param ordenar, a vector of string elements.
// =================================================================
void bubbleSort(vector<string> &ordenar){
	int size = ordenar.size() - 1;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			string dia1=ordenar[j].substr(0,2);
			string dia2=ordenar[j+1].substr(0,2);
			string month1=ordenar[j].substr(3,2);
			string month2=ordenar[j+1].substr(3,2);
			if (month1 == month2){
				if (dia1 > dia2){
					swap(ordenar, j, j + 1);
				}
			}
			else {
				if (month1 > month2){
					swap(ordenar, j, j + 1);
				}
			}
		}
	}
}

// =================================================================
// Print the sorted vector on a specific format.
//
// @param pbm, a vector of string elements.
// =================================================================
void printByMonth (vector<string> &pbm){
	DoubleLinkedList <string> IdentificadorR;		//O(1)
	DoubleLinkedList <string> IdentificadorM;		//O(1)
	int size = pbm.size() ;		//O(1)
	uint pos = 0;		//O(1)
	string monthNumber[12] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};		//O(1)
	string monthWrite[12]= {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};		//O(1)
	for (int j = 0; j < size; j++){		//O(N)
		string month = pbm[j].substr(3, 2);		//O(1)
		string puntoDeEntrada = pbm [j].substr (15, 1);		//O(1)
		string Ide = pbm [j].substr (17, 5);		//O(1)
		//std::cout << month <<" " << puntoDeEntrada << " " << Ide << endl;
		if (month == monthNumber[pos]){		//O(1)
			if (puntoDeEntrada == "M"){		//O(1)
				IdentificadorM.push_back(Ide);		//O(1)
			}
			else {
				IdentificadorR.push_back(Ide);		//O(1)
			}
		}
		else {
			if ((IdentificadorM.empty()) && (IdentificadorR.empty())){		//O(1)
				pos++;		//O(1)
			}
			else{
				std::cout << monthWrite[pos] << endl;		//O(1)
				if (IdentificadorM.empty()!= true){		//O(1)
					std::cout << "M " << IdentificadorM.length() << ": " << IdentificadorM.toString() <<endl;		//O(1)
				}
				if (IdentificadorR.empty()!= true){		//O(1)
					std::cout << "R " << IdentificadorR.length() << ": " << IdentificadorR.toString() <<endl;		//O(1)
				}
				pos++;		//O(1)
				IdentificadorM.clear();		//O(1)
				if ((month == monthNumber[pos])&&(puntoDeEntrada=="M")){
					IdentificadorM.push_back(Ide);		//O(1)
				}
				IdentificadorR.clear();
				if ((month == monthNumber[pos])&&(puntoDeEntrada=="R")){
					IdentificadorR.push_back(Ide);		//O(1)
				}
			}
		}
	}
	std::cout << monthWrite[pos] << endl;		//O(1)
	if (IdentificadorM.empty()!= true){		//O(1)
		std::cout << "M " << IdentificadorM.length() << ": " << IdentificadorM.toString() <<endl;		//O(1)
	}
	if (IdentificadorR.empty()!= true){		//O(1)
		std::cout << "R " << IdentificadorR.length() << ": " << IdentificadorR.toString() <<endl;		//O(1)
	}
	IdentificadorM.clear();		//O(1)
	IdentificadorR.clear();		//O(1)
}



int main(int argc, char* argv[]) {
	//Inicializamos las primeras variables de entrada
	int barcos; //Numero de barcos que van a entrar
	string prefix; //Prefijo a buscar
	cin >> barcos; cin >> prefix;

	//Entrada de barcos dada por el usuario
	vector <string> barcosFiltrados; //Vector tipo string que va a almacenar los barcos una vez que se hayan filtrado
	vector <string> entrada(barcos); //Vector tipo string de tam anteriormente especificado, almacena las entradas
	string registroBarco;
	for (int i=0; i < barcos; i++){	 		//O(n)
		getline(cin, registroBarco); 			//O(1)
		entrada[i]=registroBarco; 				//O(1)
	}

	//Ciclo que guarda en un nuevo vector la informacion de los barcos que cumplen con el prefijo especificado
	for (int i = 0; i < barcos; i++){	 				//O(n)
		if (buscar(entrada, i, prefix)==true){	//O(1)
			barcosFiltrados.push_back(entrada[i]);//O(1)
		}
	}

	//Ordenamos por mes y dia para que a la hora de imprimir los barcos sea mas facil
	bubbleSort (barcosFiltrados);
	int sizeBarcosFiltrados = barcosFiltrados.size();
	//for (int i = 0; i < sizeBarcosFiltrados; i++){
	//	cout << barcosFiltrados[i]<< endl;
	//}
	printByMonth (barcosFiltrados);



	return 0;
}
