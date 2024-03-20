#include <iostream>

using namespace std;

int readNumber(){
    
    int number;

    cout << "please enter a number..." << endl;
    cin >> number;

    return number;
}
 
int mySqrt(int number){

    return pow(number, .5);

}


int main(){

    cout << mySqrt(readNumber());

    return 0;
}