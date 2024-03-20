#include <iostream>

using namespace std;

// write a program to read a number, then print all digit frequency in that number

int readPositiveNumber(string message){
    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
}

int digitFrequenceyInNumber(short digit, int number){

    int remainder = 0, digitFrequence = 0;

    while(number > 0){
        remainder = number % 10;
        number = number / 10;

        if(remainder == digit)
            digitFrequence++;
    }
    return digitFrequence;
}

void printAllDigitsFrequencey(int number){

    cout << endl;
    for(int i = 0; i < 10; i++){
        short digitFreq = 0;
        digitFreq = digitFrequenceyInNumber(i, number);

        if(digitFreq > 0){
            cout << "Digit " << i << " Frequencey is " << digitFreq << endl;
        }

    }
}

int main(){

    int number = readPositiveNumber("please enter a number...");

    printAllDigitsFrequencey(number);
 

    return 0;
}