#include <iostream>

using namespace std;

// write a program to read a number and print it in a reversed order;

int readPositiveNumber(string message){
    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

int reverseNumber(int number){
    
    int remainder = 0, number2 = 0;

    while(number > 0){
        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
    }
    return number2;
}

int main(){

    cout << reverseNumber(readPositiveNumber("please enter a positive number...")) << "\n";

    return 0;
}