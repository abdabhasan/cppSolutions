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

int myFloor(float number){
    int intPart;
    intPart = int(number);


        if(number > 0)
            return intPart;
        else
            return --intPart;
}


int main(){

   cout << myFloor(readNumber());










    return 0;
}