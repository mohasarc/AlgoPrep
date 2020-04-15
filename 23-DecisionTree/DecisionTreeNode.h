/**
* Author: Mohammed S. Yaseen
* ID: 21801331
* Section: 3
* Assignment: 2
**/

#ifndef DECISIONTREENODE_H
#define DECISIONTREENODE_H
#include <iostream>

class  DecisionTreeNode
{
public:
    // Constructor
     DecisionTreeNode();

    // Class Properties
    int featureId;
    int theClass;
    double certainty;
    bool leaf;
    DecisionTreeNode *left;
    DecisionTreeNode *right;
};
#endif