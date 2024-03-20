#include <iostream>

using namespace std;

// write a program to guss a 3-letter password(all capital)


string readPassword(string message){
    string password = "";

        cout << message << endl;
        cin >> password;

    return password;
}

string gussPassword(string password){

    double counter = 0;
    string gussPass = "";

    for(int i = 65; i <= 90 ; i++){
        for(int j = 65; j <= 90; j++){
            for(int k = 65; k <= 90; k++){
                counter++;
                gussPass = gussPass + char(i);
                gussPass = gussPass + char(j);
                gussPass = gussPass + char(k);

                if(gussPass == password){
                    return ("password is " + gussPass + " \n found after " + to_string(counter) + " trail.\n");
                }
                gussPass = "";
            }
        }
    }
    return "Not found";
}


int main(){

    cout << gussPassword(readPassword("please enter a passwrod...\n"));   
    
    return 0;
}