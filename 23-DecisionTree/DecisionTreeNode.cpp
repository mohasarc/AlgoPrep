/**
* Author: Mohammed S. Yaseen
* ID: 21801331
* Section: 3
* Assignment: 2
**/

#include "DecisionTreeNode.h"

// Default constructor
DecisionTreeNode::DecisionTreeNode(){
    featureId = -1;
    theClass = -1;
    certainty = -1;
    leaf = false;
    left = NULL;
    right = NULL;
}