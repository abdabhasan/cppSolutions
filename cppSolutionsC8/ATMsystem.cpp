#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct sClient {
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
    bool markForDelete = false;
};

enum enMainMenueOptions {
    eQuickWithdraw = 1, eNormalWithdraw = 2, eDeposit = 3,
    eCheckBalance = 4, eExit = 5
};

const string clientsFileName = "clients.txt";
sClient currentClient;

void showMainMenue();
void login();
void showQuickWithdrawScreen();
void showNormalWithdrawScreen();
void showDepositScreen();

vector<string> splitString(string s1, string delimiter) {
    vector<string> vString;
    size_t pos = 0;
    string sWord;

    while ((pos = s1.find(delimiter)) != string::npos) {
        sWord = s1.substr(0, pos);
        if (!sWord.empty()) {
            vString.push_back(sWord);
        }
        s1.erase(0, pos + delimiter.length());
    }

    if (!s1.empty()) {
        vString.push_back(s1);
    }

    return vString;
}

sClient convertLineToRecord(string line, string separator = "#//#") {
    sClient client;
    vector<string> vClientData;

    vClientData = splitString(line, separator);

    client.accountNumber = vClientData[0];
    client.pinCode = vClientData[1];
    client.name = vClientData[2];
    client.phone = vClientData[3];
    client.accountBalance = stod(vClientData[4]);

    return client;
}

string convertRecordToLine(sClient client, string separator = "#//#") {
    string stClientRecord = "";
    stClientRecord += client.accountNumber + separator;
    stClientRecord += client.pinCode + separator;
    stClientRecord += client.name + separator;
    stClientRecord += client.phone + separator;
    stClientRecord += to_string(client.accountBalance);

    return stClientRecord;
}

vector<sClient> loadClientsDataFromFile(string fileName) {
    vector<sClient> vClients;

    fstream myFile;
    myFile.open(fileName, ios::in);

    if (myFile.is_open()) {
        string line;
        sClient client;

        while (getline(myFile, line)) {
            client = convertLineToRecord(line);
            vClients.push_back(client);
        }

        myFile.close();
    }

    return vClients;
}

bool findClientByAccountNumberAndPinCode(string accountNumber, string pinCode, sClient& client) {
    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);

    for (sClient c : vClients) {
        if (c.accountNumber == accountNumber && c.pinCode == pinCode) {
            client = c;
            return true;
        }
    }
    return false;
}

vector<sClient> saveClientsDataToFile(string fileName, vector<sClient> vClients) {
    fstream myFile;
    myFile.open(fileName, ios::out);

    string dataLine;

    if (myFile.is_open()) {
        for (sClient c : vClients) {
            if (!c.markForDelete) {
                dataLine = convertRecordToLine(c);
                myFile << dataLine << endl;
            }
        }

        myFile.close();
    }

    return vClients;
}

bool depositBalanceToClientByAccountNumber(string accountNumber, double amount, vector<sClient>& vClients) {
    char answer = 'n';

    cout << "\n\nAre you sure you want to perform this transaction? y/n ? ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y') {
        for (sClient& c : vClients) {
            if (c.accountNumber == accountNumber) {
                c.accountBalance += amount;
                saveClientsDataToFile(clientsFileName, vClients);
                cout << "\n\nDone Successfully. New balance is: " << c.accountBalance;
                return true;
            }
        }
        return false;
    }
}

short readQuickWithdrawOption() {
    short choice = 0;
    while (choice < 1 || choice > 9) {
        cout << "\nChoose what to do from [1] to [9] ? ";
        cin >> choice;
    }
    return choice;
}

short getQuickWithdrawAmount(short quickWithdrawOption) {
    switch (quickWithdrawOption) {
        case 1: return 20;
        case 2: return 50;
        case 3: return 100;
        case 4: return 200;
        case 5: return 400;
        case 6: return 600;
        case 7: return 800;
        case 8: return 1000;
        default: return 0;
    }
}

void performQuickWithdrawOption(short quickWithdrawOption) {
    if (quickWithdrawOption == 9) {
        return;
    }

    short withdrawBalance = getQuickWithdrawAmount(quickWithdrawOption);

    if (withdrawBalance > currentClient.accountBalance) {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "Press Any key to continue...";
        system("pause>0");
        showQuickWithdrawScreen();
        return;
    }

    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    depositBalanceToClientByAccountNumber(currentClient.accountNumber, withdrawBalance * -1, vClients);
    currentClient.accountBalance -= withdrawBalance;
}

double readDepositAmount() {
    double amount;
    cout << "\nEnter a positive Deposit Amount? ";
    cin >> amount;
    while (amount <= 0) {
        cout << "\Enter a positive Deposit Amount? ";
        cin >> amount;
    }
    return amount;
}

void performDepositOption() {
    double depositAmount = readDepositAmount();
    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    depositBalanceToClientByAccountNumber(currentClient.accountNumber, depositAmount, vClients);
    currentClient.accountBalance += depositAmount;
}

void showDepositScreen() {
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tDeposit Screen\n";
    cout << "===========================================\n";
    performDepositOption();
}

void showCheckBalanceScreen() {
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tCheck Balance Screen\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << currentClient.accountBalance << "\n";
}

int readWithdrawAmount() {
    int amount;
    cout << "\nEnter an amount multiple of 5's ? ";
    cin >> amount;
    while (amount % 5 != 0) {
        cout << "\nEnter an amount multiple of 5's ? ";
        cin >> amount;
    }
    return amount;
}

void performNormalWithdrawOption() {
    int withdrawBalance = readWithdrawAmount();
    if (withdrawBalance > currentClient.accountBalance) {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "Press Any key to continue...";
        system("pause>0");
        showNormalWithdrawScreen();
        return;
    }
    vector<sClient> vClients = loadClientsDataFromFile(clientsFileName);
    depositBalanceToClientByAccountNumber(currentClient.accountNumber, withdrawBalance * -1, vClients);
    currentClient.accountBalance -= withdrawBalance;
}

void showNormalWithdrawScreen() {
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tNormal Withdraw Screen\n";
    cout << "===========================================\n";
    performNormalWithdrawOption();
}

void showQuickWithdrawScreen() {
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tQuick Withdraw\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << currentClient.accountBalance;
    performQuickWithdrawOption(readQuickWithdrawOption());
}

void goBackToMainMenue() {
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    showMainMenue();
}

short readMainMenueOption() {
    cout << "Choose what do you want to do? [1 to 5]? ";
    short choice = 0;
    cin >> choice;
    return choice;
}

void performMainMenueOption(enMainMenueOptions mainMenueOption) {
    switch (mainMenueOption) {
        case eQuickWithdraw:
            system("clear");
            showQuickWithdrawScreen();
            goBackToMainMenue();
            break;
        case eNormalWithdraw:
            system("clear");
            showNormalWithdrawScreen();
            goBackToMainMenue();
            break;
        case eDeposit:
            system("clear");
            showDepositScreen();
            goBackToMainMenue();
            break;
        case eCheckBalance:
            system("clear");
            showCheckBalanceScreen();
            goBackToMainMenue();
            break;
        case eExit:
            system("clear");
            login();
            break;
    }
}

void showMainMenue() {
    system("clear");
    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit\n";
    cout << "\t[4] Check Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";
    performMainMenueOption(static_cast<enMainMenueOptions>(readMainMenueOption()));
}

bool loadClientInfo(string accountNumber, string pinCode) {
    if (findClientByAccountNumberAndPinCode(accountNumber, pinCode, currentClient)) {
        return true;
    }
    else {
        return false;
    }
}

void login() {
    bool loginFailed = false;
    string accountNumber, pinCode;
    do {
        system("clear");
        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (loginFailed) {
            cout << "Invalid Account Number/PinCode!\n";
        }

        cout << "Enter Account Number? ";
        cin >> accountNumber;

        cout << "Enter Pin? ";
        cin >> pinCode;
        loginFailed = !loadClientInfo(accountNumber, pinCode);
    } while (loginFailed);

    showMainMenue();
}

int main() {
    login();
    system("pause>0");
    return 0;
}
