#include<iostream>

using namespace std;

/*
    write a program to print number of : days
    in a certain month;

    ! with two lines of code
*/

short readYear(){

    short num;
    
    cout << "Enter a Year to check" << endl;
    cin >> num;

    return num;
}

short readMonth(){

    short num;
    
    cout << "Enter a Month to check" << endl;
    cin >> num;

    return num;
}

bool isLeapYear(short year){

    return ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
}

short numberOfDaysInMonth(short month, short year){

    if(month < 1 || month > 12)
        return 0;
    
    int numberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];
}

int main(){

    short year = readYear();
    short month = readMonth();

    cout << "\n\nNumber of Days in Month [" << month << "] is "
         << numberOfDaysInMonth(month, year);

    return 0;
}