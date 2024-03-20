#include <iostream>

using namespace std;

// wrtie a program to print 3 random numbers from 1 to 10;

int randomNumber(int from, int to){

    int randNum = rand() % (to - from + 1) + from;
    return randNum;

}


int main(){

    srand((unsigned)time(NULL));

    cout << randomNumber(1, 10) << endl;
    cout << randomNumber(1, 10) << endl;
    cout << randomNumber(1, 10) << endl;


    return 0;
}