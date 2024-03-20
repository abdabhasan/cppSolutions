#include <iostream>

using namespace std;

// wrtie a program to fill array with max size 100 with random numbers from 1 to 100, 
// read number and return its index in array if found otherwise retrun -1


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

void fillArrayWithRandomNumbers(int arr[100], int arrLength){

    for(int i = 0; i < arrLength; i++)
        arr[i] = randomNumber(1, 99);
}
/* // ! my code
 void findNumberInArray(int arr[100], int arrLength, short number){

     cout << "Number you are looking for..." << number << endl;

     for(int i = 0; i < arrLength; i++){
         if(number == arr[i]){
             cout << "num position .." <<  i << endl;
             cout << "num order .." <<  i + 1;
             break;
         } 
         if(i == arrLength - 1){
             cout << "NOT FOUND";
         } 
     }
 }
*/ // ! end of my code


void printArray(int arr[100], short arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

short findNumberPositionInArray(int number, int arr[100], int arrLength){
    for(int i =0; i < arrLength; i++){
        if(arr[i] == number)
            return i;
    }
    return -1;
     
}

int main(){

    srand((unsigned)time(NULL));

    int arr[100];
    short arrLength = readPositiveNumber("Please enter number...");

    fillArrayWithRandomNumbers(arr, arrLength);
    printArray(arr, arrLength);
    
    short number = readPositiveNumber("Please enter number you wanna find...");
    short numberPosition = findNumberPositionInArray(number, arr, arrLength);

    if(numberPosition == -1)
        cout << "The number is NOT found :-(\n";
    else{
        cout << "The number found at postion: " << numberPosition << endl;
        cout << "The number found its order: " << numberPosition + 1 << endl;
    }

    return 0;
}