#include<iostream>
#include<iomanip>

using namespace std;

/*
    write a program to print month calendar;
*/

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

string monthShortName(short month){

    string months[12] = {"Jan","Feb","Mar","Apr","May","Jun",
    "Jul","Aug","Sep","Oct","Nov", "Dec"};
    return months[month - 1];
}

short dayOfWeekOrder(short day, short month, short year){
    
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string dayShortName(short day){

    string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return days[day];
}

bool isLeapYear(short year){

    return ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0));
}

short numberOfDaysInMonth(short month, short year){

    if(month < 1 || month > 12)
        return 0;
    
    int numberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDays[month - 1];
}

void printMonthCalendar(short month, short year){

    short numberOfDays;
    short current = dayOfWeekOrder(1, month, year);
    numberOfDays = numberOfDaysInMonth(month, year);

    printf("\n _____________%s________________\n\n",
    monthShortName(month).c_str());

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for(i = 0; i < current; i++)
        printf("     ");
    
    for(int j = 1; j <= numberOfDays; j++){

        printf("%5d", j);

        if(++i == 7){
            i = 0;
            printf("\n");
        }
    }
   printf("\n  _______________________________\n"); 
}

int main(){

    short year = readYear();
    short month = readMonth();
    
    printMonthCalendar(month, year);

    
    return 0;
}