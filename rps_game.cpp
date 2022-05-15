// Author : Nemuel Wainaina

/*
    Rock-Paper-Scissors Game 
    => Play against the computer in this awesome game
    => Get the final score of both the computer and you, the player/user
    Have fun :)
*/

#include <iostream>
#include <ctime>

using namespace std;

char compChoice() {
    srand((unsigned)time(NULL));
    int n = rand() % 3;

    char cChoice;
    if (n == 0) {
        cChoice = 'R';
    } else if (n == 1) {
        cChoice = 'P';
    } else {
        cChoice = 'S';
    }

    return cChoice;
}

int judge(char cChoice, char uChoice) {
    int score; // 0, 1, 2

    if (cChoice == 'R') {
        if (uChoice == 'R') {
            cout<<"[=] That's a tie !"<<endl;
            score = 0;
        } else if (uChoice == 'P') {
            cout<<"[+] You win ! Paper covers Rock"<<endl;
            score = 2;
        } else { 
            cout<<"[-] You lose ! Rock breaks Scissors"<<endl;
            score = 1;
        }
    } else if (cChoice == 'P') {
        if (uChoice == 'R') {
            cout<<"[-] You lose ! Paper covers Rock"<<endl;
            score = 1;
        } else if (uChoice == 'P') {
            cout<<"[=] That's a tie !"<<endl;
            score = 0;
        } else {
            cout<<"[+] You win ! Scissors cut Paper"<<endl;
            score = 2;
        }
    } else { // cChoice == 'S'
        if (uChoice == 'R') {
            cout<<"[+] You win ! Rock breaks Scissors"<<endl;
            score = 2;
        } else if (uChoice == 'P') {
            cout<<"[-] You lose ! Scissors cut Paper"<<endl;
            score = 1;
        } else {
            cout<<"[=] That's a tie !"<<endl;
            score = 0;
        }
    }

    return score;
}

void announceResults(int comp, int user) {
    cout<<"========================="<<endl;
    cout<<"[+] COMPUTER : "<<comp<<endl;
    cout<<"[+] USER     : "<<user<<endl;
    
    if (comp > user) {
        cout<<"  *** WINNER : COMP ***";
    } else if (comp < user) {
        cout<<"  *** WINNER : USER ***";
    } else {
        cout<<"  *** NO WINNER => Tie!";
    }

    cout<<"\n========================="<<endl;
}

int main() {
    int comp = 0, user = 0; // keep track of the scores of computer and the user respectively

    while (1) {
        char cChoice = compChoice();
        char uChoice;
        cout<<"\n[*] Choose (R/P/S) : ";
        cin>>uChoice;

        int score = judge(cChoice, uChoice);
        if (score == 1) {
            comp += 1;
        } else if (score == 2) {
            user += 1;
        } else {
            // It's a tie, no score to either side
        }

        char ch;
        cout<<"\nWould you like to play again ? (Y/N) ";
        cin>>ch;
        if (ch != 'Y' && ch != 'y') {
            cout<<"\n\n";
            announceResults(comp, user);
            break;
        } else {
            continue;
        }
    }

    return 0;
}