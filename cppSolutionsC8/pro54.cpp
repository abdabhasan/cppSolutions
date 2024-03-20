#include<iostream>

using namespace std;

/*
    write a progeram to read a Vacation period 
    dateFrom and DateTo and make a func
    to calc the actual vacation days;

    NOTE : weekends are excluded;
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

string dayShortName(short day){

    string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return days[day];
}

short dayOfWeekOrder(short day, short month, short year){
    
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

short dayOfWeekOrder(stDate date){
    
    return  dayOfWeekOrder(date.day, date.month, date.year);
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

bool isDate1BeforeDate2(stDate date1, stDate date2){

    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
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

bool isWeekend(stDate date){
    short dayIndex = dayOfWeekOrder(date);
    return (dayIndex == 6 || dayIndex == 5);
}

bool isBusinessDay(stDate date){
    return !isWeekend(date);
}

short calculateVacationDays(stDate dateFrom, stDate dateTo){

    short days = 0;
    while(isDate1BeforeDate2(dateFrom, dateTo)){

        if(isBusinessDay(dateFrom))
            days++;

        dateFrom = increaseDateByOneDay(dateFrom);
    }
    return days;
}


int main(){


    cout << "Vacation starts : \n";
    stDate date1 = readFullDate();
    cout << "\n\nVacation ends : \n\n";
    stDate date2 = readFullDate();
    
    cout << "Vacation From : " << dayShortName(dayOfWeekOrder(date1))
         << ", " << date1.day << "/" << date1.month << "/" << date1.year << endl;
    cout << "Vacation To : " << dayShortName(dayOfWeekOrder(date2))
         << ", " << date2.day << "/" << date2.month << "/" << date2.year << endl;

    cout << "Actual Vacation days :  " << calculateVacationDays(date1, date2);




    return 0;
}