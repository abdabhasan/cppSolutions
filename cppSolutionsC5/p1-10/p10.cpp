#include <iostream>

using namespace std;

// write a program to read a number and print it in order from left;

int readPositiveNumber(string message){
    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

void printNumberInOrder(int number){
    
    int remainder = 0;

    if(number > 0){
        remainder = number % 10;
        number = number / 10;
        printNumberInOrder(number);
    }
    if(remainder != 0)
        cout << remainder << endl;
}

int main(){

    printNumberInOrder(readPositiveNumber("please enter a positive number..."));

    return 0;
}