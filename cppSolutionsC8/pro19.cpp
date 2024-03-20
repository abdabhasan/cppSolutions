#include<iostream>

using namespace std;

/*
    write a program to read a date1, date2, and
    make a function to calculate the diffs in daysj

    NOTE : if date2 is less than date1 print the 
    retults in minus; 
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

void swapDates(stDate& date1, stDate& date2){

    stDate tempDate;

    tempDate.year = date1.year;
    tempDate.month = date1.month;
    tempDate.day = date1.day;

    date1.year = date2.year;
    date1.month = date2.month;
    date1.day = date2.day;

    date2.year = tempDate.year;
    date2.month = tempDate.month;
    date2.day = tempDate.day;
}

int diffrenceInDaysBetweenTwoDates(stDate date1, stDate date2, bool includeEndDay = false){

    int days = 0;
    short swapFlagValue = 1;

    if(!isDate1BeforeDate2(date1, date2)){
        
        swapDates(date1, date2);
        swapFlagValue = -1;
    }

    while(isDate1BeforeDate2(date1, date2)){

        days++;
        date1 = increaseDateByOneDay(date1);
    }
        
    return includeEndDay ? ++days * swapFlagValue : days * swapFlagValue;
}

int main(){


    stDate date1 = readFullDate();
    cout << "\n\n";
    stDate date2 = readFullDate();
    cout << "\n\n";

    cout << "Diffrences is : " << diffrenceInDaysBetweenTwoDates(date1, date2);
    

    return 0;
}