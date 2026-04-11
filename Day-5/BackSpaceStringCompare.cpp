// Problem Statement
// Alice challenged Bob to write the same word as his on a typewriter. Both are kids and are making some mistakes in typing and are making use of the ‘#’ key on a typewriter to delete the last character printed on it.

// An empty text remains empty even after backspaces. 

// Input Format
// The first line contains a string typed by Bob.

// The second line contains a string typed by Alice.

// Output Format
// The first line contains ‘YES’ if Alice is able to print the exact words as Bob , otherwise ‘NO’.

// Constraints
// 1 <= Bob.length

// Alice.length <= 100000

// Bob and Alice only contain lowercase letters and '#' characters.

// Sample Testcase 0
// Testcase Input
// ab#c
// ad#c
// Testcase Output
// YES
// Explanation
// Here ,
// The actual typed string by Bob : ‘ac’
// The actual typed string by Alice : ‘ac’
// Hence , they matched.
// Sample Testcase 1
// Testcase Input
// a#c
// b
// Testcase Output
// NO
// Explanation
// Here ,
// The actual typed string by Bob : ‘c’
// The actual typed string by Alice : ‘b’
// Hence , they do not matched.


#include <iostream>
#include <string>
using namespace std;
string process(string x){
    string temp="";

    for(char ch : x){
        if(ch=='#'){
            if(!temp.empty()){
                temp.pop_back();
            }
        }
        else{
            temp.push_back(ch);
        }
    }

    return temp;
}
bool userLogic(string bob, string alice) {
    // user logic goes here
    string x=process(bob);
    string y=process(alice);

    return x==y; // or false
}

int main() {
    string bob, alice;
    getline(cin, bob);
    getline(cin, alice);
    bool result = userLogic(bob, alice);
    cout << (result ? "YES" : "NO") << endl;
    return 0;
}