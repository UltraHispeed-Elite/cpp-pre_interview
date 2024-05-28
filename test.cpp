#include <iostream>
#include <string>
using namespace std;

enum action_key {
    END = -1,
    SEEMOVES = 0,
    SETNAME = 1,
};

int move_count = 1;

string action;
enum action_key action_translation;

struct {
    string name;
} character;

void listMoves() {
    cout << "end | ends the program \n";
    cout << "setName | sets your character's name \n";
}

void setName() {
    cout << "What is your name?: ";
    cin >> character.name;
    cout << "Hello "+character.name+".\n";
}

void next_move() {
    int i = 0;
    while(i < move_count) {
        cin >> action;

        if(action == "seeMoves") {
            action_translation = SEEMOVES;
        }else if(action == "setName") {
            action_translation = SETNAME;
        }else if(action == "end") {
            action_translation = END;
        }

        switch(action_translation) {
            case -1:
                i = move_count;
                break;
            case 0:
                listMoves();
                break;
            case 1:
                setName();
                break;
        }
        move_count++;
        i++;
    }
}

void intro() {
    cout << "Welcome to the testing field \n";
    cout << "You'll be entering commands and such to test the use cases of specific things \n";
    cout << "This is bascially a text based game \n";
    cout << "use command 'seeMoves' to get started \n";
}

int main() {
    intro();
    next_move();
    return 0;
}
