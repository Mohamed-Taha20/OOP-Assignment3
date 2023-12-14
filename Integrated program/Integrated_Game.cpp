

#include <iostream>
#include"include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    string game;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "please choose any of this game you want to play X_O(3x3) or X_O(5x5) or pyramic or connect4: ";
    cin >> game;
    if(game == "3x3"){
        cout << "Press 1 if you want to play with computer or 2 to play with your friend: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);
        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
        system ("pause");
    }
    else if(game == "5x5"){
        cout << "Press 1 if you want to play with computer or 2 to play with your friend: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 5);
        GameManager x_o_game (new X_O_Board5x5(), players);
        x_o_game.run();
        system ("pause");
    }
    else if(game == "pyramic"){
        cout << "Press 1 if you want to play with computer or 2 to play with your friend: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 3);
        GameManager x_o_game (new Pyramic_X_O(), players);
        x_o_game.run();
        system ("pause");
    }
    else if(game == "connect4"){
        cout << "Press 1 if you want to play with computer or 2 to play with your friend: ";
        cin >> choice;
        if (choice != 1)
            players[1] = new Player (2, 'o');
        else
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 7);
        GameManager x_o_game (new Connect_four_board(), players);
        x_o_game.run_connect();
        system ("pause");
    }

}
