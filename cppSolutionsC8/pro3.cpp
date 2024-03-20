#include<iostream>

using namespace std;

/*
    write a program to check if year is a leap year or NOT;
    NOTE : all years which are perfectly divisible by 4 are leap
    except for century years (years ends with 00), which are leap
    years only if they are perfectly divisible by 400;

    ! solve isLeapYear with ONE line of code;  
*/

short readYear(){

    short num;
    
    cout << "Enter a Year" << endl;
    cin >> num;

    return num;
}

bool isLeapYear(short year){

    return ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
}

int main(){

    short year = readYear();

    if(isLeapYear(year))
        cout << "YES it is leap\n";
    else
        cout << "NO it is NOT leap\n";

    return 0;
}