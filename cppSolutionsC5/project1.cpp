#include <iostream>
#include <stdlib.h>

using namespace std;

/*
    write a small game program for stone-paper-scissor
    Requirements: 
        - ask for how many rounds the game will be.
        - start each round player vs coputer.
        - show the results with each round.
        - if computer wins the round ring a bill, and screed red.
        - if player won the round show green screen.
        - after all rounds show game over the print game results, then ask 
        the user if s/he want to play again;
*/

enum enChoice {stone = 1, paper = 2, scissor = 3};

enChoice checkChoice(int choice){

    switch (choice){
    case 1:
        return enChoice::stone;
    case 2:
        return enChoice::paper;
    case 3:
        return enChoice::scissor;
    }
}

int randomChoice(){

    int randNum = rand() % (3 - 1 + 1) + 1;
    return randNum;

}

int readPlayerChoice(string message){
    int number = 0;
    do{
        cout << message << endl;
        cin >> number;
    }while(number <= 0 || number > 3);

    return number;
}

int readPositiveNumber(string message){
    
    int number = 0;
    
    do{
    
        cout << message << endl;
        cin >> number;
    
    }while(number < 1 || number > 10 );

    return number;
}

bool isPlayerWon(int playerChoice, int computerChoice, int& playerWonTimes){

    if(checkChoice(playerChoice) == enChoice::stone && checkChoice(computerChoice) == enChoice::scissor){
        playerWonTimes++;
        return true;
    }
    
    if(checkChoice(playerChoice) == enChoice::paper && checkChoice(computerChoice) == enChoice::stone){
        playerWonTimes++;
        return true;
    }
    
    if(checkChoice(playerChoice) == enChoice::scissor && checkChoice(computerChoice) == enChoice::paper){
        playerWonTimes++;
        return true;
    }

    return false;
}

bool isComputerWon(int playerChoice, int computerChoice, int& computerWonTimes){
    
    if(checkChoice(playerChoice) == enChoice::stone && checkChoice(computerChoice) == enChoice::paper){
        computerWonTimes++;
        return true;
    }
    
    if(checkChoice(playerChoice) == enChoice::paper && checkChoice(computerChoice) == enChoice::scissor){
        computerWonTimes++;
        return true;
    }
    
    if(checkChoice(playerChoice) == enChoice::scissor && checkChoice(computerChoice) == enChoice::stone){
        computerWonTimes++;
        return true;
    }

    return false;
}

void printChoices(int playerChoice, int computerChoice){
    
    // PLAYER Choices
    if(checkChoice(playerChoice) == enChoice::stone)
        cout << "Player choice    : Stone"  << endl;
    if(checkChoice(playerChoice) == enChoice::paper)
        cout << "Player choice    : Paper"  << endl;
    if(checkChoice(playerChoice) == enChoice::scissor)
        cout << "Player choice    : Scissors"  << endl;
    
    // COMPUTER Choices
    if(checkChoice(computerChoice) == enChoice::stone)
        cout << "Computer choice  : Stone"  << endl;
    if(checkChoice(computerChoice) == enChoice::paper)
        cout << "Computer choice  : Paper"  << endl;
    if(checkChoice(computerChoice) == enChoice::scissor)
        cout << "Computer choice  : Scissors"  << endl;
}

void printNoWinner(int playerChoice, int computerChoice){
        if(checkChoice(playerChoice) == enChoice::stone)
                printChoices(playerChoice, computerChoice);
            
        if(checkChoice(playerChoice) == enChoice::paper)
                printChoices(playerChoice, computerChoice);
            
        if(checkChoice(playerChoice) == enChoice::scissor)
                printChoices(playerChoice, computerChoice);
}

void printRoundWinner(int playerChoice, int computerChoice, int& playerWonTimes, int& computerWonTimes, int& drawTimes){

        // PLAYER
        if(isPlayerWon(playerChoice, computerChoice, playerWonTimes)){
            printChoices(playerChoice, computerChoice);
            cout << "Round winner     : [PLAYER]" << endl;
        }

        // COMPUTER
        else if(isComputerWon(playerChoice, computerChoice, computerWonTimes)){
            printChoices(playerChoice, computerChoice);
            cout << "Round winner     : [COMPUTER]" << endl;
        }

        // NO WINNER
        else{
            
            printNoWinner(playerChoice, computerChoice);
            cout << "Round winner     : [NO WINNER]" << endl;
            drawTimes++;
        }

}

void playRound(int roundCounter, int& playerWonTimes, int& computerWonTimes, int& drawTimes){
    int playerChoice = readPlayerChoice("Your Choice: [1]:Stone, [2]:Paper, [3],Scissors ?");
    int computerChoice = randomChoice();
    
    cout << "____________Round [" << roundCounter << "]____________\n\n";

    printRoundWinner(playerChoice, computerChoice, playerWonTimes, computerWonTimes, drawTimes);
    
    cout << "__________________________________\n" << endl;
}   

char doPlayAgain(char& again){
    
    
    cout << "\t\t Do you want to play again? Y/N? ";
    cin >> again;

    return again;
}

void printGameResults(int rounds, int playerWonTimes, int computerWonTimes, int drawTimes, string finalWinner){

    cout << "\t\t--------------------------------------------\n\n";
    cout << "\t\t\t+++ G a m e O v e r +++\n\n";
    cout << "\t\t--------------------------------------------\n\n";
    cout << "\t\t--------------- [Game Reaults] -------------\n\n";

    cout << "\t\tGame Rounds           : " << rounds - 1 << endl;
    cout << "\t\tPlayer won times      : " << playerWonTimes << endl;
    cout << "\t\tComputer won times    : " << computerWonTimes << endl;
    cout << "\t\tDraw times            : " << drawTimes << endl;
    cout << "\t\tFinal Winner          : " << finalWinner << endl;

    cout << "\n\t\t--------------------------------------------\n\n";
}

void gameRounds(int roundsNumber){

    int roundCounter = 1, playerWonTimes = 0, computerWonTimes = 0, drawTimes = 0;
    string finalWinner = "TEST";

    for( ;roundCounter <= roundsNumber; roundCounter++){
        cout << "Round [" << roundCounter << "] begins: \n\n";
        
        playRound(roundCounter, playerWonTimes, computerWonTimes, drawTimes);
    }
    if(playerWonTimes > computerWonTimes)
        finalWinner = "PLAYER";
    else if (computerWonTimes > playerWonTimes)
        finalWinner = "COMPUTER";
    else if (playerWonTimes == computerWonTimes)
        finalWinner = "NO WINNER";

    printGameResults(roundCounter, playerWonTimes, computerWonTimes, drawTimes, finalWinner);
}

void game(){
    
    char again;

    do{
        gameRounds(readPositiveNumber("How many rounds 1 to 10 ?"));
        doPlayAgain(again);

        if(again == 'Y' || again == 'y')
            system("clear");

    }while(again == 'Y' || again == 'y');
}

int main(){

    srand((unsigned)time(NULL));

    game();


    return 0;
}