#include "pch.h"
#include "King.h"
#include "Board.h"

King::King() : Piece()
{
}

King::King(int posX, int posY, Color color) : Piece(posX,posY,color)
{
}

PieceList King::pieceType() const
{
	return LKing;
}

bool King::ruleCheckMove(int deltaX, int deltaY, Board const & b) const

//TODO : castling
{
	if ((deltaX > -2 && deltaX < 2) && (deltaY > -2 && deltaY < 2))
	{
		if (b.checkIfEmpty(m_posX + deltaX, m_posY+ deltaY)) return true;
		else
		{
			if (b.getPieceColor(m_posX + deltaX, m_posY + deltaY) != m_color)
				return true;
			else
				return false;
		}
	}
	return false;
}


King::~King()
{
}
