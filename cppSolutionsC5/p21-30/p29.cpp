#include <iostream>
#include <cmath>

using namespace std;

// wrtie a program to fill array with max size 100 with random numbers 
// from 1 to 100, copy prime numbers to another array and print it

enum enPrimeNotPrime{ prime = 1, notPrime = 2};

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

void fillArrayWithRandomNumbers(int arr[100], int& arrLength){

    for(int i = 0; i < arrLength; i++)
        arr[i] = randomNumber(1, 99);
}
 
void printArray(int arr[100], int arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

enPrimeNotPrime checkPrime(int number){

int m = round(number / 2);

    for(int counter = 2; counter <= m; counter++){
        if(number % counter == 0)
            return enPrimeNotPrime::notPrime;
    }
    return enPrimeNotPrime::prime;
}

void copyPrimeNumberToArray(int arr[100],int arr2[100] , short arrLength, short& arr2Length){

    short counter = 0;
    
    for (int i = 0; i < arrLength; i++){
        checkPrime(arr[i]);
        if(checkPrime(arr[i]) == enPrimeNotPrime::prime){
            arr2[counter] = arr[i];
            counter++;
        }
    }
    arr2Length = --counter;
}


int main(){

    srand((unsigned)time(NULL));

    int arr[100], arr2[100];
    short arr2Length = 0;
    int arrLength = readPositiveNumber("Please enter array length...");
    
    fillArrayWithRandomNumbers(arr, arrLength);
    printArray(arr, arrLength);

    copyPrimeNumberToArray(arr, arr2, arrLength,arr2Length);
    printArray(arr2, arr2Length);
    


    return 0;
}