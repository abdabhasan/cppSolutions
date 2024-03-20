#include <iostream>

using namespace std;

float getFractionPart(float number){
    return number - int(number);
}

int myRound(float number){
    int intPart;
    intPart = int(number);

    float fractionsPart = getFractionPart(number);

    if(abs(fractionsPart) >= .5){
        if(number > 0)
            return ++intPart;
        else
            return --intPart;
    } else{
        return intPart;
    }
}


int main(){












    return 0;
}