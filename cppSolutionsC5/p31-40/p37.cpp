#include <iostream>

using namespace std;

// wrtie a program to fill array with max size 100 with random numbers 
// from 1 to 100, copy it to another array using addArrayElement, and print it;


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

void addArrayEelement(int number, int arr[100], short& arrLength){

    arrLength++;
    arr[arrLength - 1] = number;
}

void copyArray(int arr[100],int arr2[100] , short arrLength, short& arr2Length){

    for (int i = 0; i < arrLength; i++){
        addArrayEelement(arr[i], arr2, arr2Length);
    }
}


int main(){

    srand((unsigned)time(NULL));

    int arr[100], arr2[100];
    int arrLength = readPositiveNumber("Please enter array length...");
    short arr2Length = 0;

    fillArrayWithRandomNumbers(arr, arrLength);

    cout << "The first array = ";
    printArray(arr, arrLength);
    
    cout << "\nThe second array = ";
    copyArray(arr, arr2, arrLength, arr2Length);
    printArray(arr2, arrLength);


    return 0;
}