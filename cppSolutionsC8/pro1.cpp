#include <iostream>

using namespace std;

/*
    write a program to read a number and print the text of that number;
*/

int readNumber(){

    int num;
    
    cout << "Enter a number" << endl;
    cin >> num;

    return num;
}


    if(number == 0)
        return "";
    
    if(number >= 1 && number <= 19){

        string arr[] = {
        "", "one", "two", "three", "four", "five", "six", 
        "seven", "eight", "nine", "ten", "eleven", "twelve",
        "thirteen", "fourteen", "fifteen", "sixteen","seventeen",
        "eighteen", "nineteen"};

        return arr[number] + " ";
    }
    if(number >= 20 && number <= 99){

        string arr[] = {
        "", "", "twenty", "thirty", "forty", "fifty", 
        "sixty", "seventy", "eighty", "ninety"};

        return arr[number / 10] + " " + numberToText(number % 10);
    }
    if(number >= 100 && number <= 199){

        return "One Hundred "+ numberToText(number % 100);
    }
    if (number >= 200 && number <= 999) {
        
        return numberToText(number / 100) + " Hundreds " + numberToText(number % 100);
    }
    if (number >= 1000 && number <= 1999) {
        
        return "One Thousand " + numberToText(number % 1000);
    }
    if (number >= 2000 && number <= 999999) {
        
        return numberToText(number / 1000) + " Thousands " + numberToText(number % 1000);
    }
    if (number >= 1000000 && number <= 1999999) {
        
        return "One Million " + numberToText(number % 1000000);
    }
    if (number >= 2000000 && number <= 999999999) {
        
        return numberToText(number / 1000000) + " Millions " + numberToText(number % 1000000);
    }
    if (number >= 1000000000 && number <= 1999999999) {
        
        return "One Billion " + numberToText(number % 1000000000);
    } else {
        
        return numberToText(number / 1000000000) + " Billions " + numberToText(number % 1000000000);
    }
}


int main(){

    int number = readNumber();

    cout << numberToText(number);

    return 0;
}