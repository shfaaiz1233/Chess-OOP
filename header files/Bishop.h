#pragma once
#include "Pieces.h"
class Bishop :
    public Pieces
{
public:
    Bishop(char = {}, Position = {});
    bool validMove(Position&);
};

