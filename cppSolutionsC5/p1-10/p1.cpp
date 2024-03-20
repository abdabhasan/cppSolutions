/*
    write a program prints multiplication table from 1 to 10 as the image;
*/

#include <iostream>

using namespace std;

// ! my code is true but I'll add columnSperator function



void printMultiplicationTableHeader(){
    cout << "\t\t\t Multiplication Table From 1 to 10" << endl; 
    cout << "\t";
    for (int i = 1; i <= 10; i++){
        cout << i << "\t";
    }
    cout << "\n--------------------------------------------";
    cout << "--------------------------------------------------" << endl;
    
}

// ! here
string columnSperator(int i){
    if(i < 10)
        return "   |";
    else
        return "  |";
}

void printMultiplicationTable(){

    printMultiplicationTableHeader();
    
    for(int i = 1; i <= 10; i++){
        cout << " " <<  i << columnSperator(i);

        for(int j = 1; j <= 10; j++){
            cout << "\t" << j * i;
        }
        cout << endl;
    }


}



int main(){
    
    printMultiplicationTable();
 
    return 0;
}