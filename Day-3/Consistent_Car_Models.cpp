// Problem Statement
// Imagine you have a list of allowed car components (e.g., engine, wheels) given as a string with each component as a character. You are also given a collection of car models given as an array of strings with components of the ith car denoted as characters of the ith string.

// A car model is consistent if all its components exist in the allowed list.

// Your task is to count how many car models in the collection meet this criterion, ensuring they are built from allowed components

// Input Format
// In the first line, a string "components" denoting the allowed components is given to you. 

// In the second line, an integer "n" denoting the number of car models is given to you. 

// In the third line, the elements of the array "models" denoting the components of the n car models is given to you.

// Output Format
// Count of consistent cars is displayed to you. 

// Constraints
// 1 <= n <= 104
// 1 <= components.length<=26
// 1 <= models[i].length <= 100
// The characters in the components are distinct.
// Sample Testcase 0
// Testcase Input
// emta
// 6
// etmb e et eam mtb akm
// Testcase Output
// 3
// Explanation
// The car models that are consistent are: e, et, eam

// Sample Testcase 1
// Testcase Input
// tam
// 5
// maaat mttt mmaaa maka mbta
// Testcase Output
// 3
// Explanation
// The car models that are consistent are: "maaat", "mttt", "mmaaa" because it contains only the components that are allowed.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int countConsistentCars(const string& components, int n, const vector<string>& models) {
    // User logic goes here

    unordered_set<char> st;
    int cnt=0;
    for(char ch : components){
        st.insert(ch);
    }
    for(string x : models){
        bool valid=true;

        for(char ch : x){
            if(st.find(ch)==st.end()){
                valid=false;
                break;
            }
        }
        if(valid) cnt++;
    }

    return cnt;
    // Placeholder return value
}

int main() {
    string components;
    int n;
    vector<string> models;

    getline(cin, components);
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string model;
        cin >> model;
        models.push_back(model);
    }

    int result = countConsistentCars(components, n, models);
    cout << result << endl;

    return 0;
}