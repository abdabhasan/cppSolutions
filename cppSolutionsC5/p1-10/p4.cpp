#include <iostream>
#include <cmath>

using namespace std;

// write a program to print all perfect numbers from 1 to N;


float readPositiveNumber(string message){
    float number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

bool isPerfectNumber(int number){

    int maxDivide = round(number / 2);
    int sum = 0;

    for(int counter = 1; counter <= maxDivide; counter++){
        if(number % counter == 0){
            sum += counter;
        }
    }

    return sum == number;
}

void printPerfectNumbersFrom1toN(int number){

    for(int i = 1; i <= number; i++){

        if(isPerfectNumber(i))
            cout << i << " is Perfect" << endl;
    }
}


int main(){

    printPerfectNumbersFrom1toN(readPositiveNumber("please enter a positive number..."));


    return 0;
}