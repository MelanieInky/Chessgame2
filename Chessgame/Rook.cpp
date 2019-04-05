#include "pch.h"
#include "Rook.h"
#include "Board.h"

Rook::Rook() : Piece()
{
}

Rook::Rook(int posX, int posY, Color color) : Piece(posX,posY,color)
{
}


PieceList Rook::pieceType() const
{
	return LRook;
}

bool Rook::ruleCheckMove(int deltaX, int deltaY, Board const & b) const
{
	return checkMoveRook(deltaX, deltaY, b);
}

Rook::~Rook()
{
}
