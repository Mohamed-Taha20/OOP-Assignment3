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
X_O_Board::X_O_Board () {
   n_rows = n_cols = 3;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
   for (int i: {0,1,2}) {
      cout << "\n| ";
      for (int j: {0,1,2}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n-----------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == board[i][0])) ||
             (col_win[i] && (col_win[i] == board[0][i])) )
            {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
        {return true;}
    return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}

//////////////////////////////////////
//X_O 5x5 board

X_O_Board5x5::X_O_Board5x5 () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool X_O_Board5x5::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}


void X_O_Board5x5::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n----------------------------------------------";
    }
    cout << endl;
}

bool X_O_Board5x5::is_winner(){
    if(n_moves == 24){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if(check_row(i,j)){
                    if(board[i][j] == 'X'){
                        player1++;
                    }
                    else if(board[i][j] == 'O'){
                        player2++;
                    }
                }
                if(check_column(i,j)){
                    if(board[i][j] == 'X'){
                        player1++;
                    }
                    else if(board[i][j] == 'O'){
                        player2++;
                    }
                }
                if(check_diagonal1(i,j)){
                    if(board[i][j] == 'X'){
                        player1++;
                    }
                    else if(board[i][j] == 'O'){
                        player2++;
                    }
                }
                if(check_diagonal2(i,j)){
                    if(board[i][j] == 'X'){
                        player1++;
                    }
                    else if(board[i][j] == 'O'){
                        player2++;
                    }
                }
            }
        }
        if(player1 == player2){
            return false;
        }
        else{
            cout << player1 << " "<< player2;
            return true;
        }
    }
    return false;
}

bool X_O_Board5x5::is_valid(int x, int y) {
    if (!(x < 0 || x > 4 || y < 0 || y > 4)) {
        return true;
    }
    return false;
}

bool X_O_Board5x5::check_row(int x,int y){
    if(is_valid(x,y+1) && is_valid(x,y+2)){
        if(board[x][y] == board[x][y] && board[x][y+1] == board[x][y] && board[x][y+2] == board[x][y]){
            return true;
        }
        return false;
    }

}

bool X_O_Board5x5::check_column(int x,int y){
    if(is_valid(x+1,y) && is_valid(x+2,y)){
        if(board[x][y] == board[x][y] && board[x+1][y] == board[x][y] && board[x+2][y] == board[x][y]){
            return true;
        }
        return false;
    }
}

bool X_O_Board5x5::check_diagonal1(int x,int y){
    if(is_valid(x+1,y+1) && is_valid(x+2,y+2)){
        if((board[x][y] == board[x][y] && board[x+1][y+1] == board[x][y] && board[x+2][y+2] == board[x][y])){
            return true;
        }
        return false;
    }
}
bool X_O_Board5x5::check_diagonal2(int x, int y) {
    if(is_valid(x+1,y-1) && is_valid(x+2,y-2)){
        if((board[x][y] == board[x][y] && board[x+1][y-1] == board[x][y] && board[x+2][y-2] == board[x][y])){
            return true;
        }
        return false;
    }
}
// Return true if 24 moves are done and no winner
bool X_O_Board5x5::is_draw(){
    return (n_moves == 24 && !is_winner());
}

bool X_O_Board5x5::game_is_over(){
    return (n_moves >= 24);
}
