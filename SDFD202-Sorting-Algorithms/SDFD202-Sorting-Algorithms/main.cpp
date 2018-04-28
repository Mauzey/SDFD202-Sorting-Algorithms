// Sorting Algorithms - SDFD___ - Alex Mounsey (2018)
// A program that can sort a set of numbers by using a selection of sorting algorithms

#include <vector>
#include <iostream>
#include <cstdlib>

#define NUMBER_COUNT 10 // The amount of random numbers the vector stores
#define MAX_NUMBER 1000 // The highest a number can be generated as

using namespace std;

vector<int> intVector;

void createVector(vector<int> & v);
void printVector(vector<int> & v);
void sortUsingInsertion(vector<int> & v);
void sortUsingBubble(vector<int> & v);
void sortUsingSelection(vector<int> & v);

void main(void) {
	// Generate new set of numbers
	createVector(intVector);

	// Start timer and begin sorting algorithm
	sortUsingInsertion(intVector);
	sortUsingBubble(intVector);
	sortUsingSelection(intVector);

	// End timer and print results

}

// Fill a vector with a set of random numbers
void createVector(vector<int> & v) {
	for (int i = 0; i < NUMBER_COUNT; i++) v.push_back((rand() % MAX_NUMBER) + 1);
}

// Print the contents of a vector
void printVector(vector<int> & v) {
	for (int i = 0; i < v.size(); ++i) cout << v[i] << endl;
}

// Sort a vector using the insertion algorithm
void sortUsingInsertion(vector<int> & v) {

}

// Sort a vector using the bubble algorithm
void sortUsingBubble(vector<int> & v) {

}

// Sort a vector using the selection algorithm
void sortUsingSelection(vector<int> & v) {
	for (int i = 0; i < (v.size() - 1); i++) {
		int minimumValue = i;

		for (int j = i + 1; j < v.size(); ++j) {
			if (v.at(minimumValue) > v.at(j)) minimumValue = j;
		}

		if (minimumValue != i) swap(v.at(i), v.at(minimumValue));
	}
}