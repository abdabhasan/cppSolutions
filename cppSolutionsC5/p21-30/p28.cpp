#include <iostream>

using namespace std;

// wrtie a program to fill array with max size 100 with random numbers 
// from 1 to 100, copy it to another array and print it


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
        arr[i] = randomNumber(1, 100);
}
 
void printArray(int arr[100], int arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

void copyArray(int arr[100],int arr2[100] , short arrLength){

    for (int i = 0; i < arrLength; i++){
        arr2[i] = arr[i];
    }
}


int main(){

    srand((unsigned)time(NULL));

    int arr[100], arr2[100];
    int arrLength = readPositiveNumber("Please enter array length...");
    
    fillArrayWithRandomNumbers(arr, arrLength);

    printArray(arr, arrLength);
    
    copyArray(arr, arr2, arrLength);
    printArray(arr2, arrLength);


    return 0;
}