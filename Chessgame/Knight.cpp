#include "pch.h"
#include "Knight.h"
#include "Board.h"

Knight::Knight() : Piece()
{
}

Knight::Knight(int posX, int posY, Color color) : Piece(posX,posY,color)
{
}


Knight::~Knight()
{
}

PieceList Knight::pieceType() const
{
	return LKnight;
}

bool Knight::ruleCheckMove(int deltaX, int deltaY, Board const & b) const
{
	bool test = (deltaX == 1 && deltaY == 2) || 
				(deltaX == 2 && deltaY == 1) || 
				(deltaX == -1 && deltaY == -2) || 
				(deltaX == -2 && deltaY == -1) || 
				(deltaX == 2 && deltaY == -1) || 
				(deltaX == 1 && deltaY == -2) || 
				(deltaX == -1 && deltaY == 2) || 
				(deltaX == -2 && deltaY == 1);
	
	if (test)
	{
		if(b.checkIfEmpty(m_posX+deltaX, m_posY + deltaY)) return true;
		else
		{
			return(b.getPieceColor(m_posX + deltaX, m_posY + deltaY) != m_color);
		}
	}
	
	return false;

}
