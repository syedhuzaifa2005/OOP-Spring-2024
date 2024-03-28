/*
Programmer: Syed Huzaifa Ali
Roll No: 23K-0004
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class ChessPiece {
private:
    string name;
    char color;
    char symbol;

public:
    ChessPiece() : name("Pawn"), color('W'), symbol('p') {}
    
    ChessPiece(string pieceName, char pieceColor, char pieceSymbol)
        : name(pieceName), color(pieceColor), symbol(pieceSymbol) {}

    std::string getName() const { return name; }
    char getColor() const { return color; }
    char getSymbol() const { return symbol; }

    void setName(string newName) { name = newName; }
    void setColor(char newColor) { color = newColor; }
    void setSymbol(char newSymbol) { symbol = newSymbol; }
};

class ChessBoard {
private:
    ChessPiece* board[8][8];

public:
    ChessBoard() {
        initializeBoard();
    }

    void initializeBoard() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (i == 1 || i == 6) {
                    board[i][j] = new ChessPiece("Pawn", (i == 1) ? 'W' : 'B', 'p');
                } else if ((i == 0 || i == 7) && (j == 0 || j == 7)) {
                    board[i][j] = new ChessPiece("Rook", (i == 0) ? 'W' : 'B', 'R');
                } else if ((i == 0 || i == 7) && (j == 1 || j == 6)) {
                    board[i][j] = new ChessPiece("Knight", (i == 0) ? 'W' : 'B', 'N');
                } else if ((i == 0 || i == 7) && (j == 2 || j == 5)) {
                    board[i][j] = new ChessPiece("Bishop", (i == 0) ? 'W' : 'B', 'B');
                } else if ((i == 0 || i == 7) && j == 3) {
                    board[i][j] = new ChessPiece("Queen", (i == 0) ? 'W' : 'B', 'Q');
                } else if ((i == 0 || i == 7) && j == 4) {
                    board[i][j] = new ChessPiece("King", (i == 0) ? 'W' : 'B', 'K');
                } else {
                    board[i][j] = NULL;
                }
            }
        }
    }

    void display() const {
        cout << "  a \tb \tc \td \te \tf \tg \th\n";
        for (int i = 7; i >= 0; --i) {
            cout << i + 1 << " ";
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] != NULL) {
                    char pieceSymbol = (board[i][j]->getColor() == 'W') ? 
                                        tolower(board[i][j]->getSymbol()) : board[i][j]->getSymbol();
                    cout << pieceSymbol << " \t";
                } else {
                    cout << ". \t";
                }
            }
            cout << i + 1 << "\n";
        }
        cout << "  a \tb \tc \td \te \tf \tg \th\n";
    }

    bool movePiece(std::string source, std::string destination) {
        int sourceRow = 8 - (source[1] - '0');
        int sourceCol = source[0] - 'a';
        int destRow = 8 - (destination[1] - '0');
        int destCol = destination[0] - 'a';

        if (sourceRow < 0 || sourceRow >= 8 || sourceCol < 0 || sourceCol >= 8 ||
            destRow < 0 || destRow >= 8 || destCol < 0 || destCol >= 8) {
            cout << "Invalid move: Out of bounds\n";
            return false;
        }

        if (board[sourceRow][sourceCol] == NULL) {
            cout << "Invalid move: No piece at source position\n";
            return false;
        }

        char pieceSymbol = board[sourceRow][sourceCol]->getSymbol();
        char pieceColor = board[sourceRow][sourceCol]->getColor();

        if (pieceSymbol == 'N' || pieceSymbol == 'n') {
            int rowDiff = abs(destRow - sourceRow);
            int colDiff = abs(destCol - sourceCol);
            if ((rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2)) {
                delete board[destRow][destCol];
                board[destRow][destCol] = board[sourceRow][sourceCol];
                board[sourceRow][sourceCol] = NULL;
                return true;
            } else {
                cout << "Invalid move for a knight\n";
                return false;
            }
        }

        if (pieceSymbol == 'P' || pieceSymbol == 'p') {
            int rowDiff = destRow - sourceRow;
            int colDiff = abs(destCol - sourceCol);
            if ((pieceColor == 'W' && rowDiff == 1 && colDiff == 0) ||
                (pieceColor == 'B' && rowDiff == -1 && colDiff == 0)) {
                delete board[destRow][destCol];
                board[destRow][destCol] = board[sourceRow][sourceCol];
                board[sourceRow][sourceCol] = NULL;
                return true;
            } else if ((pieceColor == 'W' && sourceRow == 1 && rowDiff == 2 && colDiff == 0) ||
                       (pieceColor == 'B' && sourceRow == 6 && rowDiff == -2 && colDiff == 0)) {
                delete board[destRow][destCol];
                board[destRow][destCol] = board[sourceRow][sourceCol];
                board[sourceRow][sourceCol] = NULL;
                return true;
            } else {
                cout << "Invalid move for a pawn\n";
                return false;
            }
        }

        cout << "Invalid move for the selected piece\n";
        return false;
    }
};

int main() {
	cout << "Syed Huzaifa Ali" << endl << "23K-0004" << endl << endl;
	
    ChessBoard chessBoard;
    chessBoard.display();

    chessBoard.movePiece("b8", "a6");
    chessBoard.display();

    chessBoard.movePiece("b8", "d7");
    chessBoard.display();

    return 0;
}

