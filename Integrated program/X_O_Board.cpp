// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "include/BoardGame_Classes.hpp"
using namespace std;
// Set the board
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

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over()
{
    return n_moves >= 9;
}

//////////////////////////////////////
// X_O 5x5 board

X_O_Board5x5::X_O_Board5x5()
{
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool X_O_Board5x5::update_board(int x, int y, char mark)
{
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void X_O_Board5x5::display_board()
{
    for (int i : {0, 1, 2, 3, 4})
    {
        cout << "\n| ";
        for (int j : {0, 1, 2, 3, 4})
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n----------------------------------------------";
    }
    cout << endl;
}
int X_O_Board5x5::player1 = 0;
int X_O_Board5x5::player2 = 0;
bool X_O_Board5x5::is_winner()
{
    if (n_moves == 24)
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (check_row(i, j))
                {
                    if (board[i][j] == 'X')
                    {
                        player1++;
                    }
                    else if (board[i][j] == 'O')
                    {
                        player2++;
                    }
                }
                if (check_column(i, j))
                {
                    if (board[i][j] == 'X')
                    {
                        player1++;
                    }
                    else if (board[i][j] == 'O')
                    {
                        player2++;
                    }
                }
                if (check_diagonal1(i, j))
                {
                    if (board[i][j] == 'X')
                    {
                        player1++;
                    }
                    else if (board[i][j] == 'O')
                    {
                        player2++;
                    }
                }
                if (check_diagonal2(i, j))
                {
                    if (board[i][j] == 'X')
                    {
                        player1++;
                    }
                    else if (board[i][j] == 'O')
                    {
                        player2++;
                    }
                }
            }
        }
        if (player1 == player2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool X_O_Board5x5::is_valid(int x, int y)
{
    if (!(x < 0 || x > 4 || y < 0 || y > 4))
    {
        return true;
    }
    return false;
}

bool X_O_Board5x5::check_row(int x, int y)
{
    if (is_valid(x, y + 1) && is_valid(x, y + 2))
    {
        if (board[x][y + 1] == board[x][y] && board[x][y + 2] == board[x][y])
        {
            return true;
        }
        return false;
    }
    return false;
}

bool X_O_Board5x5::check_column(int x, int y)
{
    if (is_valid(x + 1, y) && is_valid(x + 2, y))
    {
        if (board[x + 1][y] == board[x][y] && board[x + 2][y] == board[x][y])
        {
            return true;
        }
        return false;
    }
    return false;
}

bool X_O_Board5x5::check_diagonal1(int x, int y)
{
    if (is_valid(x + 1, y + 1) && is_valid(x + 2, y + 2))
    {
        if ((board[x + 1][y + 1] == board[x][y] && board[x + 2][y + 2] == board[x][y]))
        {
            return true;
        }
        return false;
    }
    return false;
}
bool X_O_Board5x5::check_diagonal2(int x, int y)
{
    if (is_valid(x + 1, y - 1) && is_valid(x + 2, y - 2))
    {
        if ((board[x + 1][y - 1] == board[x][y] && board[x + 2][y - 2] == board[x][y]))
        {
            return true;
        }
        return false;
    }
    return false;
}
// Return true if 24 moves are done and no winner
bool X_O_Board5x5::is_draw()
{
    return (n_moves == 24 && !is_winner());
}

bool X_O_Board5x5::game_is_over()
{
    return (n_moves >= 24);
}

bool X_O_Board5x5::player1_winner()
{
    if (player1 > player2)
    {
        return true;
    }
    return false;
}

/////////////////////////////////////////////////////////
Pyramic_X_O ::Pyramic_X_O()
{
    n_rows = 3;
    n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = 0;
        }
    }
}

bool Pyramic_X_O ::update_board(int x, int y, char mark)
{
    // Only update if move is valid
    if (((x == 0 && y == 2) || (x == 1 && (y >= 1 && y <= 3)) || (x == 2 && (y >= 0 && y <= 4))) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void Pyramic_X_O ::display_board()
{
    cout << "             |" << board[0][2] << "(0,2)|"
         << "\n";
    cout << "____________________________________\n";
    cout << "       |" << board[1][1] << "(1,1)|" << board[1][2] << "(1,2)|" << board[1][3] << "(1,3)|"
         << "\n";
    cout << "____________________________________\n";
    cout << "  " << board[2][0] << "(2,0)|" << board[2][1] << "(2,1)|" << board[2][2] << "(2,2)|" << board[2][3] << "(2,3)|" << board[2][4] << "(2,4)"
         << "\n";
    cout << "____________________________________\n";
}
bool Pyramic_X_O::is_winner()
{
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[2][2] != 0)
    {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != 0)
    {
        return true;
    }
    if (board[1][1] == board[1][2] && board[1][2] == board[1][3] && board[1][3] != 0)
    {
        return true;
    }
    if (board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[2][4] != 0)
    {
        return true;
    }
    if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][2] != 0)
    {
        return true;
    }
    if (board[2][1] == board[2][2] && board[2][2] == board[2][3] && board[2][3] != 0)
    {
        return true;
    }
    if (board[2][2] == board[2][3] && board[2][3] == board[2][4] && board[2][4] != 0)
    {
        return true;
    }
    return false;
}
bool Pyramic_X_O::is_draw()
{
    return (n_moves == 9 && !is_winner());
}
bool Pyramic_X_O ::game_is_over()
{
    return n_moves >= 9;
}
/////////////////////////////////////////////////////
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

bool Connect_four_board::is_draw()
{
    return (n_moves == 42 && !is_winner());
}

bool Connect_four_board::game_is_over()
{
    return n_moves >= 42;
}
