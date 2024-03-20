#include <iostream>

using namespace std;

// write a program to read a number and print letter pattern;
// 3
// A
// BB
// CCC

int readPositiveNumber(string message){
    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

void printPatternOfLetters(int number){

    for(int i = 64; i < 65 + number ; i++){
        for(int j = 64; j < i; j++){
            cout << char(i);
        }
        cout << endl;
    }

}

int main(){

    printPatternOfLetters(readPositiveNumber("please enter a number..."));   
    
    return 0;
}