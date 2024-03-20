#include<iostream>

using namespace std;

/*
    write a program to read a date and,
    make a funcs to decrease date as follows
    
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

bool isDate1BeforeDate2(stDate date1, stDate date2){

    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}

stDate decreaseDateByOneDay(stDate date){

    if(date.day == 1){
        if(date.month == 1){
            date.year--;
            date.month = 12;
            date.day = 31;

        }else {
            date.month--;
            date.day = numberOfDaysInAMonth(date.month, date.year);
        }
    }else
        date.day--;

    return date;
}

stDate decreaseDateByXDays(stDate date, short days){

    for(short i = 1; i <= days; i++){

        date = decreaseDateByOneDay(date);
    }
    return date;
}

stDate decreaseDateByOneWeek(stDate date){

    for(short i = 1; i <= 7; i++){

        date = decreaseDateByOneDay(date);
    }

    return date;
}

stDate decreaseDateByXWeeks(stDate date, short weeks){

    for(short i = 1; i <= weeks; i++){

        date = decreaseDateByXDays(date, 7);
    }

    return date;
}

stDate decreaseDateByOneMonth(stDate date){
        if(date.month == 1){
            date.month = 12;
            date.year--;
        }else 
            date.month--;

        short numberOfDaysInCurrentMonth = numberOfDaysInAMonth(date.month, date.year);
        if(date.day > numberOfDaysInCurrentMonth)
            date.day = numberOfDaysInCurrentMonth;

    return date;
}

stDate decreaseDateByXMonths(stDate date, short months){

    for(short i = 1; i <= months; i++)
        date = decreaseDateByOneMonth(date);

    return date;
}

stDate decreaseDateByOneYear(stDate date){
    
    date.year--;

    return date;
}

stDate decreaseDateByXYears(stDate date, short years){

    date.year -= years;

    return date;
}

stDate decreaseDateByOneDecade(stDate date){
    
    date.year -= 10;

    return date;
}

stDate decreaseDateByXDecades(stDate date, short decades){

    date.year -= decades * 10;

    return date;
}

stDate decreaseDateByOneCentury(stDate date){
    
    date.year -= 100;

    return date;
}

stDate decreaseDateByOneMillenium(stDate date){
    
    date.year -= 1000;

    return date;
}



int main(){


    stDate date = readFullDate();
    cout << "\n\n";
    cout << "Date After\n\n";
    
    date = decreaseDateByOneDay(date);
    cout << "01- subtracting one day is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByXDays(date, 10);
    cout << "02- subtracting 10 day is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByOneWeek(date);
    cout << "03- subtracting one week is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByXWeeks(date, 10);
    cout << "04- subtracting 10 weeks is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByOneMonth(date);
    cout << "05- subtracting one month is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByXMonths(date, 5);
    cout << "06- subtracting 5 months is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByOneYear(date);
    cout << "07- subtracting one year is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByXYears(date, 10);
    cout << "08- subtracting 10 years is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByOneDecade(date);
    cout << "09- subtracting one decade is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByXDecades(date, 10);
    cout << "10- subtracting 10 decades is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByOneCentury(date);
    cout << "11- subtracting one century is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    date = decreaseDateByOneMillenium(date);
    cout << "12- subtracting one millenium is : " << date.day << "/" << date.month << "/" << date.year << endl;
    
    
    return 0;
}