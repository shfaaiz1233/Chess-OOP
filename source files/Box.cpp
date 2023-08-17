#include "Box.h"
Box::Box(Pieces* p)
{
	chessPiece = p;
}
void Box::setPiece(Pieces* p)
{
	chessPiece = p;
}
Pieces* Box::getPiece()const
{
	return chessPiece;
}
void Box::clear()
{
	chessPiece = nullptr;
}
