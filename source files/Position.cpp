#include "Position.h"
Position::Position(int x, int y)
{
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	xPosition = x;
	yPosition = y;
}
void Position::setXpos(int x)
{
	xPosition = x;
}
void Position::setYpos(int y)
{
	yPosition = y;
}
int Position::getXpos() const
{
	return xPosition;
}
int Position::getYpos() const
{
	return yPosition;
}