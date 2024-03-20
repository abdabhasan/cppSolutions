#include<iostream>

using namespace std;

/*
    write a program to print number of : days, hours, minutes, seconds
    in a certain month;
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
    
    if(month == 2)
        return isLeapYear(year) ? 29 : 28;

    short arr31Days[] = {1, 3, 5, 7, 8, 10, 12};

    for(short i = 1; i <= 7; i++){

        if(arr31Days[i - 1] == month)
            return 31;
    }
    return 30;
}

short numberOfHoursInMonth(short month, short year){
    return numberOfDaysInMonth(month, year) * 24;
}

int numberOfMinutesInMonth(short month, short year){
    return numberOfHoursInMonth(month, year) * 60;
}

int numberOfSecondsInMonth(short month, short year){
    return numberOfMinutesInMonth(month, year) * 60;
}


int main(){

    short year = readYear();
    short month = readMonth();

    cout << "\n\nNumber of Days in Month [" << month << "] is "
         << numberOfDaysInMonth(month, year);
    cout << "\nNumber of hours in Month [" << month << "] is "
         << numberOfHoursInMonth(month, year); 
    cout << "\nNumber of minutes in Month [" << month << "] is " 
         << numberOfMinutesInMonth(month, year);
    cout << "\nNumber of seconds in Month [" << month << "] is " 
         << numberOfSecondsInMonth(month, year);

    return 0;
}