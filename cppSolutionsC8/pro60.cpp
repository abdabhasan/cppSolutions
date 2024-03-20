#include<iostream>

using namespace std;

/*
    write a progeram to read a period
    and a Date, then check if this date 
    within this period or NOT;
*/

enum enDateCompare {dateBefore = -1, dateEqual = 0, dateAfter = 1};

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

stPeriod readPeriod(){

    stPeriod period;

    cout << "\nEnter Start date : \n\n"; 
    period.startDate= readFullDate();

    cout << "\nEnter End date : \n\n"; 
    period.endDate= readFullDate();

    return period;
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

enDateCompare compareDates(stDate date1, stDate date2){

    if(isDate1EqualsDate2(date1, date2))
        return enDateCompare::dateEqual;
    if(isDate1BeforeDate2(date1, date2))
        return enDateCompare::dateBefore;
        
    
    return enDateCompare::dateAfter;
}

bool isDateInPeriod(stPeriod period, stDate date){

    // if(
    //     compareDates(period.startDate, date) == enDateCompare::dateBefore
    //     &&
    //     compareDates(period.endDate, date) == enDateCompare::dateAfter
    // )
    //     return true;
    // else 
    //     return false;

    return !(
        compareDates(period.startDate, date) == enDateCompare::dateBefore 
        || 
        compareDates(period.endDate, date) == enDateCompare::dateAfter 
            );
}

int main(){


    cout << "Enter period1 : \n";
    stPeriod period1 = readPeriod();
    cout << "Enter a date to check : \n";
    stDate date = readFullDate();


    if(isDateInPeriod(period1, date))
        cout << "Yes, Date within Period\n";
    else
        cout << "NO, Date NOT within  Period\n";

    return 0;
}