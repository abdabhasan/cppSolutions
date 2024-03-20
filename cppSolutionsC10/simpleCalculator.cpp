#include<iostream>

using namespace std;

class clsCalculator{

    float _lastNumber;
    float _result = 0;
    float _previousResult = 0;
    string _lastOperation = "Clear";

public:

    void add(float number){
        _lastNumber = number;
        _previousResult = _result;
        _lastOperation = "Adding";
        _result += number;
    }
    void subtract(float number){
        _lastNumber = number;
        _previousResult = _result;
        _lastOperation = "Subtracting";
        _result -= number;
    }
    void multiply(float number){
        _lastNumber = number;
        _previousResult = _result;
        _lastOperation = "Multiplying";
        _result *= number;
    }
    void divide(float number){
        _previousResult = _result;
        _lastNumber = number;
        
        if(number == 0)
            number = 1;

        _previousResult = _result;
        _lastOperation = "Dividing";
        _result /= number;
    }

    void printResult(){

        cout << "Result after " << _lastOperation << " "<< _lastNumber << " is " << _result << endl;
    }
    void clear(){
        _lastOperation = "Clear";
        _result = 0;
        _lastNumber = 0;
    }
    void cancelLastOperation(){
        _lastNumber = 0;
        _lastOperation = "Cancelling last operation";
        _result = _previousResult;
    }
};

int main(){


    clsCalculator calculator;

    calculator.add(10);
    calculator.printResult();

    calculator.subtract(20);
    calculator.printResult();

    calculator.divide(0);
    calculator.printResult();

    calculator.clear();
    calculator.printResult();

    return 0;
}