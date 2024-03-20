#include<iostream>

using namespace std;

/*
    write a program to read a date and,
    make a funcs to increase date as follows
    
    xDays
    oneWeek
    xWeeks
    oneMonth
    xMonths
    oneYear
    xYears
    xYearsFaster
    oneDecade
    xDecades
    xDecadesFaster
    oneCentury
    oneMillennium
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

stDate increaseDateByXDays(stDate date, short days){

    for(short i = 1; i <= days; i++){

        date = increaseDateByOneDay(date);
    }
    return date;
}

stDate increaseDateByOneWeek(stDate date){

        date = increaseDateByXDays(date, 7);

    return date;
}

stDate increaseDateByXWeeks(stDate date, short weeks){

    for(short i = 1; i <= weeks; i++){

        date = increaseDateByXDays(date, 7);
    }

    return date;
}

stDate increaseDateByOneMonth(stDate date){
        if(isLastMonthInYear(date.month)){
            date.month = 1;
            date.year++;
        }else 
            date.month++;

        short numberOfDaysInCurrentMonth = numberOfDaysInAMonth(date.month, date.year);
        if(date.day > numberOfDaysInCurrentMonth)
            date.day = numberOfDaysInCurrentMonth;

    return date;
}

stDate increaseDateByXMonths(stDate date, short months){

    for(short i = 1; i <= months; i++)
        date = increaseDateByOneMonth(date);

    return date;
}

stDate increaseDateByOneYear(stDate date){
    
    date.year++;

    return date;
}

stDate increaseDateByXYears(stDate date, short years){

    date.year += years;

    return date;
}

stDate increaseDateByOneDecade(stDate date){
    
    date.year += 10;

    return date;
}

stDate increaseDateByXDecades(stDate date, short decades){

    date.year += decades * 10;

    return date;
}

stDate increaseDateByOneCentury(stDate date){
    
    date.year += 100;

    return date;
}

stDate increaseDateByOneMillenium(stDate date){
    
    date.year += 1000;

    return date;
}



int main(){


    stDate date = readFullDate();
    cout << "\n\n";
    cout << "Date After\n\n";
    

    date = increaseDateByOneDay(date);
    cout << "01- Adding one day is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByXDays(date, 10);
    cout << "02- Adding 10 day is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByOneWeek(date);
    cout << "03- Adding one week is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByXWeeks(date, 10);
    cout << "04- Adding 10 weeks is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByOneMonth(date);
    cout << "05- Adding one month is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByXMonths(date, 5);
    cout << "06- Adding 5 months is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByOneYear(date);
    cout << "07- Adding one year is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByXYears(date, 10);
    cout << "08- Adding 10 years is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByOneDay(date);
    cout << "09- Adding one decade is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByXDecades(date, 10);
    cout << "010- Adding 10 decades is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByOneCentury(date);
    cout << "011- Adding one century is : " << date.day << "/" << date.month << "/" << date.year << endl;
    date = increaseDateByOneMillenium(date);
    cout << "012- Adding one millenium is : " << date.day << "/" << date.month << "/" << date.year << endl;

    
    
    
    
    
    return 0;
}