#include <iostream>

using namespace std;

// write a program to read a number and check if it is palindrome?

int readPositiveNumber(string message){
    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

int reverseNumber(int number){
    
    int remainder = 0, number2 = 0;

    while(number > 0){
        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
    }
    return number2;
}

bool checkPalindromeNumber(int number){
            return number == reverseNumber(number);
}

void printIsPalindromeNumber(bool isPalindrome){
    if(isPalindrome)
        cout << "The number is Palindrome..." << endl;
    else
        cout << "The number is NOT Palindrome..." << endl;
}


int main(){

    printIsPalindromeNumber(checkPalindromeNumber(readPositiveNumber("please enter a positive number...")));

    return 0;
}