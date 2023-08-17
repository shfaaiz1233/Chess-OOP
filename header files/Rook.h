#pragma once
#include "Pieces.h"
class Rook :
    public Pieces
{
public:
    Rook(char = {}, Position={});
    bool validMove(Position&);
};

