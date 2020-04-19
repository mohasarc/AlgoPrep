#include "./Header_Files/Tree23.h"
#include <iostream>

struct Int{
    Int(int aval){
        value = aval;
    }

    int val(){
        return value;
    }

    int value;
};

int main(){
    Tree23<int>* tree = new Tree23<int>();

    tree->insert(5);
    tree->traverse();
    return 0;
}