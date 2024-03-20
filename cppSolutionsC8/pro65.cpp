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

string replaceWordInString(string s1, string stringToReplace, string stringReplaceTo){

    short pos = s1.find(stringToReplace);

    while(pos != std::string::npos){

        s1 = s1.replace(pos, stringToReplace.length(), stringReplaceTo);
        pos = s1.find(stringToReplace); // find the next
    }
    return s1;
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

string formateDate(stDate date, string dateFormate = "dd/mm/yyyy"){
    
    string formattedDateString = "";

    formattedDateString = replaceWordInString(dateFormate, "dd", to_string(date.day));
    formattedDateString = replaceWordInString(formattedDateString, "mm", to_string(date.month));
    formattedDateString = replaceWordInString(formattedDateString, "yyyy", to_string(date.year));

    return formattedDateString;
}


int main(){

    string dateString = readStringDate("Please Enter Date dd/mm/yyyy? ");

    stDate date = stringToDate(dateString);

cout << "\n" << formateDate(date) << "\n";
cout << "\n" << formateDate(date, "yyyy/dd/mm") << "\n";
cout << "\n" << formateDate(date, "mm/dd/yyyy") << "\n";
cout << "\n" << formateDate(date, "dd-mm-yyyy") << "\n";
cout << "\n" << formateDate(date, "Day:dd, Month:mm, Year:yyyy") << "\n";



    return 0;
}