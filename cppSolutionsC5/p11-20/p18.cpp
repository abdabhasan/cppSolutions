#include <iostream>

using namespace std;


string readText(){
    string text = "";

    cout << "Plese enter a Text..." << endl;
    getline(cin, text);

    return text;
}

string encryptText (string text, short encryptionKey){

    for(int i = 0; i <= text.length(); i++){
        text[i] = char((int) text[i] + encryptionKey);
    }

    return text;
}

string decryptText (string text, short encryptionKey){

     for(int i = 0; i <= text.length(); i++){
        text[i] = char((int) text[i] - encryptionKey);
    }

    return text;

}



int main(){

    const short encryptionKey = 2;

    string text = readText();
    string textAfterEncryption = encryptText(text, encryptionKey);
    string textAfterDecryption = decryptText(textAfterEncryption, encryptionKey);

    cout << "\n Text Before encryption : " << text << endl;
    cout << "\n Text after encryption : " << textAfterEncryption << endl;
    cout << "\n Text after decryption : " << textAfterDecryption << endl;


    return 0;
}