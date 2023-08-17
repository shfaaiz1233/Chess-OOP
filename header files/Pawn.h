#pragma once
#include "Pieces.h"
class Pawn :
    public Pieces
{
    bool doubleJump;
public:
    Pawn(char = {}, Position = {});
     bool validMove(Position&);
};

