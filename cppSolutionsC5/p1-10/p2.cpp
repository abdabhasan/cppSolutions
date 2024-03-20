#include <iostream>
#include <cmath>

using namespace std;

// write a program to print all prime numbers from 1 to N;
// ! my code is the same of Abu-Hadhoud
// ---> but he named printPrimeNumbers as printPrimeNumbersFrom1ToN <---
// and he added some couts


enum enPrimeNotPrime{ prime = 1, notPrime = 2};

float readPositiveNumber(string message){
    float number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
}

enPrimeNotPrime checkPrime(int number){

int m = round(number / 2);

    for(int counter = 2; counter <= m; counter++){
        if(number % counter == 0)
            return enPrimeNotPrime::notPrime;
    }
    return enPrimeNotPrime::prime;
}

void printPrimeNumbersFrom1ToN(int number){

    for(int i = 1; i <= number; i++){

        if(checkPrime(i) == enPrimeNotPrime::prime)
            cout << i << endl;
    }
}

int main(){

    printPrimeNumbersFrom1ToN(readPositiveNumber("please enter a positive numbe..."));


    return 0;
}