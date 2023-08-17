#include"chessBoard.h"
chessBoard board;
void convertLower(char& a)
{
	if (a >= 'A' && a <= 'Z')
		a += 32;
}
void check_win(bool& check_for_black, bool& check_for_white)
{
	Position temp;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			temp.setXpos(i);
			temp.setYpos(j);
			if (board.getPiece(temp) != nullptr)
			{
				if (board.getPiece(temp)->getType() == "K")
				{
					if (board.getPiece(temp)->getColor() == 'w')
						check_for_white = true;
					else if (board.getPiece(temp)->getColor() == 'b')
						check_for_black = true;
				}
			}
		}
	}
}
int main()
{
	char col = 0;
	int row = 0;
	char color = 'w';
	int qh = 0;
	bool check_for_black = false, check_for_white = false;
	while (true)
	{
		check_for_black = false;
		check_for_white = false;
		board.draw();
		check_win(check_for_black, check_for_white);
		if (!check_for_black)
		{
			cout << "Black king captured.\n";
			cout << "White player won.\n";
			break;
		}
		else if (!check_for_white)
		{
			cout << "White King captured.\n";
			cout << "Black player won.\n";
			break;
		}
		cout << "Press 1 for help.\n";
		cout << "Press 2 to quit.\n";
		cout << "Press any number other tha 1 and 2 to continue.\n";
		cin >> qh;
		if (qh == 2)
		{
			cout << "Exited.\n";
			break;
		}
		else if (qh == 1)
		{
			cout << "Enter position like a1, b2 ,b3.(alphabets for columns and numbers for rows)\n";
			cout << "Pawn can move 2(or)1 box forward on its first move otherwise only 1 box per move. It captures other piece in diagonal.\n";
			cout << "Bishop can move diagonally anywhere on the board.\n";
			cout << "Rook can move in a plus shape i.e Straight in vertical and staright in diagonal.\n";
			cout << "Knight can move in L shape and can jump one box.\n";
			cout << "King can move anywhere on the board, but only one box.\n";
			cout << "Queen can move anywhere on the board diagonally,straight in both forward and backward directions.\n";
			continue;
		}
		if (color == 'w')
			cout << "White's turn.\n";
		else
			cout << "Black's turn.\n";
		cout << "Enter position: ";
		cin >> col>>row;
		convertLower(col);
		Position p(row - 1, int(col)-97);
		if (board.getPiece(p) == nullptr)
		{
			cout << "Invalid select.\n";
			continue;
		}
		else if (board.getPiece(p)!=nullptr&&board.getPiece(p)->getColor() != color)
		{
			cout << "Wrong color piece selected.\nTry again.\n";
			continue;
		}
		cout << "Now enter destination: ";
		cin >> col >> row;
		convertLower(col);
		Position d(row - 1, int(col) - 97);
		bool moved = board.movePiece(p, d);
		if (moved) {
			cout << "Success\n";
			board.draw();
			if (color == 'w')
				color = 'b';
			else
				color = 'w';
		}
		else
			cout << "Invalid.\n";
		system("cls");
	}
}