#ifndef BOARD_H
#define BOARD_H


#include <utility>
#include<string>
class Board{
private:
    char board[8][8];
public:
    void initialize();
    void display();
    std::pair<int,int> coordinate(std::string s);
    char getPiece(int row, int col);
    bool isValidCoordinate(int row,int col);
    void movePiece(std::pair<int,int> from, std::pair<int,int> to);

};

#endif