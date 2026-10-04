#include "Board.h"
#include <iostream>
using namespace std;

void Board::initialize()
{
    char arr[8] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    // row 0
    for (int i = 0; i < 8; i++)
    {
        board[0][i] = arr[i];
    }
    // row 1
    for (int j = 0; j < 8; j++)
    {
        board[1][j] = 'p';
    }
    for (int i = 2; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = '.';
        }
    }
    // row 6
    for (int j = 0; j < 8; j++)
    {
        board[6][j] = 'P';
    }
    // row 7
    for (int i = 0; i < 8; i++)
    {
        board[7][i] = arr[i] - ('a' - 'A');
    }
}

void Board::display()
{
    cout << "    a b c d e f g h" << endl;
    cout << "  -----------------" << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << 8 - i << " | ";

        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << "| " << 8 - i << endl;
    }

    cout << "  -----------------" << endl;
    cout << "    a b c d e f g h" << endl;
}

pair<int, int> Board::coordinate(string s)
{
    if (s.size() != 2)
        return {-1, -1};
    return {s[1] - '1', s[0] - 'a'};
}

char Board::getPiece(int row, int col)
{
    return board[row][col];
}

bool Board::isValidCoordinate(int row, int col)
{
    if ((row >= 0 && row < 8) && (col >= 0 && col < 8))
        return true;
    return false;
}

void Board::movePiece(std::pair<int, int> from, std::pair<int, int> to)
{

    board[to.first][to.second] = board[from.first][from.second];
    board[from.first][from.second] = '.';
}