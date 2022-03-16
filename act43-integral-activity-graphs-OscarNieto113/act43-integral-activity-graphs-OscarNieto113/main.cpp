// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <sstream>
#include "ugraph.h"
#include <cstring>
#include <string.h>

using namespace std;


int main(int argc, char* argv[]) {
	UListGraph<string> *graph;
	int n, m, MNP; // Number of conections in the graph
	string input, from, to, port; //Contains from and to
	std::vector<std::string> from_to;


	cin >> n;
	graph = new UListGraph<string>(n);

	for (int i = 0; i < n; i++){
		cin >> from >> to;
		graph->addEdge(from, to);
		//cout<< from << " " << to <<"\n";
	}

	cin >> m;
	int j = 1;
	for (int i = 0; i < m; i++){
		cin >> port >> MNP;
		int a = 1;
		printLevels (port ,graph, MNP);
		std::cout << "Case " << j << ": "<< a << " ports not reachable from port " << port << " with MNP = " << MNP << ". \n";
		j++;
	}
	delete graph;

	return 1;
}
