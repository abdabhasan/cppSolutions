#include<iostream>

using namespace std;

/*
    write a program to read a date, and print the day name of week;
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

short readDay(){

    short num;
    
    cout << "Enter a day to check" << endl;
    cin >> num;

    return num;
}

short dayOfWeekOrder(short day, short month, short year){
    
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string dayShortName(short day){

    string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return days[day];
}

int main(){

    short year = readYear();
    short month = readMonth();
    short day = readDay();

    short dayOrder =  dayOfWeekOrder(day, month, year);

    cout << "Date      : " << day << "/" << month << "/" << year << endl;
    cout << "Day Order : " << dayOrder << endl;
    cout << "Day Name  : " << dayShortName(dayOrder);

    return 0;
}