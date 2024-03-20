#include<iostream>

using namespace std;

/*
    write a program to read date and 
    make a function to increse date by one day;
*/

struct stDate{
    
    short year;
    short month;
    short day;
};

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

stDate readFullDate(){

    stDate date;

    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();

    return date;
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

bool isLastDayInMonth(stDate date){

    return (date.day == numberOfDaysInAMonth(date.month, date.year));
}

bool isLastMonthInYear(short month){

    return (month == 12);
}

stDate increaseDateByOneDay(stDate date){

    if(isLastDayInMonth(date)){
        date.day = 1;
        if(isLastMonthInYear(date.month)){
            date.month = 1;
            date.year++;
        }else 
            date.month++;
    }else
        date.day++;

    return date;
}

int main(){


    stDate date1 = readFullDate();
    cout << "\n\n";

    date1 = increaseDateByOneDay(date1);
    cout << "date after adding one day : " << date1.day << "/" << date1.month << "/" << date1.year;
    

    return 0;
}