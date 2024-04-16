#include <iostream>
#include <vector>
using namespace std;

void displayBoard(const vector<vector<char>> &board)
{
  for (const auto &row : board)
  {
    for (char cell : row)
    {
      cout << cell << " ";
    }
    cout << endl;
  }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>> &board, char player)
{
  // Check rows, columns, and diagonals for three consecutive marks by the player
  for (int i = 0; i < 3; ++i)
  {
    if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
        (board[0][i] == player && board[1][i] == player && board[2][i] == player))
    {
      return true;
    }
  }
  if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
      (board[0][2] == player && board[1][1] == player && board[2][0] == player))
  {
    return true;
  }
  return false;
}

// Function to check if the board is full (draw)
bool checkDraw(const vector<vector<char>> &board)
{
  for (const auto &row : board)
  {
    for (char cell : row)
    {
      if (cell == ' ')
      {
        return false; // Found an empty cell, game is not draw
      }
    }
  }
  return true; // All cells are filled, game is draw
}

int main()
{
  vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board
  char currentPlayer = 'X';                            // Player X starts the game

  // Main game loop
  while (true)
  {
    cout << "Current Board:" << endl;
    displayBoard(board);

    int row, col;
    cout << "Player " << currentPlayer << ", enter your move (row and column): ";
    cin >> row >> col;

    // Check if the entered move is valid
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
    {
      cout << "Invalid move! Try again." << endl;
      continue;
    }

    // Update the board with the player's move
    board[row][col] = currentPlayer;

    // Check for win
    if (checkWin(board, currentPlayer))
    {
      cout << "Player " << currentPlayer << " wins!" << std::endl;
      break;
    }

    // Check for draw
    if (checkDraw(board))
    {
      cout << "It's a draw!" << std::endl;
      break;
    }

    // Switch players
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  return 0;
}