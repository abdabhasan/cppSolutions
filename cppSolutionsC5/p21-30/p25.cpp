#include <iostream>

using namespace std;

// wrtie a program to fill array with max size 100 with random numbers 
// from 1 to 100, then print MIn

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

int findMinNumberInArray(int arr[100], int arrLength){

    int min = 120;

    for(int i = 0; i < arrLength; i++){
        if(arr[i] < min)
            min = arr[i];
    }
    return min;        
}

void printArray(int arr[100], int arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}


int main(){

    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = readPositiveNumber("Please enter array length...");
    
    fillArrayWithRandomNumbers(arr, arrLength);

    printArray(arr, arrLength);

    cout << findMinNumberInArray(arr, arrLength);

    return 0;
}