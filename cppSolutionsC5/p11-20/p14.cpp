#include <iostream>

using namespace std;

// write a program to read a number and print inverted letter pattern;
// 3
// CCC
// BB
// A

int readPositiveNumber(string message){
    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

void printInvertedPatternOfLetters(int number){

    for(int i = number + 64; i >= 65; i--){
        for(int j = 64; j < i; j++){
            cout << char(i);
        }
        cout << endl;
    }

}

int main(){

    printInvertedPatternOfLetters(readPositiveNumber("please enter a number..."));   
    
    return 0;
}