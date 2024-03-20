#include <iostream>

using namespace std;

// write a program to read a number and print inverted pattern;
// 1
// 22
// 333

int readPositiveNumber(string message){
    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

void printInvertedPatternOfNumber(int number){

    for(int i = 0; i <= number; i++){
        for(int j = 0; j < i; j++){
            cout << i;
        }
        cout << endl;
    }


}

int main(){

    printInvertedPatternOfNumber(readPositiveNumber("please enter a number..."));   
    
    return 0;
}