#include <iostream>

using namespace std;

// wrtie a program to read how many keys to generate and fill, 
// them in array then print them on the screen;

enum enCharType {smallLetter = 1, capitalLetter = 2, specialChar = 3, digit = 4};

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

void printArray(string arr[100], short arrLength){
    for(int i = 0; i < arrLength; i++)
        cout << arr[i] << endl;

    cout << "\n";
}

char getRandomCharacter(enCharType charType){

    switch (charType){
    case enCharType::smallLetter:
        return char(randomNumber(97, 123));
    case enCharType::capitalLetter:
        return char(randomNumber(65, 90));
    case enCharType::specialChar:
        return char(randomNumber(33, 47));
    case enCharType::digit:
        return char(randomNumber(48, 57));
    default:
        return char(randomNumber(48, 57));
    }

}

string generateWord(enCharType charType, short length){
    
    string word;

    for(int i = 0; i < length; i++){
        word = word + getRandomCharacter(charType);
    }
    return word;
}

string generateKey(){
    
    string key = "";

    key = key + generateWord(enCharType::capitalLetter, 4) + "-"; 
    key = key + generateWord(enCharType::capitalLetter, 4) + "-"; 
    key = key + generateWord(enCharType::capitalLetter, 4) + "-"; 
    key = key + generateWord(enCharType::capitalLetter, 4);

    return key; 
}

void generaetKeysArray(string arr[100] ,short numberOfKeys){

    for(int i = 0; i < numberOfKeys; i++){
        arr[i] = generateKey();
    }
}

int main(){

    srand((unsigned)time(NULL));

    string arr[100];
    short arrLength = readPositiveNumber("Please enter keys number...");
    
    generaetKeysArray(arr, arrLength);
    printArray(arr, arrLength);

    return 0;
}