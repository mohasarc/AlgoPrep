#include "./Header_Files/Tree23.h"
#include <iostream>
#include <string>
#include <sstream>

struct Int{
    int value;
};

string toStr(int num){
    string returnstr;
    stringstream ss;
    ss << num;
    ss >> returnstr;
    return returnstr;
}

int mulByNum(int item, int num, int other){
    return item * num + other;
}

string addStars(string item, string star, int &num){
    string number = "";
    number = " " + toStr(num) + " ";
    num++;
    return star + number + item + star;
}

int main(){
    Tree23<int>* tree = new Tree23<int>();
    Tree23<string>* strTree = new Tree23<string>();


    tree->insert(5);
    tree->insert(10);
    tree->insert(5);
    tree->insert(2);
    tree->insert(3);
    tree->insert(7);
    tree->insert(1);
    tree->traverse();
    cout << endl;
    tree->updateEntries(mulByNum, 5, 3);
    tree->traverse();

    strTree->insert("Hello");
    strTree->insert("There");
    strTree->insert("I");
    strTree->insert("am");
    strTree->insert("a HERO :)");
    strTree->traverse();
    cout << endl;
    int num = 5;
    strTree->updateEntries(addStars, " * ", num);
    strTree->traverse();
    return 0;
}