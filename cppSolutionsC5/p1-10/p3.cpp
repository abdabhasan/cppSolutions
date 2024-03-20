#include <iostream>
#include <cmath>

using namespace std;

// write a program to check if the number is Perfect or Not?
// ---> Note: Perfect Number = Sum(all divisors); 
// ! there is a diffs between our codes 


float readPositiveNumber(string message){
    float number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

bool isPerfectNumber(int number){

    // int maxDivide = number / 2;
    int sum = 0;

    for(int counter = 1; counter <= number; counter++){
        if(number % counter == 0){
            sum += counter;
        }
    }

    return sum == number;
}

void printResults(int number){

    if(isPerfectNumber(number))
        cout << number << " is Perfect" << endl;
    else
        cout << number << " is not Perfect" << endl;
}

int main(){

    printResults(readPositiveNumber("please enter a positive numbe..."));


    return 0;
}