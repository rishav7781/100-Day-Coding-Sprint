// Above is the standard representation of a chessboard.

// This could be imagined as a 2D cartesian plane, with the x axis being represented by the alphabets and y axis by the numbers.

// Given coordinates in the form of string, print if that cell is white or black.

// Input Format
// First line contains a string s.

// Output Format
// White or Black.

// Constraints
// |s|=2

// Sample Testcase 0
// Testcase Input
// b2
// Testcase Output
// Black
// Explanation
// Self explanatory.
// Sample Testcase 1
// Testcase Input
// a1
// Testcase Output
// Black

#include <iostream>
#include <string>

std::string determineColor(const std::string& s) {
    int col= s[0]-'a' +1;
    int row= s[1]-'0';

    if((row +col)%2 ==0) return "Black";
    else return "White";
    
}

int main() {
    std::string s;
    std::cin >> s;
    std::string result = determineColor(s);
    std::cout << result << std::endl;
    return 0;
}