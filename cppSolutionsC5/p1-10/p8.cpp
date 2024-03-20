#include <iostream>

using namespace std;

// write a program to read a digit and a number, then print digit frequence in that number

int readPositiveNumber(string message){
    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
}

int digitFrequenceInNumber(short digit, int number){

    int remainder = 0, digitFrequence = 0;

    while(number > 0){
        remainder = number % 10;
        number = number / 10;

        if(remainder == digit)
            digitFrequence++;
    }
    return digitFrequence;
}

void printDigitFrequenceInNumber(short digit, int digitFreq){

    cout << digit << " Frequence is " << digitFreq << endl;
}

/* // ! start of Abu-Hadhoud's code
int CountDigitFrequency(short DigitToCheck, int Number){ 
    
    int FreqCount = 0, Remainder = 0;
    
    while (Number > 0){         
        Remainder = Number % 10;
        Number = Number / 10;
        if (DigitToCheck == Remainder){
            FreqCount++;
        } 
    } 
    return FreqCount; 
}
*/ // ! end of Abu-Hadhoud's code



int main(){

    int number = readPositiveNumber("please enter a number...");
    short digit = readPositiveNumber("please enter the digit you want...");

    printDigitFrequenceInNumber(digit, digitFrequenceInNumber(digit, number));

/* // ! start of Abu-Hadhoud's code
        int Number = ReadPositiveNumber("Please enter the main number?");
        short DigitToCheck = ReadPositiveNumber("Please enter one digit to check?");
        
        cout << "\nDigit " << DigitToCheck << " Frequency is "
             << CountDigitFrequency(DigitToCheck, Number) << " Time(s).\n";
*/ // ! end of Abu-Hadhoud's code



    return 0;
}