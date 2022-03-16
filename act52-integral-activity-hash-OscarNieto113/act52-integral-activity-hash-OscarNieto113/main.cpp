// =================================================================
//
// File: main.cpp
// Author:
// Date:
//
// =================================================================
#include <iostream>
#include <map>
#include <string>
#include "exception.h"
#include "header.h"

using namespace std;

int getSalaryByDescription(std::map<string, int> SBP, string JD){
	int acum = 0;
	return acum;
}

int main(int argc, char* argv[]) {
	int m, n, salary;
	string profession, JobDescription;
	//uint salary;
	map <string, int> SalariesByProfession;
	map <string, int>::iterator itr;

	cin >> m >> n;
	for (int i = 0; i < m ; i++){
		cin >> profession >> salary;
		SalariesByProfession.insert(pair<string, uint>(profession, salary));
	}

	for (int i = 0; i < n; i++){
		string word = ("chunchunmaru");
		int acum = 0;
		while (word != "."){
			cin >> word;
			itr = SalariesByProfession.find(word);
			if (itr != SalariesByProfession.end()){
				acum += itr->second;
			}
		}
		std::cout << acum << endl;
	}
	return 0;
}
