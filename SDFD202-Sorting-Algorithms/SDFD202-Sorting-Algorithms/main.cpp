// Sorting Algorithms - SDFD___ - Alex Mounsey (2018)
// A program that can sort a set of numbers by using a selection of sorting algorithms

#include <vector>
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <chrono>

#define NUMBER_COUNT 10 // The amount of random numbers the vector stores
#define MAX_NUMBER 20 // The highest a number can be generated as

using namespace std;

vector<int> intVector;

void createVector(vector<int> & v);
void printVector(vector<int> & v);
void sortUsingInsertion(vector<int> & v);
void sortUsingBubble(vector<int> & v);
void sortUsingSelection(vector<int> & v);

// Timer variables
chrono::time_point<chrono::steady_clock> startTime, endTime;
chrono::duration<float> runTime;

void main(void) {
	// Generate new set of numbers
	createVector(intVector);
	cout << "Un-Sorted Vector: ";
	printVector(intVector);

	// Start timer
	startTime = chrono::high_resolution_clock::now();

	//sortUsingInsertion(intVector);
	sortUsingBubble(intVector);
	//sortUsingSelection(intVector);

	// End timer + calculate runtime (milliseconds)
	endTime = chrono::high_resolution_clock::now();
	runTime = endTime - startTime;

	// Print results
	cout << "Sorted Vector: ";
	printVector(intVector);
	cout << endl << "Finished sorting " << NUMBER_COUNT << " numbers." << endl;
	cout << "Elapsed Time = " << (float)runTime.count() * 1000.0f << "ms" << endl;

	_getch();
}

// Fill a vector with a set of random numbers
void createVector(vector<int> & v) {
	for (int i = 0; i < NUMBER_COUNT; i++) v.push_back((rand() % MAX_NUMBER) + 1);
}

// Print the contents of a vector
void printVector(vector<int> & v) {
	for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
	cout << endl;
}

// Sort a vector using the insertion algorithm
void sortUsingInsertion(vector<int> & v) {
	for (int i = 1; i < v.size(); i++) {
		int key = v[i];
		int j = i - 1;

		while (j >= 0 && v[j] > key) {
			v[j + 1] = v[j];
			j = j - 1;
		}

		v[j + 1] = key;
	}
}

// Sort a vector using the bubble algorithm
void sortUsingBubble(vector<int> & v) {
	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = 0; j < v.size() - i - 1; j++) {
			if (v[j] > v[j + 1]) swap(v.at(j), v.at(j + 1));
		}
	}
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