#include <iostream>

using namespace std;

// write a program to read a number and print the sum of its digits

float readPositiveNumber(string message){
    float number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

void printSumOfDigits(int number){
    
    int remainder = 0;
    int sum = 0;

    while(number > 0){
        remainder = number % 10;
        sum += remainder;
        number = number / 10;
    }
    cout << endl << sum << endl;
}


int main(){


    printSumOfDigits(readPositiveNumber("please enter a number..."));

    return 0;
}