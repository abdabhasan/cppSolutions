#include <iostream>

using namespace std;

float readNumber(){
    
    float number;

    cout << "please enter a number..." << endl;
    cin >> number;

    return number;
}

float getFractionPart(float number){
    return number - int(number);
}

int myCeil(float number){
    int intPart;
    intPart = int(number);


        if(number > 0)
            return ++intPart;
        else
            return intPart;
}


int main(){

    cout << myCeil(readNumber());

    return 0;
}