#pragma once
#include"Position.h"
#include<iostream>
#include<string>
using namespace std;
class Pieces
{
protected:
	string type;
	char color; //b for black and w for white.
	Position position;
public:
	Pieces();
	void draw();
	void setPosition(Position&);
	Position getPosition();
	char getColor() const;
	string getType() const;
	virtual bool validMove(Position&) = 0;
};

