#include<iostream>

using namespace std;

/*
    write a program to read date and 
    check if its the last day in month
    if its the last month in the year;
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

stDate getDateFromDaysOrderInYear(short daysOrderInYear, short year){

    stDate date;
    date.month = 1;
    date.year = year;

    short monthDays = 0;
    short remainingDays = daysOrderInYear;

    while(true){

        monthDays = numberOfDaysInAMonth(date.month, year);

        if(remainingDays > monthDays){
            
            remainingDays -= monthDays;
            date.month++;
        
        }else {
            date.day = remainingDays;
            break;
        }
    }

    return date;
}

stDate readFullDate(){

    stDate date;

    date.day = readDay();
    date.month = readMonth();
    date.year = readYear();

    return date;
}

bool isLastDayInMonth(stDate date){

    return (date.day == numberOfDaysInAMonth(date.month, date.year));
}

bool isLastMonthInYear(short month){

    return (month == 12);
}


int main(){


    stDate date1 = readFullDate();
    cout << "\n\n";

    if(isLastDayInMonth(date1))
        cout << "yes it is the last day in the month";
    else
        cout << "NO it is NOT the last day in the month";

    if(isLastMonthInYear(date1.month))
        cout << "\nyes it is the last month in the year";
    else
        cout << "\nNO it is NOT the last month in the year";
    

    return 0;
}