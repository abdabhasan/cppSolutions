#include <iostream>
#include <cmath>


using namespace std;

// wrtie a program to fill array with with numbers, then print distinct
// numbers to another array;

void fillArray(int arr[100], int& arrLength){
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

void printArray(int arr[100], int arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

void addArrayEelement(int number, int arr[100], int& arrLength){

    arrLength++;
    arr[arrLength - 1] = number;
}

int findNumberPositionInArray(int number, int arr[100], int arrLength){
    for(int i =0; i < arrLength; i++){
        if(arr[i] == number)
            return i;
    }
    return -1;
}

bool isNumberFoundInArray(int number, int arr[100], int arrLength){
    return findNumberPositionInArray(number, arr, arrLength) != -1;
}

void copyDistinctNumbersToArray(int arrSourse[100], int arrDestination[100], int sourseLength, int& destinationLength){
    
    for(int i = 0; i < sourseLength; i++){
        if(!isNumberFoundInArray(arrSourse[i], arrDestination, destinationLength)){
            addArrayEelement(arrSourse[i], arrDestination, destinationLength);
        }
    }
}

int main(){

    int arrSource[100], sourceLength = 0, arrDestination[100], destinationLength = 0;
    fillArray(arrSource, sourceLength);

    cout << "\nArray 1 elements:\n";
    printArray(arrSource, sourceLength);

    copyDistinctNumbersToArray(arrSource, arrDestination, sourceLength, destinationLength);

    cout << "\nArray 2 elements:\n";
    printArray(arrDestination, destinationLength);


    return 0;
}