#include <iostream>

using namespace std;

// wrtie a program to fill array with max size 100 with numbers 
// then check if it is Palindrome array or not;

int readPositiveNumber(string message){

    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number < 0);

    return number;
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

void readArrayElements(int arr[100], int& arrLength ){
    
    arrLength = 0;
    bool more;

    do{

        addArrayEelement(readPositiveNumber("Plese enter a number..."), arr, arrLength);
        more = readPositiveNumber("Do you wanna add more numbers? [0]:NO, [1]:YES ?");

    } while(more);
}

bool isPalindromeArray(int arr[100], int arrLength){

    // for(int i = 0, j = arrLength - 1; i < arrLength; i++, j--){
        
    //     if(arr[i] != arr[j])
    //         return false;
    // } // ! mine end

    for(int i = 0; i < arrLength; i++){
        if (arr[i] != arr[arrLength - i - 1])
            return false;
    }
    return true;
}



int main(){

    srand((unsigned)time(NULL));

    int arr[100], arrLength = 0;

    readArrayElements(arr, arrLength);

    
    if(isPalindromeArray(arr, arrLength))
        cout << "\nYes it is a palindrome array" << endl;
    else 
        cout << "\nNO it is NOT a palindrome array" << endl;

    return 0;
}