#include <iostream>

using namespace std;

// write a program to read a number and print it in a reversed order;

/* // ! start of my code
int readNumber(string message){
    int number = 0;
    
    cout << message << endl;
    cin >> number;

    return number;
    
}

void printReversedNumber(int number){

    for(int i = 0; number % 10 != 0; i++){
        cout << number % 10 << endl;
        number /= 10;
    }
}
*/ // ! end of my code

float readPositiveNumber(string message){
    float number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

void printDigits(int number){
    
    int remainder = 0;

    while(number > 0){
        remainder = number % 10;
        number = number / 10;
        cout << remainder << endl;
    }
}

int main(){

/* // ! start of my code
    printReversedNumber(readNumber("please enter a number to reverse it..."));
*/ // ! end of my code


    printDigits(readPositiveNumber("please enter a positive number..."));


    return 0;
}