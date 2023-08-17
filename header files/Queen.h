#pragma once
#include "Pieces.h"
class Queen :
    public Pieces
{
public:
    Queen(char = {}, Position = {});
    bool validMove(Position&);
};

