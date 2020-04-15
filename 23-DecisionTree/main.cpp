#include "DecisionTree.h"


// sample main
int main (){
    DecisionTree t;
    t.train("train_data.txt", 498, 21);
    t.print();

    cout << "Testing : " << t.test("test_data.txt", 473)*100 << " %" << endl;
    
    return 0;
}