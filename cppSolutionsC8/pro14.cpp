#include<iostream>

using namespace std;

/*
    write a program to read date1, date2 and 
    check if date1 Equals date2;
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

bool isDate1EqualsDate2(stDate date1, stDate date2){

    return ((date1.day == date2.day) && (date1.month == date2.month) && (date1.year == date2.year));
}

int main(){


    stDate date1 = readFullDate();
    cout << "\n\n";
    stDate date2 = readFullDate();
    cout << "\n\n";


    if(isDate1EqualsDate2(date1, date2))
        cout << "yes Date1 is Equals to date2";
    else
        cout << "NO Date1 is NOT Equal to date2";

    

    return 0;
}