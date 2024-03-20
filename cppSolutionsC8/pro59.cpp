#include<iostream>

using namespace std;

/*
    write a progeram to read a period
    and clac period length in days;
*/

struct stDate{
    
    short year;
    short month;
    short day;
};

struct stPeriod{

    stDate startDate;
    stDate endDate;
};

short readYear(){

    short num;
    
    cout << "Please Enter a Year? ";
    cin >> num;

    return num;
}

short readMonth(){

    short num;
    
    cout << "Please Enter a Month? ";
    cin >> num;

    return num;
}

short readDay(){

    short num;
    
    cout << "Please Enter a Day? ";
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

stPeriod readPeriod(){

    stPeriod period;

    cout << "\nEnter Start date : \n\n"; 
    period.startDate= readFullDate();

    cout << "\nEnter End date : \n\n"; 
    period.endDate= readFullDate();

    return period;
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

bool isDate1BeforeDate2(stDate date1, stDate date2){

    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

bool isDate1EqualsDate2(stDate date1, stDate date2){

    return ((date1.day == date2.day) && (date1.month == date2.month) && (date1.year == date2.year));
}

bool isDate1AfterDate2(stDate date1, stDate date2){

    return (!isDate1BeforeDate2(date1, date2) && !isDate1EqualsDate2(date1, date2));
}

short diffrenceInDaysBetweenTwoDates(stDate date1, stDate date2, bool includeEndDay = false){

    short days = 0;
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

short calculatePeriodLengthInDays(stPeriod period, bool includeEndDay = false){

    return diffrenceInDaysBetweenTwoDates(period.startDate, period.endDate);
}

int main(){


    cout << "Enter period1 : \n";
    stPeriod period1 = readPeriod();

    cout << "Period length is : ";
    cout << calculatePeriodLengthInDays(period1);

    return 0;
}