#pragma once
#include "Pieces.h"
class King :
    public Pieces
{
public:
    King(char = {}, Position = {});
    bool validMove(Position&);
};

