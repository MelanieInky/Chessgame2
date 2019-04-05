#include "pch.h"
#include "Bishop.h"
#include "Board.h"

Bishop::Bishop() : Piece()
{
}

Bishop::Bishop(int posX, int posY, Color color) : Piece(posX,posY,color)
{

}


Bishop::~Bishop()
{
}

PieceList Bishop::pieceType() const
{
	return LBishop;
}

bool Bishop::ruleCheckMove(int deltaX, int deltaY, Board const & b) const
{
	return checkMoveBishop(deltaX, deltaY, b);
}
