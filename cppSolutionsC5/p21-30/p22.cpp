#include <iostream>

using namespace std;

// wrtie a program to read N elements and store them in array
// then print all array elements and ask for a number to check, 
// then print how many number a certain elements repeated in that array;

int readPositiveNumber(string message){



    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
}

void readArray(int arr[100], int& arrLength){

    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    cout << "\nEnter array elements:\n";
    for(int i = 0; i < arrLength; i++){
        cout << "Element [" << i + 1 << "] :";
        cin >> arr[i];
    }
    cout << endl;
}

void printArray(int arr[100], int arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

int timesRepeated(int number, int arr[100], int arrLength){
    int count = 0;
    for(int i = 0; i <= arrLength - 1; i++){
        if(number == arr[i])
            count++;
    }
    return count;
}


int main(){

    int arr[100], arrLength, numberToCheck;

    readArray(arr, arrLength);
 
    numberToCheck = readPositiveNumber("Enter the number you wanna check...");

    cout << "\nOriginal array: ";
    printArray(arr, arrLength);

    cout << "\nNumber " << numberToCheck;
    cout << " is repeated ";
    cout << timesRepeated(numberToCheck, arr, arrLength) << " time(s)\n";

    return 0;
}