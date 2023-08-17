#include "Pieces.h"
Pieces::Pieces()
{
	type = {};
}
void Pieces::draw()
{
	cout << color << type;
}
void Pieces::setPosition(Position& p)
{
	this->position = p;
}
Position Pieces::getPosition()
{
	return this->position;
}
char Pieces::getColor()const
{
	return color;
}
string Pieces::getType() const
{
	return this->type;
}