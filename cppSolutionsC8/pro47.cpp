#include<iostream>

using namespace std;

/*
    write a progeram to read a date and make funcs
    as follow:

    isEndOfWeek
    isWeekend
    isBusinessDay
    daysUntilTheEndOfWeek
    daysUntilTheEndOfMonth
    daysUntilTheEndOfYear

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

short dayOfWeekOrder(stDate date){
    
    short a, y, m;
    a = (14 - date.month) / 12;
    y = date.year - a;
    m = date.month + (12 * a) - 2;

    return (date.day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
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

short numberOfDaysFromTheBeginingOfTheYear(stDate date){

    short sum = 0;

    for(short i = 1; i < date.month; i++){
        
        sum += numberOfDaysInAMonth(i, date.year);
    }
    sum += date.day;

    return sum;
}

stDate getSystemDate(){

    stDate date;

    time_t t = time(0);
    tm* now = localtime(&t);

    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;

    return date;
}

bool isEndOfWeek(stDate date){
    return (dayOfWeekOrder(date) == 6);
}

bool isWeekend(stDate date){
    short dayIndex = dayOfWeekOrder(date);
    return (dayIndex == 6 || dayIndex == 5);
}

bool isBusinessDay(stDate date){
    return !isWeekend(date);
}

short daysUntilTheEndOfWeek(stDate date){
    return (6 - dayOfWeekOrder(date));
}

short daysUntilTheEndOfMonth(stDate date){
    return (numberOfDaysInAMonth(date.month, date.year) - date.day);
}

short daysUntilTheEndOfYear(stDate date){
    return (isLeapYear ? (366 - numberOfDaysFromTheBeginingOfTheYear(date)) : (365 - numberOfDaysFromTheBeginingOfTheYear(date)));
}


int main(){


    stDate todayDate = readFullDate();
    // stDate todayDate = getSystemDate();

    
    cout << "Today is " << dayShortName(dayOfWeekOrder(todayDate));
    cout << ", " << todayDate.day << "/" << todayDate.month << "/" << todayDate.year;
    cout << "\n\n";

    cout << "is it End of week?\n";
    if(isEndOfWeek(todayDate))
        cout << "Yes it is end of week\n\n";
    else 
        cout << "NO it is NOT end of week\n\n";

    cout << "is it weekend ?\n";
    if(isWeekend(todayDate))
        cout << "Yes it is weekend\n\n";
    else 
        cout << "NO it is NOT weekend\n\n";

    cout << "is it business day ?\n";
    if(isBusinessDay(todayDate))
        cout << "Yes it is business day\n\n";
    else 
        cout << "NO it is NOT business day\n\n";
    

    cout << "\nDays until the end of the week ";
    cout << daysUntilTheEndOfWeek(todayDate);

    cout << "\nDays until the end of the Month ";
    cout << daysUntilTheEndOfMonth(todayDate);
    
    cout << "\nDays until the end of the Year ";
    cout << daysUntilTheEndOfYear(todayDate);
    
    
    return 0;
}