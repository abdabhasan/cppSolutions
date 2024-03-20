#include <iostream>

using namespace std;

// wrtie a program to print 3 random small letter,
// capital letter, special char, and digit int order

enum enCharType {smallLetter = 1, capitalLetter = 2, specialChar = 3, digit = 4};

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


int main(){

    srand((unsigned)time(NULL));

    cout << getRandomCharacter(enCharType::smallLetter) << endl;
    cout << getRandomCharacter(enCharType::capitalLetter) << endl;
    cout << getRandomCharacter(enCharType::specialChar) << endl;
    cout << getRandomCharacter(enCharType::digit) << endl;


    return 0;
}