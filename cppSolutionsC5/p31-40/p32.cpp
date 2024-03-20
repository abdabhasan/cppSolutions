#include <iostream>

using namespace std;

// wrtie a program to fill array with random numbers from 1 to 100, 
// then copy it to another array in reverse order and print it;

int readPositiveNumber(string message){

    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
}

int randomNumber(int from, int to){

    int randNum = rand() % (to - from + 1) + from;
    return randNum;

}

void fillArrayWithRandomNumbers(int arr[100], short arrLength){

    for(int i = 0; i < arrLength; i++)
        arr[i] = randomNumber(1, 99);
}

void printArray(int arr[100], short arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

void reversArray(int firstArray[100], int reversedArray[100], short arrLength){

    for(int i = arrLength - 1, j = 0; i >= 0 ; i--, j++){
        reversedArray[j] = firstArray[i];
    }

}

int main(){

    srand((unsigned)time(NULL));

    int arr[100], reversedArray[100];
    short arrLength = readPositiveNumber("Please enter arrays length...");
    
    fillArrayWithRandomNumbers(arr, arrLength);
    cout << "The first Array..." << endl;
    printArray(arr, arrLength);

    reversArray(arr, reversedArray, arrLength);
    cout << "The reversed Array..." << endl;
    printArray(reversedArray, arrLength);

    return 0;
}