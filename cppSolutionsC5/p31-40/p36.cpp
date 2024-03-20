#include <iostream>

using namespace std;

// wrtie a program to dynamically read numbers and save them in an array
// Max size of array is 100, allocate simi-dynamic array length.


int readPositiveNumber(string message){

    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number < 0);

    return number;
}

void printArray(int arr[100], short arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";
}

void addArrayEelement(int number, int arr[100], short& arrLength){

    arrLength++;
    arr[arrLength - 1] = number;
}

void readArrayElements(int arr[100], short& arrLength ){
    
    arrLength = 0;
    bool more;

    do{

        addArrayEelement(readPositiveNumber("Plese enter a number..."), arr, arrLength);
        more = readPositiveNumber("Do you wanna add more numbers? [0]:NO, [1]:YES ?");

    } while(more);
}


int main(){


    int arr[100];
    short arrLength = 0;
    
    readArrayElements(arr, arrLength);

    cout << "Array length = " << arrLength << endl;
    printArray(arr, arrLength);

    return 0;
}