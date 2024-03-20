#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

/* 
    write a program to : 
    - read date string.
    - convert it to date structure.
    - print Day, month, year separately.
    - then convert date structure to string and print it.

    NOTE : write the following funcs : 
    - stringToDate
    - dateToString
*/

struct stDate{
    
    short year;
    short month;
    short day;
};

string readStringDate(string message){

    string s;
    
    cout << message;
    getline(cin >> ws, s);

    return s;
}

vector <string> splitString(string s1, string delim){

    short pos = 0;
    string sWord; 
    vector <string> vWords;

    // use find() func to get the position of the delimiters.
    while((pos = s1.find(delim)) != std::string::npos){
        
        sWord = s1.substr(0, pos); // store the word.
        if(sWord != "")
            vWords.push_back(sWord);
            

        s1.erase(0, pos + delim.length()); // erase() until postion and move to next word.
    }

    if(s1 != "")
        vWords.push_back(s1); // add the last word in the string;

    return vWords;
}

stDate stringToDate(string dateString){

    stDate date;
    vector<string> vDate;

    vDate = splitString(dateString, "/");
    date.day = stoi(vDate[0]);
    date.month = stoi(vDate[1]);
    date.year = stoi(vDate[2]);

    return date;    
}

string dateToString(stDate date){
    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

int main(){

    string dateString = readStringDate("Please Enter Date dd/mm/yyyy? ");

    stDate date = stringToDate(dateString);

    cout << "\nDay:" << date.day << endl;
    cout << "month:" << date.month << endl;
    cout << "year :" << date.year << endl;


    cout << "\nyou entered : " << dateToString(date) << endl;


    return 0;
}