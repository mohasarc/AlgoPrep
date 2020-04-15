/**
* Author: Mohammed S. Yaseen
* ID: 21801331
* Section: 3
* Assignment: 2
**/

#ifndef DECISIONTREE_H
#define DECISIONTREE_H
#include "DecisionTreeNode.h"
#include "helpingFunctions.h"

class DecisionTree{
public:
    void train(const bool** data, const int* labels, const int numSamples, const int numFeatures);
    void train(const string fileName, const int numSamples, const int numFeatures);
    int predict(const bool* data);
    double test(const bool** data, const int* labels, const int numSamples);
    double test(const string fileName, const int numSamples);
    void print();

private:
    int findFeatureIDToSplit(const bool** data, const int* labels, const int numSamples,
                           const int numFeatures, bool* usedSamples, bool* usedFeatures);
    void buildDecisionTree(const bool** data, const int* labels, const int numSamples,
                           const int numFeatures, bool* usedSamples, bool* usedFeatures, 
                           DecisionTreeNode* root, int *classes, int numClasses);
    void printTree(DecisionTreeNode *root, int level);
    bool isLeaf(bool *usedFeatures, bool *usedSamples, int numSamples, int numFeatures, const int *labels);

    // Class preoperties
    int numFeatures;
    DecisionTreeNode *root;
};

#endif