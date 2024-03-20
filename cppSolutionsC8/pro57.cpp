#include<iostream>

using namespace std;

/*
    write a progeram to read Date1 & Date2,
    and write a func to compare dates, 
    -1 before
     0 equal 
     1 after
*/

enum enDateCompare {dateBefore = -1, dateEqual = 0, dateAfter = 1};

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


int main(){


    cout << "Enter date1 : \n";
    stDate date1 = readFullDate();
    cout << "Enter date2 : \n";
    stDate date2 = readFullDate();


        cout << "Compare result : " << compareDates(date1, date2);;




    return 0;
}