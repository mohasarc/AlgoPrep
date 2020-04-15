/**
* Author: Mohammed S. Yaseen
* ID: 21801331
* Section: 3
* Assignment: 2
**/

#include "DecisionTree.h"

// train function is used to make the root for the decision tree
// and call buildDecisionTree function to build the tree
void DecisionTree::train(const bool** data, const int* labels, const int numSamples, const int numFeatures){
    // Local variables
    bool usedSamples[MAX_ARRAY_SIZE];
    bool usedFeatures[MAX_ARRAY_SIZE];
    int classes[MAX_ARRAY_SIZE];
    int featureId = -1;
    int numClasses = 0;
    // Initialize variables
    findClasses((int*)labels, numSamples, classes, numClasses);
    for (int i = 0; i < numSamples; i++)
        usedSamples[i] = 0;
    for (int i = 0; i < numFeatures; i++)
        usedFeatures[i] = 0;
    
    // Store numFeatures
    this->numFeatures = numFeatures;

    // Creating the root node
    featureId = findFeatureIDToSplit(data,labels,numSamples,numFeatures, usedSamples, usedFeatures);
    root = new DecisionTreeNode();
    root->featureId = featureId;
    
    // Building the rest of the tree upon the root node
    buildDecisionTree(data, labels, numSamples, numFeatures, usedSamples, usedFeatures, root, classes, numClasses);
}

void DecisionTree::train(const string fileName, const int numSamples, const int numFeatures){
    // Local variables
    string dataRead = "";
    bool *data[MAX_ARRAY_SIZE];
    int labels[MAX_ARRAY_SIZE];

    for (int i = 0; i < MAX_ARRAY_SIZE; i++){
        data[i] = new bool[MAX_ARRAY_SIZE];
    }

    // Read the file
    readFile(fileName, dataRead);

    // Parse dataRead string into data and labels
    parseDataRead(dataRead, numFeatures, data, labels);

    // Pass the data obtained to the train function
    train((const bool**)data, labels ,numSamples, numFeatures);

    // distruct the data
    for (int i = 0; i < MAX_ARRAY_SIZE; i++){
        delete [] data[i];
    }
}

int DecisionTree::predict(const bool* data){
    // Local variables
    DecisionTreeNode* cur = root;

    // Go through nodes starting at root and go
    // left or right depending on the value from
    // the sample until reaching leaf node
    while (cur) {
        if (!data[cur->featureId]){
            // if not leaf go left
            if (cur->left)
                cur = cur->left;
            else
                // leaf so return the class
                return cur->theClass;
        } else {
            // if not leaf go right
            if (cur->right)
                cur = cur->right;
            else
                // leaf so return the class
                return cur->theClass;          
        }
    }    

    // if no tree exist return -1
    return -1;
}

double DecisionTree::test(const bool** data, const int* labels, const int numSamples){
    int prediction = 0;    // Predicted class
    double correct = 0;    // number of correct predictions
    double ratio = 0;      // The ratio of correct to all predictions

    // Go through all sample
    for (int i = 0; i < numSamples; i++){
        // Make a prediction
        prediction = predict(data[i]);
        // Assess if prediction correct
        if (prediction == labels[i])
            correct++;
    }

    ratio = correct / (double)numSamples;
    return ratio;
}

double DecisionTree::test(const string fileName, const int numSamples){
    // Local variables
    string dataRead = "";
    bool *data[MAX_ARRAY_SIZE];
    int labels[MAX_ARRAY_SIZE];
    double result = 0;

    for (int i = 0; i < MAX_ARRAY_SIZE; i++){
        data[i] = new bool[MAX_ARRAY_SIZE];
    }

    // Read the file
    readFile(fileName, dataRead);

    // Parse dataRead string into data and labels
    parseDataRead(dataRead, numFeatures, data, labels);

    result = test((const bool**)data, labels, numSamples);

    // distruct the data
    for (int i = 0; i < MAX_ARRAY_SIZE; i++){
        delete [] data[i];
    }
    return result;
}

void DecisionTree::print(){
    printTree(root, 0);
}

// ******** Private Functions ********

void DecisionTree::printTree(DecisionTreeNode *root, int level){
    
    // Base case : node is null
    if (!root)
        return;

    // Print the tabs
    for (int i = 0; i < level; i++)
        cout << "\t";

    // print self
    // If leaf print class
    if (root->leaf){
        cout << "class = " << root->theClass << endl;
        return;
    } else
        cout << root->featureId << endl;
    
    // print left
    printTree(root->left, level+1);

    // print right
    printTree(root->right, level+1);
}

// Finds the id with the highest information gain
int DecisionTree::findFeatureIDToSplit(const bool** data, const int* labels, const int numSamples,
                                        const int numFeatures, bool* usedSamples, bool* usedFeatures){
    // Local variables
    bool allSamplesUsed = true;
    bool allFeaturesUsed = true;
    int firstUnusedFeature = 0;
    double highestIGsoFar[2];
    double highestIG[2];

    // initialize variables
    for (int i = 0; i < numSamples; i++)
        allSamplesUsed = allSamplesUsed && usedSamples[i];
    for (int i = 0; i < numFeatures; i++){
        allFeaturesUsed = allFeaturesUsed && usedFeatures[i];
        if (!usedFeatures[i]){
            firstUnusedFeature = i;
            break;
        }
    }

    highestIGsoFar[0] = firstUnusedFeature;
    highestIGsoFar[1] = calculateInformationGain(data, labels, numSamples, numFeatures,
                                                 usedSamples, firstUnusedFeature);
    highestIG[0] = firstUnusedFeature;
    highestIG[1] = highestIGsoFar[1];

    // Base cases
    if (allSamplesUsed)
        return -1;
    if (allFeaturesUsed)
        return -2;

    // Find root (the feature with highest entropy)
    for (int i  = 0; i < numFeatures; i++){
        if (!usedFeatures[i]){  // if this feature was not used before
            highestIGsoFar[0] = i;
            highestIGsoFar[1] = calculateInformationGain(data, labels, numSamples,
                                                         numFeatures, usedSamples, i);
            // If a feature with a higher IG is found update highestIG
            if (highestIGsoFar[1] > highestIG[1] ){
                highestIG[1] = highestIGsoFar[1];   // the feature IG
                highestIG[0] = highestIGsoFar[0];   // The featureID
            }
        }
    }

    // Mark the feature found as used
    usedFeatures[(int)highestIG[0]] = 1;

    // return the index of feature with highest IG
    return highestIG[0];
}

// Builds the decision tree recursively
void DecisionTree::buildDecisionTree(const bool** data, const int* labels, const int numSamples,
                                     const int numFeatures, bool* usedSamples, bool* usedFeatures, 
                                     DecisionTreeNode* root, int *classes, int numClasses){
    // Local variables
    // Variables used to pass information to left and right subtrees
    bool usedSamplesToLeft[MAX_ARRAY_SIZE];
    bool usedSamplesToRight[MAX_ARRAY_SIZE];
    bool usedFeatureToLeft[MAX_ARRAY_SIZE];
    bool usedFeatureToRight[MAX_ARRAY_SIZE];
    int numSamplesToL = 0;
    int numSamplesToR = 0;
    int featureId = 0;
    // Variables used to find information for leaf node
    int theClassSoFar[2][MAX_ARRAY_SIZE];
    double theClass[2];
    double numOfSamplesUsed = 0;

    // Initialize variables
    for (int i = 0; i < 2; i++){
        for ( int j = 0; j < numClasses; j++){
            theClassSoFar[0][j] = classes[j];    // the class
            theClassSoFar[1][j] = 0;             // the repetition
            theClass[i] = 0;
        }
    }

    // Base case - Leaf Node -
    if (isLeaf(usedFeatures, usedSamples, numSamples, numFeatures, labels) | root->leaf /*| featureId < 0*/){
        // find the class
        for (int i = 0; i < numSamples; i++){
            // if sample still exist
            if (!usedSamples[i]){
                numOfSamplesUsed++;

                // find number of repetition for each class
                for (int k = 0; k < numClasses; k++){
                    if (theClassSoFar[0][k] == labels[i])
                        theClassSoFar[1][k] ++;
                }
            }
        }

        // find the class with the highest repetition
        for (int i = 0; i < numClasses; i++){
            if (theClassSoFar[1][i] > theClass[1]){
                theClass[1] = theClassSoFar[1][i];
                theClass[0] = theClassSoFar[0][i];
            }
        }

        // fill the leaf information
        root->theClass = theClass[0];
        root->certainty = theClass[1]/numOfSamplesUsed*100;
        root->leaf = true;
        root->left = NULL;
        root->right = NULL;

        return;
    }

    // - NOT A LEAF -
    // Initialize children features arrays
    for (int i = 0; i < numFeatures; i++){
        usedFeatureToLeft[i] = usedFeatures[i];
        usedFeatureToRight[i] = usedFeatures[i];
    }

    // update used samples to pass it to left
    // 0 for left
    for (int i = 0; i < numSamples; i++){
        // Initialize it
        usedSamplesToLeft[i] = usedSamples[i];
        // Update it if sample is usable
        if (!usedSamples[i]){
            // if data at featureId'th feature and i'th sample = 1 mark it unusable
            if (data[i][root->featureId]){
                usedSamplesToLeft[i] = 1;
            } else {
                // counts the number of samples going left
                numSamplesToL++;
            }
        }
    }

    // If there are samples going left
    if (numSamplesToL > 0){
        // find the next feature
        featureId = findFeatureIDToSplit(data, labels, numSamples, numFeatures, usedSamplesToLeft, usedFeatureToLeft);
        root->left = new DecisionTreeNode();
        root->left->featureId = featureId;

        // mark it as leaf if featureId < 0
        // featureId = -1 all samples used
        // featureId = -2 all features used
        if (featureId < 0)
            root->left->leaf = true;

        // pass it to left
        buildDecisionTree(data, labels, numSamples, numFeatures, 
                          usedSamplesToLeft, usedFeatureToLeft, root->left, classes, numClasses);
    } else 
        root->left = NULL;


    // update used samples to pass it to right
    for (int i = 0; i < numSamples; i++){
        // Initialize it
        usedSamplesToRight[i] = usedSamples[i];
        // Update it if sample is usable
        if (!usedSamples[i]){
            // if data at featureId'th feature and i'th sample = 0 mark it unusable
            if (!data[i][root->featureId]){
                usedSamplesToRight[i] = 1;
            } else {
                // counts the number of samples going left
                numSamplesToR++;
            }
        }
    }

    // if there are samples going right
    if (numSamplesToR > 0){
        // find the next feature
        featureId = findFeatureIDToSplit(data, labels, numSamples, numFeatures, usedSamplesToRight, usedFeatureToRight);
        root->right = new DecisionTreeNode();
        root->right->featureId = featureId;

        // mark it as leaf if featureId < 0
        // featureId = -1 all samples used
        // featureId = -2 all features used
        if (featureId < 0)
            root->right->leaf = true;

        // pass it to right
        buildDecisionTree(data, labels, numSamples, numFeatures, 
                          usedSamplesToRight, usedFeatureToRight, root->right, classes, numClasses);
    } else
        root->right = NULL;
}

bool DecisionTree::isLeaf(bool *usedFeatures, bool *usedSamples, int numSamples, int numFeatures, const int *labels){
    // Local variables
    int firstLabel = 0;
    bool allSameLabel = true;

    // All usable samples of same label
    for (int i = 0, k = 0; i < numSamples; i++){
        if (!usedSamples[i]){
            if (k == 0){
                k = 1;
                firstLabel = labels[i];
            } else {
                allSameLabel = allSameLabel && (firstLabel == labels[i]);
            }
        }
    }

    return allSameLabel;
}