#include <iostream>

using namespace std;

// wrtie a program to print abs of numbers;


int readPositiveNumber(string message){

    int number = 0;
        cout << message << endl;
        cin >> number;

    return number;
}

int myAbs(int number){
    if(number < 0)
        return number * -1;
    return number;
}

int main(){

    int number = readPositiveNumber("enter a number...");
    
    cout << "the number you entered..." << number << endl;

    cout << "My abs..." << myAbs(number) << endl;
    cout << "C++ abs..." << abs(number);

    return 0;
}