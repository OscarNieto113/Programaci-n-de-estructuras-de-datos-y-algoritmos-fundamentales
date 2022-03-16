// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include "heap.h"

using namespace std;


// =================================================================
// Calculates the numer of comparisons by a given minHeap
//
//
// @param Heap, pointer to heap.
// @returns, Returns the number of comparisons given by the formula (m+n-1).
// =================================================================
int NumOfComparison (Heap<int> &Heap){
  int N;
	int M;
	int acum=0;
	uint aux;

  while (!Heap.empty()){
		N = Heap.remove();
		M = Heap.remove();
		aux = N + M - 1;
    acum += aux;
    aux+=1;
		Heap.add(aux);

		if (Heap.length() <= 1){
			break;
		}
	}
  Heap.clear();
  return acum;
}


int main(int argc, char* argv[]) {
	int numList; // Number of objects in heap
  uint aux;
	cin >> numList;
	Heap<int> heap(numList);

	for (int i=0; i < numList; i++){
			cin >> aux;
			heap.add(aux);
	}
  int noc=NumOfComparison(heap);
  std::cout << noc << endl;

	return 0;
}
