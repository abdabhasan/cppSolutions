#include <iostream>

using namespace std;

// wrtie a program to fill array with ordered numbers from 1 to N, 
// then print it, after that shuffle this array and print it after shuffle;


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

void fillArrayWithOrderedNumbers(int arr[100], short arrLength){

    for(int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}

void swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp; 
}

void shuffleArray(int arr[100], short arrLength){

    int randNum1, randNum2;

    for(int i = 0; i < arrLength; i++){
        randNum1 = randomNumber(1, arrLength -1 );
        randNum2 = randomNumber(1, arrLength -1 );
        swap(arr[randNum1], arr[randNum2]);
    }
}


void printArray(int arr[100], short arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}


int main(){

    srand((unsigned)time(NULL));

    int arr[100];
    short arrLength = readPositiveNumber("Please enter arrays length...");
    
    fillArrayWithOrderedNumbers(arr, arrLength);
    cout << "The first Array..." << endl;
    printArray(arr, arrLength);

    shuffleArray(arr, arrLength);
    cout << "The shuffled Array..." << endl;
    printArray(arr, arrLength);

    return 0;
}