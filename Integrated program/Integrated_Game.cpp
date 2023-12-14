

#include <iostream>
#include"include/BoardGame_Classes.hpp"
using namespace std;

int main()
{
    int choice;

    while (true)
    {
        cout << "\nChoose a game to play:\n";
        cout << "1. X_O (3x3)\n";
        cout << "2. X_O (5x5)\n";
        cout << "3. Pyramic\n";
        cout << "4. Connect4\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Player *players[2];
            players[0] = new Player(1, 'x');
            cout << "Press 1 if you want to play with computer or 2 to play with your friend: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                // Player pointer points to child
                players[1] = new RandomPlayer('o', 3);
            GameManager x_o_game(new X_O_Board(), players);
            x_o_game.run();
            system("pause");
            break;
        }
        case 2:
        {
            Player *players[2];
            players[0] = new Player(1, 'x');
            cout << "Press 1 if you want to play with computer or 2 to play with your friend: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                // Player pointer points to child
                players[1] = new RandomPlayer('o', 5);
            GameManager x_o_game(new X_O_Board5x5(), players);
            x_o_game.run();
            system("pause");
            break;
        }
        case 3:
        {
            Player *players[2];
            players[0] = new Player(1, 'x');
            cout << "Press 1 if you want to play with computer or 2 to play with your friend: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                // Player pointer points to child
                players[1] = new RandomPlayer('o', 3);
            GameManager x_o_game(new Pyramic_X_O(), players);
            x_o_game.run();
            system("pause");
            break;
        }
        case 4:
        {
            Player *players[2];
            players[0] = new Player(1, 'x');
            cout << "Press 1 if you want to play with computer or 2 to play with your friend: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player(2, 'o');
            else
                // Player pointer points to child
                players[1] = new RandomPlayer('o', 7);
            GameManager x_o_game(new Connect_four_board(), players);
            x_o_game.run_connect();
            system("pause");
            break;
        }
        case 5:
        {
            cout << "Thank you for playing!\n";
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            break;
        }
        }
    }

    return 0;
}
