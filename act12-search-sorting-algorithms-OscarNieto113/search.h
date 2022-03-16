// =================================================================
//
// File: search.h
// Author: Pedro Perez
// Description: This file contains the implementations of the
//				sequential and binary search algorithms.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
// =================================================================
#ifndef SEARCH_H
#define SEARCH_H

#include "header.h"
#include <vector>

// =================================================================
// Performs a sequential search for an element within a vector.
//
// @param A, a vector of T elements.
// @param key, the element to search.
// @return the index of the searched element, -1 in case the element
//		   is not found in the vector.
// =================================================================
template <class T>
int sequentialSearch(T*arr, int key, int size) {
	int contSequential = 0;
	for (int i = 0; i < size; i++) {
		contSequential+=1;
		if (arr[i] == key) {
			return contSequential;
		}
	}
	return contSequential;
}

// =================================================================
// Performs a binary search for an element within a vector
//
// @param A, a vector of T elements.
// @param key, the element to search.
// @return the index of the searched element, -1 in case the element
//		   is not found in the vector.
// =================================================================
template <class T>
int binarySearch(T*arr, int key, int size) {
	int low, high, mid;
	int contBin=0;
	low = 0;
	high = size - 1;
	while (low <= high) {
		mid = low + ((high - low) / 2); // mid = (high + low) / 2;
		contBin+=1;
		if (key == arr[mid]) {
			return contBin;
		} else if (key < arr[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return contBin;
}

// =================================================================
// Performs a binary search for an element within a vector
//
// @param A, a vector of T elements.
// @param low, lower limit of the search.
// @param high, upper limit of the search.
// @param key, the element to search.
// @return the index of the searched element, -1 in case the element
//		   is not found in the vector.
// =================================================================
template <class T>
int binaryRSearch(T*arr, int low, int high, int key) {
	int mid;

	if (low > high) {
		return -1;
	} else {
		mid = low + ((high - low) / 2); // mid = (high + low) / 2;
		if (key == arr[mid]) {
			return mid;
		} else if (key < arr[mid]) {
			return binaryRSearch(arr, low, mid - 1, key);
		} else {
			return binaryRSearch(arr, mid + 1, high, key);
		}
	}
}

#endif /* SEARCH_H */
