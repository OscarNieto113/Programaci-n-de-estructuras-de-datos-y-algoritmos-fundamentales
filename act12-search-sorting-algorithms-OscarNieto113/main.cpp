// =================================================================
//
// File: main.cpp
// Author:Oscar Eduardo Nieto Espitia A01705090
// Date:
//
// =================================================================
#include <iostream>
#include <vector>
#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {
	int tamArreglo = 600; // Tamanio del arreglo
	int arregloAux [tamArreglo]; //Arreglo que me va a proporcionar mi usuario
	int arregloInsertionSort [tamArreglo]; //Arreglo en el que se van a imprimir las posiciones de Insrtion Sort
	int arregloSelectionSort [tamArreglo]; //Arreglo en el que se van a imprimir las posiciones de Selection Sort
	int arregloBubbleSort [tamArreglo]; //Arreglo en el que se van a imprimir las posiciones de Bubble Sort

	int compInsertion=0; //Numero de comparaciones que hara el Insertion Sort
	int compSelection=0; //Numero de comparaciones que hara el Selection Sort
	int compBubble=0; //Numero de comparaciones que hara el Bubble Sort
	int n, q;

//=======================================================================
//Lectura de datos (entrada)
	std::cin >> n; //n es un numero entero positivo que indica el numero de elementos a leer
	for (int i = 0; i < n; i++){ //Ciclo que le graba el input del usuario a una lista
		std::cin >> arregloAux[i];
		arregloInsertionSort[i]=arregloAux[i];
		arregloSelectionSort[i]=arregloAux[i];
		arregloBubbleSort[i]=arregloAux[i];
	}

	std::cin >> q; //Cantidad de numeros a buscar
	int arregloNumBusqueda [q]; //Arreglo de numeros a buscar
	for (int i = 0; i < q; i++){ //Ciclo que graba los numeros a buscar en una lista
		std::cin >> arregloNumBusqueda[i];
	}

//==========================================================================
//Datos de salida
	compSelection=selectionSort(arregloSelectionSort, n);
	compInsertion= insertionSort(arregloInsertionSort, n);
	compBubble=bubbleSort(arregloBubbleSort, n);
	std::cout<<compBubble<<" "<<compSelection<<" "<<compInsertion<<endl; //Imprime
	std::cout<<""<<endl;


	//int upperLimit=n-1;
	for (int i=0; i < q; i++){
		int numBusqueda=arregloNumBusqueda[i];
		int pos=binaryRSearch(arregloSelectionSort, 0, n, numBusqueda);
		int compSequential=sequentialSearch(arregloSelectionSort, numBusqueda, n);
		int compBinary=binarySearch(arregloSelectionSort, numBusqueda, n);
		std::cout<<pos<<" "<<compSequential<<" "<<compBinary<<endl;
	}
	return 0;
}

//Output: Posicion, comparaciones de busqueda Secuencial/Binarai
