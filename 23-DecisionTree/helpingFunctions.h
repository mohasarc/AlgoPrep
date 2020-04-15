/**
* Author: Mohammed S. Yaseen
* ID: 21801331
* Section: 3
* Assignment: 2
**/

#ifndef HELPINGFUNCTIONS_H
#define HELPINGFUNCTIONS_H
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#define MAX_ARRAY_SIZE 25000     // Tha maximum size allowed for all arrays (number of samples should be equal or less)
using namespace std;

extern double calculateEntropy(const int* classCounts, const int numClasses);
extern double calculateInformationGain(const bool** data, const int* labels, const int numSamples, 
                                       const int numFeatures, const bool* usedSamples, const int featureId);
extern void findClasses(int *labels, int numSamples, int *classes, int &numClasses);
extern bool exists(int toFind, int* arr, int size);
extern bool readFile(string fileName, string &data);
extern void parseDataRead(string dataRead, int numFeatures, bool **data, int *labels);
#endif