// =================================================================
//
// File: activity.h
// Author: Oscar Eduardo Nieto Espitia A01705090
// Date:Agosto 20 del 2021
//
// =================================================================
#ifndef ACTIVITY_H
#define ACTIVITY_H

// =================================================================
// sumaIterativa. Calculate the sum from 1 to n with an iterative
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// =================================================================
unsigned int sumaIterativa(unsigned int n) {
	double acum = 0;

	for (int i = 1; i <= n; i++){
		acum += i;
	}

	return acum;
}

// =================================================================
// sumaRecursiva. Calculate the sum from 1 to n with an recursive
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// =================================================================
unsigned int sumaRecursiva(unsigned int n) {
	if (n==1){
		return 1;
	}
	else {
			return (sumaRecursiva(n-1)+n);
		}
}

// =================================================================
// sumaRecursiva. Calculate the sum from 1 to n with a mathematical
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// =================================================================
unsigned int sumaDirecta(unsigned int n) {
	if (n==0){
		return 0;
	}
	else {
		n = (n*(n+1)/2);
		return n;
	}
}

#endif /* ACTIVITY_H */
