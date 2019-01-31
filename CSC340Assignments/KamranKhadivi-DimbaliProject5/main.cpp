//
//  main.cpp
//  PJ5
//
//  Created by Kamran Khadivi-Dimbali on 7/31/17.
//

#include <iostream>
#include <string>
using namespace std;

int digitSum( int input){
    if( input < 9)
        return input;
    else
        return input % 10 + digitSum(input/10);
    
}

bool isPalindrome(const string &s){
    if(s.length()==1)
        return true;
    if(s.length() == 2)
        return s[0] == s[1];
    return (s[0] == s[s.length()-1]) && isPalindrome(s.substr(1,s.length()-2));
    
}

int waysToClimb( int stairs){
    if(stairs <= 1)
        return stairs;
    else
        return waysToClimb(stairs-1) + waysToClimb(stairs-2);
    
}


int main() {
 
    /********** sum digit *************/
    int input;
    cout << "Enter a number and I will add the digits: " << endl;
    cin >> input;
    cout << "The sum of the digits are: " << digitSum(input) << endl << endl;
    
    
    /*********** ways to climb *********/
    int num_Stairs;
    cout << "Enter a number of stairs and I will tell you how many ways you can climb them: " << endl;
    cin >> num_Stairs;
    cout << "There are " << waysToClimb(num_Stairs + 1) << " ways to climb " << num_Stairs << " stairs" << endl;
    
    /*********** Palindrome ***********/
    string s;
    cout << "\nEnter a string and I will tell you if it is a palindrome: " << endl;
    cin >> s;
    
    if(isPalindrome(s)){
        cout << s << " is a palindrome!" << endl;
    }
    else
        cout << s << " is not a palindrome!" << endl;
    
    
    
    
    return 0;
}
