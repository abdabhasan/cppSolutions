#include <iostream>

using namespace std;

// wrtie a program to fill 2 arrays with max size 100 with random numbers 
// from 1 to 100, sum their elements in a third array and print the results;


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

void sumOf2Arrays(int arr[100], int arr2[100], int arr3[100], int arrLength){

    for(int i = 0; i < arrLength; i++){
            arr3[i] = arr[i] + arr2[i];
    }
}

void printArray(int arr[100], int arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}


int main(){

    srand((unsigned)time(NULL));

    int arr[100], arr2[100], arr3[100];
    int arrLength = readPositiveNumber("Please enter arrays length...");
    
    fillArrayWithRandomNumbers(arr, arrLength);
    fillArrayWithRandomNumbers(arr2, arrLength);

    cout << "The first Array..." << endl;
    printArray(arr, arrLength);

    cout << "The second Array..." << endl;
    printArray(arr2, arrLength);

    sumOf2Arrays(arr,arr2, arr3, arrLength);

    cout << "Sum of Arrays : " << endl;
    printArray(arr3, arrLength);



    return 0;
}