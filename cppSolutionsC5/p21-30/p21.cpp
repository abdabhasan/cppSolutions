#include <iostream>

using namespace std;

// wrtie a program to read how many keys to generate
// and print them on the screen

/* // ! start of my code
int readPositiveNumber(string message){
    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0);

    return number;
    
}

string generateKeys(){

    int from = 65, to = 90, hiphen = 45, randNum = 0;
    string key = "";
   
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            randNum = rand() % (to - from + 1) + from;
            key = key + char(randNum);
        }
    
        if(i < 3)
            key = key + char(hiphen);
    }

    return key;
}

void printKeys(int number){
 
    for(int i =0; i < number; i++){
        cout << "Key [ " << i << " ] : "; 
        cout << generateKeys() << endl;
    }

}
*/ // ! end of my code

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

void generaetKeys(short numberOfKeys){

    for(int i = 0; i < numberOfKeys; i++){

        cout << "Key [" << i + 1<< "] : ";
        cout << generateKey() << endl;
    }
}

int main(){

    srand((unsigned)time(NULL));

/* // ! start of my code
    printKeys(readPositiveNumber("Please enter the number of keys..."));
*/ // ! end of my code

    generaetKeys(readPositiveNumber("plese eneter number of keys..."));


    return 0;
}