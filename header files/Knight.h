#pragma once
#include "Pieces.h"
class Knight :
    public Pieces
{
public:
    Knight(char = {}, Position = {});
    bool validMove(Position&);
};

