#ifndef PIECES_H
#define PIECES_H
#include "Board.h"

#include<utility>

class Pieces{
public:
    bool isPawnMove(std::pair<int,int> from, std::pair<int,int> to, Board &board);
    bool isKnightMove(std::pair<int,int> from, std::pair<int,int> to, Board &board);
    bool isBishopMove(std::pair<int,int> from, std::pair<int,int> to, Board &board);
    bool isRookMove(std::pair<int,int> from, std::pair<int,int> to, Board &board);
    bool isQueenMove(std::pair<int,int> from, std::pair<int,int> to, Board &board);
    bool isKingMove(std::pair<int,int> from, std::pair<int,int> to, Board &board);
    bool isValidMove(std::pair<int,int> from, std::pair<int,int> to, Board &board,bool whiteTurn);
    bool isInCheck(Board board,bool white);

};

#endif