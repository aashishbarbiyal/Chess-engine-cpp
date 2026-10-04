#include <iostream>
#include "Board.h"
#include "Pieces.h"
using namespace std;

int main()
{
    Board board;
    Pieces piece;
    board.initialize();

    bool gameOver = false;
    bool whiteTurn = true;

    while (!gameOver)
    {
        board.display();

        if (whiteTurn)
        {
            cout << "White's Turn" << endl;
        }
        else
        {
            cout << "Black's Turn" << endl;
        }

        string from, to;
        cout << "Enter Source Position" << endl;
        cin >> from;

        cout << "Enter destination Position" << endl;
        cin >> to;

        pair<int, int> fromcoor = board.coordinate(from);
        pair<int, int> tocoor = board.coordinate(to);

        if(piece.isValidMove(fromcoor,tocoor,board,whiteTurn)){
            board.movePiece(fromcoor, tocoor);
            whiteTurn = !whiteTurn;
        }
        else{
            cout << "Invalid Move" << endl;
        }
        
        // if (checkmate || stalemate)
            // gameOver = true;
    }
}
