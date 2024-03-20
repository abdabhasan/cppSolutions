#include<iostream>

using namespace std;

/*
    write a program to print total days
    from the begining of year;
*/

short readYear(){

    short num;
    
    cout << "Please Enter a Year" << endl;
    cin >> num;

    return num;
}

short readMonth(){

    short num;
    
    cout << "Please Enter a Month" << endl;
    cin >> num;

    return num;
}

short readDay(){

    short num;
    
    cout << "Please Enter a Day" << endl;
    cin >> num;

    return num;
}

bool isLeapYear(short year){

    return ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
}

short numberOfDaysInAMonth(short month, short year){

    if(month < 1 || month > 12)
        return 0;
    
    int numberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];
}

short numberOfDaysFromTheBeginingOfTheYear(short day, short month, short year){

    short sum = 0;

    for(short i = 1; i < month; i++){
        
        sum += numberOfDaysInAMonth(i, year);
    }
    sum += day;

    return sum;
}

int main(){

    short day = readDay();
    short month = readMonth();
    short year = readYear();
    
    cout << "Number of days from the beginning of the yaer is "
         << numberOfDaysFromTheBeginingOfTheYear(day, month, year);

    return 0;
}