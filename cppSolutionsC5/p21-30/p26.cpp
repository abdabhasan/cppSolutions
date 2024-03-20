#include <iostream>

using namespace std;

// wrtie a program to fill array with max size 100 with random numbers 
// from 1 to 100, then print sum of all numbers;


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

int sumOfArrayElements(int arr[100], int arrLength){

    int sum = 0;

    for(int i = 0; i < arrLength; i++){
            sum += arr[i];
    }
    return sum;        
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

    cout << sumOfArrayElements(arr, arrLength);

    return 0;
}