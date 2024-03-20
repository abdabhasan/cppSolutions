#include<iostream>

using namespace std;

/*
    write a program to print number of : days, hours, minutes, seconds
    in a certain year;
*/

short readYear(){

    short num;
    
    cout << "Enter a Year to check" << endl;
    cin >> num;

    return num;
}

bool isLeapYear(short year){

    return ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
}

short numberOfDaysInYear(short year){
    return isLeapYear(year) ? 366 : 365;
}

short numberOfHoursInYear(short year){
    return numberOfDaysInYear(year) * 24;
}

int numberOfMinutesInYear(short year){
    return numberOfHoursInYear(year) * 60;
}

int numberOfSecondsInYear(short year){
    return numberOfMinutesInYear(year) * 60;
}

int main(){

    short year = readYear();

    cout << "\n\nNumber of Days in year [" << year << "] is "
         << numberOfDaysInYear(year);
    cout << "\nNumber of hours in year [" << year << "] is "
         << numberOfHoursInYear(year); 
    cout << "\nNumber of minutes in year [" << year << "] is " 
         << numberOfMinutesInYear(year);
    cout << "\nNumber of seconds in year [" << year << "] is " 
         << numberOfSecondsInYear(year);

    return 0;
}