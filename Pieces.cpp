#include <iostream>
#include "Board.h"
#include "Pieces.h"
#include <cmath>
using namespace std;

bool Pieces::isPawnMove(pair<int, int> from, pair<int, int> to, Board &board)
{

    int r1 = from.first, c1 = from.second;
    int r2 = to.first, c2 = to.second;

    char pawn = board.getPiece(r1, c1);

    if ((pawn != 'p' && pawn != 'P') || !board.isValidCoordinate(r2, c2))
        return false;

    // Black Pawn
    if (pawn == 'p')
    {
        // starting from first
        if (r2 == 1)
        {
            if (r2 == r1 + 1 && board.getPiece(r2, c1) == '.')
                return true;
            if (r2 == r1 + 2)
            {
                if (board.getPiece(r1 + 1, c1) == '.' && board.getPiece(r1 + 2, c1) == '.')
                    return true;
            }
        }
        // starting from mid
        if (r2 == r1 + 1 && board.getPiece(r2, c1) == '.')
            return true;
        // Capturing cross
        if (r2 == r1 + 1 && (c2 == c1 + 1 || c2 == c1 - 1) && board.getPiece(r2, c2) >= 'A' && board.getPiece(r2, c2) <= 'Z')
            return true;
    }

    // White Pawn
    if (pawn == 'P')
    {
        // starting from first
        if (r2 == 6)
        {
            if (r2 == r1 - 1 && board.getPiece(r2, c1) == '.')
                return true;
            if (r2 == r1 - 2)
            {
                if (board.getPiece(r1 - 1, c1) == '.' && board.getPiece(r1 - 2, c1) == '.')
                    return true;
            }
        }
        // starting from mid
        if (r2 == r1 - 1 && board.getPiece(r2, c1) == '.')
            return true;
        // Capturing cross
        if (r2 == r1 - 1 && (c2 == c1 + 1 || c2 == c1 - 1) && board.getPiece(r2, c2) >= 'a' && board.getPiece(r2, c2) <= 'z')
            return true;
    }

    return false;
}
bool Pieces::isKnightMove(pair<int, int> from, pair<int, int> to, Board &board)
{
    int r1 = from.first, c1 = from.second;
    int r2 = to.first, c2 = to.second;

    char knight = board.getPiece(r1, c1);

    if ((knight != 'n' && knight != 'N') || !board.isValidCoordinate(r2, c2))
    {
        return false;
    }

    char dest = board.getPiece(r2, c2);

    // 8 conditions for black knight

    if (knight == 'n')
    {
        // 1
        if (r2 == r1 + 2 && c2 == c1 + 1 && (dest == '.' || (dest >= 'A' && dest <= 'Z')))
            return true;
        // 2
        if (r2 == r1 + 2 && c2 == c1 - 1 && (dest == '.' || (dest >= 'A' && dest <= 'Z')))
            return true;
        // 3
        if (r2 == r1 - 2 && c2 == c1 + 1 && (dest == '.' || (dest >= 'A' && dest <= 'Z')))
            return true;
        // 4
        if (r2 == r1 - 2 && c2 == c1 - 1 && (dest == '.' || (dest >= 'A' && dest <= 'Z')))
            return true;
        // 5
        if (r2 == r1 + 1 && c2 == c1 + 2 && (dest == '.' || (dest >= 'A' && dest <= 'Z')))
            return true;
        // 6
        if (r2 == r1 - 1 && c2 == c1 + 2 && (dest == '.' || (dest >= 'A' && dest <= 'Z')))
            return true;
        // 7
        if (r2 == r1 + 1 && c2 == c1 - 2 && (dest == '.' || (dest >= 'A' && dest <= 'Z')))
            return true;
        // 8
        if (r2 == r1 - 1 && c2 == c1 - 2 && (dest == '.' || (dest >= 'A' && dest <= 'Z')))
            return true;
    }

    // White Knight
    if (knight == 'N')
    {
        // 1
        if (r2 == r1 + 2 && c2 == c1 + 1 && (dest == '.' || (dest >= 'a' && dest <= 'z')))
            return true;
        // 2
        if (r2 == r1 + 2 && c2 == c1 - 1 && (dest == '.' || (dest >= 'a' && dest <= 'z')))
            return true;
        // 3
        if (r2 == r1 - 2 && c2 == c1 + 1 && (dest == '.' || (dest >= 'a' && dest <= 'z')))
            return true;
        // 4
        if (r2 == r1 - 2 && c2 == c1 - 1 && (dest == '.' || (dest >= 'a' && dest <= 'z')))
            return true;
        // 5
        if (r2 == r1 + 1 && c2 == c1 + 2 && (dest == '.' || (dest >= 'a' && dest <= 'z')))
            return true;
        // 6
        if (r2 == r1 - 1 && c2 == c1 + 2 && (dest == '.' || (dest >= 'a' && dest <= 'z')))
            return true;
        // 7
        if (r2 == r1 + 1 && c2 == c1 - 2 && (dest == '.' || (dest >= 'a' && dest <= 'z')))
            return true;
        // 8
        if (r2 == r1 - 1 && c2 == c1 - 2 && (dest == '.' || (dest >= 'a' && dest <= 'z')))
            return true;
    }

    return false;
}
bool Pieces::isBishopMove(pair<int, int> from, pair<int, int> to, Board &board)
{
    int r1 = from.first, c1 = from.second;
    int r2 = to.first, c2 = to.second;
    if (!board.isValidCoordinate(r2, c2))
        return false;

    if (abs(r1 - r2) != abs(c1 - c2))
        return false;
    char bishop = board.getPiece(r1, c1);
    char dest = board.getPiece(r2, c2);

    if (bishop == 'b' && dest >= 'a' && dest <= 'z')
        return false;
    if (bishop == 'B' && dest >= 'A' && dest <= 'Z')
        return false;

    int rowStep = (r2 > r1) ? 1 : -1;
    int colStep = (c2 > c1) ? 1 : -1;

    int r = r1 + rowStep;
    int c = c1 + colStep;
    while (r != r2 && c != c2)
    {
        if (board.getPiece(r, c) != '.')
        {
            return false;
        }
        r += rowStep;
        c += colStep;
    }

    return true;
}
bool Pieces::isRookMove(pair<int, int> from, pair<int, int> to, Board &board)
{
    int r1 = from.first, c1 = from.second;
    int r2 = to.first, c2 = to.second;

    if (!board.isValidCoordinate(r2, c2))
        return false;

    if (r1 != r2 && c1 != c2)
        return false;
    char rook = board.getPiece(r1, c1);
    char dest = board.getPiece(r2, c2);

    if (rook != 'r' && rook != 'R')
        return false;

    if (rook == 'r' && dest >= 'a' && dest <= 'z')
        return false;
    if (rook == 'R' && dest >= 'A' && dest <= 'Z')
        return false;

    int step = 0;
    if (r1 == r2)
    {
        step = (c2 > c1) ? 1 : -1;
        for (int c = c1 + step; c != c2; c += step)
        {
            if (board.getPiece(r1, c) != '.')
                return false;
        }
    }
    if (c1 == c2)
    {
        step = (r2 > r1) ? 1 : -1;
        for (int r = r1 + step; r != r2; r += step)
        {
            if (board.getPiece(r, c1) != '.')
            {
                return false;
            }
        }
    }

    return true;
}
bool Pieces::isQueenMove(pair<int, int> from, pair<int, int> to, Board &board)
{
    int r1 = from.first, c1 = from.second;
    int r2 = to.first, c2 = to.second;

    if (!board.isValidCoordinate(r2, c2))
        return false;
    char queen = board.getPiece(r1, c1);
    char dest = board.getPiece(r2, c2);

    if (queen != 'q' && queen != 'Q')
        return false;

    if (queen == 'q' && dest >= 'a' && dest <= 'z')
        return false;

    if (queen == 'Q' && dest >= 'A' && dest <= 'Z')
        return false;

    if (r1 == r2 || c1 == c2)
    {
        // Rook's Move
        int step = 0;
        if (r1 == r2)
        {
            step = (c2 > c1) ? 1 : -1;
            for (int c = c1 + step; c != c2; c += step)
            {
                if (board.getPiece(r1, c) != '.')
                    return false;
            }
        }
        if (c1 == c2)
        {
            step = (r2 > r1) ? 1 : -1;
            for (int r = r1 + step; r != r2; r += step)
            {
                if (board.getPiece(r, c1) != '.')
                {
                    return false;
                }
            }
        }

        return true;
    }
    else if (abs(r1 - r2) == abs(c1 - c2))
    {
        // Bishop's Move
        int rowStep = (r2 > r1) ? 1 : -1;
        int colStep = (c2 > c1) ? 1 : -1;

        int r = r1 + rowStep;
        int c = c1 + colStep;
        while (r != r2 && c != c2)
        {
            if (board.getPiece(r, c) != '.')
            {
                return false;
            }
            r += rowStep;
            c += colStep;
        }

        return true;
    }
    else
    {
        return false;
    }
}
bool Pieces::isKingMove(pair<int, int> from, pair<int, int> to, Board &board)
{
    int r1 = from.first, c1 = from.second;
    int r2 = to.first, c2 = to.second;

    if (!board.isValidCoordinate(r2, c2))
        return false;

    char king = board.getPiece(r1, c1);
    char dest = board.getPiece(r2, c2);

    if (king != 'k' && king != 'K')
        return false;

    if (king == 'k' && dest >= 'a' && dest <= 'z')
        return false;

    if (king == 'K' && dest >= 'A' && dest <= 'Z')
        return false;

    if (abs(r2 - r1) <= 1 && abs(c2 - c1) <= 1 &&
        (r2 != r1 || c2 != c1))
        return true;

    return false;
}
bool Pieces::isValidMove(std::pair<int, int> from, std::pair<int, int> to, Board &board, bool whiteTurn)
{
    char piece = board.getPiece(from.first, from.second);

    if (whiteTurn)
    {
        if (piece < 'A' || piece > 'Z')
            return false;
    }
    else
    {
        if (piece < 'a' || piece > 'z')
            return false;
    }

    if (piece == 'p' || piece == 'P')
        isPawnMove(from, to, board);
    if (piece == 'n' || piece == 'N')
        isKnightMove(from, to, board);
    if (piece == 'b' || piece == 'B')
        isBishopMove(from, to, board);
    if (piece == 'r' || piece == 'R')
        isRookMove(from, to, board);
    if (piece == 'q' || piece == 'Q')
        isKingMove(from, to, board);
}
bool Pieces::isInCheck(Board board, bool white)
{
    char king, pawn, knight, rook, bishop, queen;
    if (white)
    {
        king = 'K';

        pawn = 'p';
        knight = 'n';
        bishop = 'b';
        rook = 'r';
        queen = 'q';
    }
    else
    {
        king = 'k';
    }

    int kingrow = -1;
    int kingcol = -1;
    for (int i = 0; i < 8 && kingrow != -1; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board.getPiece(i, j == king))
            {
                kingrow = i;
                kingcol = j;
                break;
            }
        }
    }

    // knight check
}