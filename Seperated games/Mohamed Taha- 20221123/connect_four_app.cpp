// File name: Connect four game
// Author(s): Mohamed Taha Abdelhamid.
// ID(s): 20221123.
// Section: S22.
// Date: 14/12/2023
#include <bits/stdc++.h>
using namespace std;
class Board
{
protected:
    int n_rows, n_cols;
    char **board;
    int n_moves = 0;

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board(int x, int y, char symbol) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool is_winner() = 0;
    // Return true if all moves are done and no winner
    virtual bool is_draw() = 0;
    // Display the board and the pieces on it
    virtual void display_board() = 0;
    // Return true if game is over
    virtual bool game_is_over() = 0;
};
class Connect_four_board : public Board
{
protected:
public:
    Connect_four_board();
    bool update_board(int x, int y, char mark);
    bool is_winner();
    bool is_draw();
    void display_board();
    bool game_is_over();
};
///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board : public Board
{
public:
    X_O_Board();
    bool update_board(int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player
{
protected:
    string name;
    char symbol;

public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player(char symbol); // Needed for computer players
    Player(int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int &x, int &y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer : public Player
{
protected:
    int dimension;

public:
    // Take a symbol and pass it to parent
    RandomPlayer(char symbol, int dimension);
    // Generate a random move
    void get_move(int &x, int &y);
};
///////////////////////////////////////////
class GameManager
{
private:
    Board *boardPtr;
    Player *players[2];

public:
    GameManager(Board *, Player *playerPtr[2]);
    void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end
};
Player::Player(char symbol)
{
    this->symbol = symbol;
}
// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player(int order, char symbol)
{
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}
// Get desired move: x y (each between 0 and 2)
// Virtual (can change for other player types)
void Player::get_move(int &x, int &y)
{
    cout << "\nPlease enter your move  y separated by spaces: ";
    cin >> y;
}
// Give player info as a string
string Player::to_string()
{
    return "Player: " + name;
}
// Get symbol used by player
char Player::get_symbol()
{
    return symbol;
}
X_O_Board::X_O_Board()
{
    n_rows = n_cols = 3;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
Connect_four_board::Connect_four_board()
{
    n_rows = 6;
    n_cols = 7;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
}
// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board(int x, int y, char mark)
{
    // Only update if move is valid
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
bool Connect_four_board::update_board(int x, int y, char mark)
{
    x = 0;
    if (!(y < 0 || y > 7) && (board[0][y] == ' '))
    {
        for (int i = 5; i >= 0; i--)
        {
            if (board[i][y] == ' ')
            {
                board[i][y] = toupper(mark);
                n_moves++;
                return true;
            }
        }
    }
    else
        return false;
    return false;
}
// Display the board and the pieces on it
void X_O_Board::display_board()
{
    for (int i : {0, 1, 2})
    {
        cout << "\n| ";
        for (int j : {0, 1, 2})
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
void Connect_four_board::display_board()
{
    cout << "\n";
    for (int i = 0; i < 7; ++i)
    {
        cout << "|";
        cout << setw(2) << i << " ";
    }
    cout << "|\n-----------------------------";
    for (int i = 0; i < 6; ++i)
    {
        cout << "\n|";
        for (int j = 0; j < 7; ++j)
        {
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner()
{
    char row_win[3], col_win[3], diag_win[2];
    for (int i : {0, 1, 2})
    {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i : {0, 1, 2})
    {
        if ((row_win[i] && (row_win[i] == board[i][0])) ||
            (col_win[i] && (col_win[i] == board[0][i])))
        {
            return true;
        }
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
    {
        return true;
    }
    return false;
}
bool Connect_four_board::is_winner()
{
    // Check horizontally for four consecutive marks
    for (int row = 0; row < 6; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            if (board[row][col] != ' ' &&
                board[row][col] == board[row][col + 1] &&
                board[row][col] == board[row][col + 2] &&
                board[row][col] == board[row][col + 3])
            {
                return true;
            }
        }
    }
    // Check vertically for four consecutive marks
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 7; ++col)
        {
            if (board[row][col] != ' ' &&
                board[row][col] == board[row + 1][col] &&
                board[row][col] == board[row + 2][col] &&
                board[row][col] == board[row + 3][col])
            {
                return true;
            }
        }
    }
    // Check diagonals (positive slope)
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            if (board[row][col] != ' ' &&
                board[row][col] == board[row + 1][col + 1] &&
                board[row][col] == board[row + 2][col + 2] &&
                board[row][col] == board[row + 3][col + 3])
            {
                return true;
            }
        }
    }
    // Check diagonals (negative slope)
    for (int row = 3; row < 6; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            if (board[row][col] != ' ' &&
                board[row][col] == board[row - 1][col + 1] &&
                board[row][col] == board[row - 2][col + 2] &&
                board[row][col] == board[row - 3][col + 3])
            {
                return true;
            }
        }
    }
    return false;
}
// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw()
{
    return (n_moves == 9 && !is_winner());
}
bool Connect_four_board::is_draw()
{
    return (n_moves == 42 && !is_winner());
}
bool X_O_Board::game_is_over()
{
    return n_moves >= 9;
}
bool Connect_four_board::game_is_over()
{
    return n_moves >= 42;
}
RandomPlayer::RandomPlayer(char symbol, int dimension) : Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}
// Generate a random move
void RandomPlayer::get_move(int &x, int &y)
{
    x = (int)(rand() / (RAND_MAX + 1.0) * dimension);
    y = (int)(rand() / (RAND_MAX + 1.0) * dimension);
}
GameManager::GameManager(Board *bPtr, Player *playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}
void GameManager::run()
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over())
    {
        for (int i : {0, 1})
        {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol()))
            {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner())
            {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw())
            {
                cout << "Draw!\n";
                return;
            }
        }
    }
}
int main()
{
    system("cls");
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        // Player pointer points to child
        players[1] = new RandomPlayer('o', 7);
    GameManager x_o_game(new Connect_four_board(), players);
    x_o_game.run();
    system("pause");
}
