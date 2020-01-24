//PROBLEM: Two strings A and B are isomorphic if there exists character mapping
// which replaces characters from A to get B. Rules for character mapping are:

// all occurrences of one character (e.g. ‘x’) must be replaced with the same character (e.g. ‘y’)
// no two different characters may map to the same character
// a character may map to itself
// Write a function that returns true if provided strings are isomorphic, otherwise false:

// bool AreStringsIsomorphic(char* a, char* b)

// The strings are NULL-terminated, with characters from lower case English alphabet ‘a’ – ‘z’.

// source : https://www.microsoft.com/sr-latn-rs/mdcs/prepare-for-se-test.aspx

#include <map>
#include <string>
#include <iostream>
using namespace std;

bool AreStringsIsomorphic(char* str1, char* str2){
    map<char, char> myMap;
    pair<map<char, char>::iterator, bool> ret;
    map<char, char>::iterator it;
    for(int i = 0; str1[i] != '\n'; i++){
        ret = myMap.insert(pair<char, char>(str1[i], str2[i]));
        if (ret.second == false){ // the process wasn't successfull (key already exists)
            it = myMap.find(str1[i]);
            if (it->second != str2[i])
                return false;
        } 
    }
    return true;
}

int main(){
    char *a, *b, *c, *d, *e, *f;
    a = "noon\n";
    b = "feet\n";
    c = "aab\n"; 
    d = "ccd\n";
    e = "brain\n";
    f = "space\n";

    cout<<AreStringsIsomorphic(a, b)<<endl;
    cout<<AreStringsIsomorphic(c, d)<<endl;
    cout<<AreStringsIsomorphic(e, f)<<endl;
}