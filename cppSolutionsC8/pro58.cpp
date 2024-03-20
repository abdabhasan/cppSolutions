#include<iostream>

using namespace std;

/*
    write a progeram to read two periods
    and check if they overlap or NOT;
*/
enum enDateCompare {dateBefore = -1, dateEqual = 0, dateAfter = 1};

struct stDate{
    
    short year;
    short month;
    short day;
};

struct stPeriod{

    stDate dateFrom;
    stDate dateTo;
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
    period.dateFrom= readFullDate();

    cout << "\nEnter End date : \n\n"; 
    period.dateTo= readFullDate();

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

bool isPeriodsOverlap(stPeriod period1, stPeriod period2){

    if(
        compareDates(period2.dateTo, period1.dateFrom) == enDateCompare::dateBefore
        ||
        compareDates(period2.dateFrom, period1.dateFrom) == enDateCompare::dateAfter
    )
        return false;
    else 
        return true;

}

int main(){


    cout << "Enter period1 : \n";
    stPeriod period1 = readPeriod();
    cout << "Enter period2 : \n";
    stPeriod period2 = readPeriod();

    if(isPeriodsOverlap(period1, period2))
        cout << "Yes, periods Overlap\n";
    else
        cout << "NO, periods NOT Overlap\n";

    return 0;
}