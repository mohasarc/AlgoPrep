/**
* Author: Mohammed S. Yaseen
* ID: 21801331
* Section: 3
* Assignment: 2
**/

#include "helpingFunctions.h"

// This function calculates the entropy of a node
// param : classCount an array of the number of observations for each class
// param : numClasses the number of classes
double calculateEntropy(const int* classCounts, const int numClasses){
    double sum = 0;         // The number of repetitions of all classes
    double totEntropy = 0;  // The total entropy
    double ratio = 0;       // The ratio of each class reps to total reps

    for (int o = 0; o < numClasses; o++){
        sum += classCounts[o];
    }

    for (int e = 0; e < numClasses; e++){
        ratio = classCounts[e] / sum;
        if (ratio > 0)
            totEntropy += ratio * log2(ratio);
    }

    return totEntropy * -1;
}

// To calculate the information gain if the feature featureId were used
double calculateInformationGain(const bool** data, const int* labels, const int numSamples,
                                const int numFeatures, const bool* usedSamples, const int featureId) {
    // Local Variables
    int classes[MAX_ARRAY_SIZE];    // The classes
    int numClasses = 0;             // The number of classes

    double pEntropy = 0;    // H(P)
    double sEntropy = 0;    // H(S)
    double lEntropy = 0;    // H(left)
    double rEntropy = 0;    // H(right)
    int classCountsP[2][MAX_ARRAY_SIZE];   // Parent node class repetition counts
    int classCountsL[2][MAX_ARRAY_SIZE];   // Left child class repetition counts
    int classCountsR[2][MAX_ARRAY_SIZE];   // Right child class repetition counts
    double numSamplesL = 0; // Number of samples for left
    double numSamplesR = 0; // Number of samples for right
    double numSamplesP = 0; // Number of samples of the parent

    // Figure out the classes and how many are they
    findClasses((int *)labels, numSamples, classes, numClasses);

    for (int i = 0; i < numClasses; i++){
        // init classes row to classes obtained from findClasses
        classCountsL[0][i] = classes[i];
        classCountsR[0][i] = classes[i];
        classCountsP[0][i] = classes[i];
        // init num of reps to 0
        classCountsL[1][i] = 0;
        classCountsR[1][i] = 0;
        classCountsP[1][i] = 0;
    }

    // Entropy Parent : Entropy for all unused samples
    // Entropy left chiled : Entropy of all unused samples with false for feature in questions (featureId)
    // Entropy right chiled : Entropy of all unused samples with true for feature in questions (featureId)
    for (int i = 0; i < numSamples; i++){
        // if usable (not used before)
        if (!usedSamples[i]){
            numSamplesP ++;

            // Go through all classes available
            for (int k = 0; k < numClasses; k++){
                // If the class at i'th sample is same as at k'th 
                // class increment the k'th repetition count
                if (labels[i] == classCountsP[0][k]){
                    classCountsP[1][k]++;

                    // dividing the samples between left and right
                    if (data[i][featureId]){    // if 0 left, 1 right
                        // if sample belong to right increment k'th repetition
                        // count in right classes counter
                        classCountsR[1][k]++;
                        numSamplesR++;
                    } else {
                        // if sample belong to left increment k'th repetition
                        // count in left classes counter
                        classCountsL[1][k]++;
                        numSamplesL++;
                    }
                }
            }
        }
    }

    pEntropy = calculateEntropy(classCountsP[1], numClasses);
    lEntropy = calculateEntropy(classCountsL[1], numClasses);
    rEntropy = calculateEntropy(classCountsR[1], numClasses);
    // H(S) = P left * H(left) + P right * H(right)
    sEntropy = numSamplesL/numSamplesP*lEntropy + numSamplesR/numSamplesP*rEntropy;

    // IG(P,S) = H(P) - H(S)
    return pEntropy - sEntropy;
}

// Finds the classes available and their count
void findClasses(int *labels, int numSamples, int *classes, int &numClasses){
    numClasses = 0;
    int numForInit = 0; // A number that doesn't exist in 
                        // the labels to initialize the classes array

    // Find a number that doesn't exist in labels
    for (int i = 0; i < numSamples; i++){
        if (labels[i] == numForInit){
            numForInit ++;
            i = 0;
        }
    }

    // Initialize classes with numForInit
    for (int i = 0; i < numSamples; i++)
        classes[i] = numForInit;

    // Go through labels if a label doesn't exist already add it
    // and increment number of classes
    for (int i = 0; i < numSamples; i++){
        if(!exists(labels[i], classes, numClasses)){
            classes[numClasses] = labels[i];
            numClasses++;
        }
    }

}

// Checks if a number exists in an array
bool exists(int toFind, int* arr, int size){
    for (int i = 0; i < size; i++){
        if (arr[i] == toFind)
            return true;
    }

    return false;
}

// Reads a file and return a string of the data read
bool readFile(string fileName, string &data){
    string fullFileName = "./" + fileName;
	ifstream inFile(fullFileName.c_str());
	// inFile.open( fullFileName.c_str() );
	if (!inFile) {
		std::cerr << "error";
		return false;
	}
	
	data = "";
	string dataRead = "";
	while (std::getline(inFile, dataRead, ' '))
	{
		data += dataRead;
	}

	return true;
}

extern void parseDataRead(string dataRead, int numFeatures, bool **data, int *labels){
    string lineRead;
    int row = 0;

    for ( int i = 0; i < dataRead.size(); i++){
        if (dataRead[i] != '\n')
            lineRead += dataRead[i];
        else{
            for (int j = 0; j <= numFeatures; j++){
                if (j < numFeatures){
                    data[row][j] = lineRead[j] - '0';
                } else {
                    labels[row] = lineRead[j] - '0';
                }
            }

            // move to the next row and reinitialize the lineRead
            row++;
            lineRead = "";
        }
    }
}