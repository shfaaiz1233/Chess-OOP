#pragma once
class Position
{
	int xPosition;
	int yPosition;
public:
	Position(int = {}, int = {});
	void setXpos(int);
	void setYpos(int);
	int getXpos() const;
	int getYpos() const;
};

