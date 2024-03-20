#include <iostream>

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

enum enGameChoice {STONE = 1, PAPER = 2, SCISSORS = 3};
enum enWinner {PLAYER = 1, COMPUTER = 2, DRAW = 3};

struct stRoundInfo {

    short roundNumber = 0;
    enGameChoice playerChoice;
    enGameChoice computerChoice;
    enWinner winner;
    string winnerName;

};

struct stGameResults {
    
    short gameRounds = 0;
    short playerWinTimes = 0;
    short computerWinTimes = 0;
    short drawTimes = 0;
    enWinner gameWinner;
    string winnerName = "";
};

int randomNumber(int from, int to){

    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}

enGameChoice readPlayerChoice(){

    short choice = 1;

    do{
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> choice;
    }while(choice < 1 || choice > 3);

    return (enGameChoice)choice;
}

enGameChoice getComputerChoice(){
    
    return (enGameChoice)randomNumber(1, 3); 
}

short readHowManyRounds(){

    short gameRounds = 1;

    do{
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> gameRounds;
    }while(gameRounds < 1 || gameRounds > 10);

    return gameRounds;
}

string winnerName(enWinner winner){

    string arrWinnerName[3] = {"PLAYER", "COMPUTER", "NO WINNER"};
    return arrWinnerName[winner - 1];
}

string choiceName(enGameChoice choice){
    
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors"};

    return arrGameChoices[choice - 1];
}

enWinner whoWonTheRound(stRoundInfo roundInfo){

    if(roundInfo.playerChoice == roundInfo.computerChoice)
        return enWinner::DRAW;
    
    switch (roundInfo.playerChoice){

        case enGameChoice::STONE:
            if(roundInfo.computerChoice == enGameChoice::PAPER)
                return enWinner::COMPUTER;

            break;

        case enGameChoice::PAPER:
            if(roundInfo.computerChoice == enGameChoice::SCISSORS)
                return enWinner::COMPUTER;

            break;

        case enGameChoice::SCISSORS:
            if(roundInfo.computerChoice == enGameChoice::STONE)
                return enWinner::COMPUTER;
            
            break;
    }

    return enWinner::PLAYER;
}

enWinner whoWonTheGame(short playerWinTimes, short copmuterWinTimes){

    if(playerWinTimes > copmuterWinTimes)
        return enWinner::PLAYER;
    else if(copmuterWinTimes > playerWinTimes)
        return enWinner::COMPUTER;
    else
        return enWinner::DRAW;
}

stGameResults fillGameResults(int gameRounds, short playerWinTimes, short computerWinTimes, short drawTimes){

    stGameResults gameResults;

    gameResults.gameRounds = gameRounds;
    gameResults.playerWinTimes = playerWinTimes;
    gameResults.computerWinTimes = computerWinTimes;
    gameResults.drawTimes = drawTimes;
    gameResults.gameWinner = whoWonTheGame(playerWinTimes,computerWinTimes);
    gameResults.winnerName = winnerName(gameResults.gameWinner);

    return gameResults;
}

void printRoundResults(stRoundInfo roundInfo){

    cout << "\n___________Round [" << roundInfo.roundNumber << "]___________\n\n";
    cout << "Player Choice   : " << choiceName(roundInfo.playerChoice) << endl;
    cout << "Computer Choice : " << choiceName(roundInfo.computerChoice) << endl;
    cout << "Round Winner    : [" << roundInfo.winnerName << "] \n";
    cout << "_________________________________\n" << endl;

}

stGameResults playGame(short howManyRounds){
    
    stRoundInfo roundInfo;
    short playerWinTimes = 0, computerWinTimes = 0, drawTimes = 0;

    for (short gameRound = 1; gameRound <= howManyRounds; gameRound++){

        cout << "\nRound [" << gameRound << "] begins:\n";
        roundInfo.roundNumber =gameRound;
        roundInfo.playerChoice = readPlayerChoice();
        roundInfo.computerChoice = getComputerChoice();
        roundInfo.winner = whoWonTheRound(roundInfo);
        roundInfo.winnerName = winnerName(roundInfo.winner);
    
        // increase win/draw counters
        if(roundInfo.winner == enWinner::PLAYER)
            playerWinTimes++;
        else if (roundInfo.winner == enWinner::COMPUTER)
            computerWinTimes++;
        else
            drawTimes++;

        printRoundResults(roundInfo);
    }

    return fillGameResults(howManyRounds, playerWinTimes, computerWinTimes, drawTimes);
}

string tabs(short numberOfTabs){

    string t = "";
    
    for(int i = 1; i < numberOfTabs; i++){
        t = t + "\t";
        cout << t;
    }
    
    return t;
}

void showGameOverScreen(){

    cout << tabs(2) << "______________________________________________\n\n";
    cout << tabs(2) << "           +++ G A M E O V E R +++\n";
    cout << tabs(2) << "______________________________________________\n\n";
}

void showFinalGameResults(stGameResults gameResults){

    cout << tabs(2) << "_______________ [Game Results] _______________\n\n";
    cout << tabs(2) << "Game Rounds        : " << gameResults.gameRounds << endl;
    cout << tabs(2) << "Player won times   : " << gameResults.playerWinTimes << endl;
    cout << tabs(2) << "Computer won times : " << gameResults.computerWinTimes << endl;
    cout << tabs(2) << "Draw times         : " << gameResults.drawTimes << endl;
    cout << tabs(2) << "Final winner       : " << gameResults.winnerName << endl;
    cout << tabs(2) << "______________________________________________\n\n";
}

void resetScreen(){

    system("clear");
}

void startGame(){
    
    char playAgain = 'Y';

    do{

        resetScreen();
        stGameResults gameResults = playGame(readHowManyRounds());
        showGameOverScreen();
        showFinalGameResults(gameResults);

        cout << endl << tabs(2) << "Do you want to play again? Y/N? ";
        cin >> playAgain;
    }while(playAgain == 'Y' || playAgain == 'y');
}


int main(){

    srand((unsigned)time(NULL));

    startGame();


    return 0;
}