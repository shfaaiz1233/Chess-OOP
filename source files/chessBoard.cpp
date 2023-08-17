#include "chessBoard.h"
#include"Pieces.h"
#include"Pawn.h"
#include"Bishop.h"
#include"Rook.h"
#include"Knight.h"
#include"King.h"
#include"Queen.h"
chessBoard::chessBoard()
{
	initializeBoard();
}

void chessBoard::draw()
{
	for (int row = 7; row >= 0; row--) {

		// Draws Horizontal Row Dividers
		cout << "   ";
		for (int col = 0; col < 8; col++) {
			cout << "-----";
		}
		cout << "-" << endl;


		// Draws Vertical Row Divider and Chess Piece
		cout << row + 1 << "  ";
		for (int col = 0; col < 8; col++) {
			cout << "| ";
			Pieces* currPiece = board[row][col].getPiece();
			if (currPiece != nullptr) {
				currPiece->draw();
			}
			else {
				cout << "  ";
			}
			cout << " ";
		}

		// Draws Divider for end of Row
		cout << "|" << endl;

	}

	// Draws Horitonal Divider for last Row
	cout << "   ";
	for (int col = 0; col < 8; col++) {
		cout << "-----";
	}
	cout << "-" << endl;

	// Draws Letters on botton of board
	cout << "   ";
	for (int col = 0; col < 8; col++) {
		cout << "  " << (char)(col + 97) << "  ";
	}
	cout << endl << endl;

}

bool chessBoard::checkInRange(Position& p)
{
	if ((p.getXpos() > -1 && p.getXpos() < 8) && (p.getYpos() > -1 && p.getYpos() < 8))
		return true;
	else
		return false;
}


Pieces* chessBoard::getPiece(Position& p)
{
	return board[p.getXpos()][p.getYpos()].getPiece();
}


bool chessBoard::movePiece(Position& p1, Position& p2)
{
	bool isMoved = false;
	Pieces* piece_to_move = board[p1.getXpos()][p1.getYpos()].getPiece();
	if (piece_to_move->validMove(p2) && piece_to_move != nullptr && this->checkInRange(p2))
	{
		piece_to_move->setPosition(p2);
		board[p2.getXpos()][p2.getYpos()].setPiece(piece_to_move);
		board[p1.getXpos()][p1.getYpos()].clear();
		isMoved = true;
	}
	if (piece_to_move->getType() == "p")
	{
		if (piece_to_move->getColor() == 'w'&&piece_to_move->getPosition().getXpos()==7)
		{
			cout << "**************************************************************************************\n";
			cout << "\t\tPromotion of white pawn.\n";
			cout << "**************************************************************************************\n";
			cout << "Press 1 to promote it to queen.\nPress 2 to promote it to Knight.\n";
			cout << "Press 3 to promote it to Bishop.\nPress 4 to promote it to Rook.\n";
			int option = 0;
			cin >> option;
			if (option == 1) {
				board[p2.getXpos()][p2.getYpos()].clear();
				board[p2.getXpos()][p2.getYpos()].setPiece(new Queen('w', p2));
			}
			else if (option == 2) {
				board[p2.getXpos()][p2.getYpos()].clear();
				board[p2.getXpos()][p2.getYpos()].setPiece(new Knight('w', p2));
			}
			else if (option == 3) {
				board[p2.getXpos()][p2.getYpos()].clear();
				board[p2.getXpos()][p2.getYpos()].setPiece(new Bishop('w', p2));
			}
			else if (option == 4) {
				board[p2.getXpos()][p2.getYpos()].clear();
				board[p2.getXpos()][p2.getYpos()].setPiece(new Rook('w', p2));
			}
			
		}
		else if (piece_to_move->getColor() == 'b' && piece_to_move->getPosition().getXpos() == 0)
		{
			cout << "**************************************************************************************\n";
			cout << "\t\tPromotion of black pawn.\n";
			cout << "**************************************************************************************\n";
			cout << "Press 1 to promote it to queen.\nPress 2 to promote it to Knight.\n";
			cout << "Press 3 to promote it to Bishop.\nPress 4 to promote it to Rook.\n";
			int option1 = 0;
			cin >> option1;
			if (option1 == 1) {
				board[p2.getXpos()][p2.getYpos()].clear();
				board[p2.getXpos()][p2.getYpos()].setPiece(new Queen('b', p2));
			}
			else if (option1 == 2) {
				board[p2.getXpos()][p2.getYpos()].clear();
				board[p2.getXpos()][p2.getYpos()].setPiece(new Knight('b', p2));
			}
			else if (option1 == 3) {
				board[p2.getXpos()][p2.getYpos()].clear();
				board[p2.getXpos()][p2.getYpos()].setPiece(new Bishop('b', p2));
			}
			else if (option1 == 4) {
				board[p2.getXpos()][p2.getYpos()].clear();
				board[p2.getXpos()][p2.getYpos()].setPiece(new Rook('b', p2));
			}
		}
	}
	return isMoved;
}


void chessBoard::initializeBoard()
{
	//***********************************************setting Pawns******************************************
	for (int i = 0; i < 8; i++)
	{
		//setting white pawns
		Position whitePawns(1, i);
		this->board[whitePawns.getXpos()][whitePawns.getYpos()].setPiece(new Pawn('w', whitePawns));
		//setting black pawns
		Position blackPawns(6, i);
		this->board[blackPawns.getXpos()][blackPawns.getYpos()].setPiece(new Pawn('b', blackPawns));
	}

	//*******************************Setting Rooks*************************************************************

	//setting white rooks
	Position forWhiteRook(0, 0);
	this->board[forWhiteRook.getXpos()][forWhiteRook.getYpos()].setPiece(new Rook('w', forWhiteRook));
	forWhiteRook.setXpos(0);
	forWhiteRook.setYpos(7);
	this->board[forWhiteRook.getXpos()][forWhiteRook.getYpos()].setPiece(new Rook('w', forWhiteRook));

	//setting black rooks
	Position forBlackRooks(7, 0);
	this->board[forBlackRooks.getXpos()][forBlackRooks.getYpos()].setPiece(new Rook('b', forBlackRooks));
	forBlackRooks.setXpos(7); 
	forBlackRooks.setYpos(7);
	this->board[forBlackRooks.getXpos()][forBlackRooks.getYpos()].setPiece(new Rook('b', forBlackRooks));

	//******************************************setting knights****************************************************

	//setting white knights
	Position forWhiteKnights(0, 1);
	this->board[forWhiteKnights.getXpos()][forWhiteKnights.getYpos()].setPiece(new Knight('w', forWhiteKnights));
	forWhiteKnights.setXpos(0);
	forWhiteKnights.setYpos(6);
	this->board[forWhiteKnights.getXpos()][forWhiteKnights.getYpos()].setPiece(new Knight('w', forWhiteKnights));

	//setting black knights
	Position forBlackKnights(7, 1);
	this->board[forBlackKnights.getXpos()][forBlackKnights.getYpos()].setPiece(new Knight('b', forBlackKnights));
	forBlackKnights.setXpos(7);
	forBlackKnights.setYpos(6);
	this->board[forBlackKnights.getXpos()][forBlackKnights.getYpos()].setPiece(new Knight('b', forBlackKnights));

	//***********************************************setting bishops****************************************************

	//setting white bishops
	Position forWhiteBishop(0, 2);
	this->board[forWhiteBishop.getXpos()][forWhiteBishop.getYpos()].setPiece(new Bishop('w', forWhiteBishop));
	forWhiteBishop.setXpos(0);
	forWhiteBishop.setYpos(5);
	this->board[forWhiteBishop.getXpos()][forWhiteBishop.getYpos()].setPiece(new Bishop('w', forWhiteBishop));

	//setting black bishops
	Position forBlackBishop(7, 2);
	this->board[forBlackBishop.getXpos()][forBlackBishop.getYpos()].setPiece(new Bishop('b', forBlackBishop));
	forBlackBishop.setXpos(7);
	forBlackBishop.setYpos(5);
	this->board[forBlackBishop.getXpos()][forBlackBishop.getYpos()].setPiece(new Bishop('b', forBlackBishop));

	//***************************************************setting Kings**************************************************

	// setting white king
	Position forWhiteKing(0, 3);
	this->board[forWhiteKing.getXpos()][forWhiteKing.getYpos()].setPiece(new King('w', forWhiteKing));

	//setting black king
	Position forBlackKing(7, 3);
	this->board[forBlackKing.getXpos()][forBlackKing.getYpos()].setPiece(new King('b', forBlackKing));

	//*************************************************setting queens****************************************************

	//setting white queen
	Position forWhiteQueen(0, 4);
	this->board[forWhiteQueen.getXpos()][forWhiteQueen.getYpos()].setPiece(new Queen('w', forWhiteQueen));

	//setting black queen
	Position forBlackQueen(7, 4);
	this->board[forBlackQueen.getXpos()][forBlackQueen.getYpos()].setPiece(new Queen('b', forBlackQueen));

}