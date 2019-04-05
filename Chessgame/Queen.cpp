#include "pch.h"
#include "Queen.h"


Queen::Queen() : Piece()
{
}

Queen::Queen(int posX, int posY, Color color) : Piece(posX,posY,color)
{
}

PieceList Queen::pieceType() const
{
	return LQueen;
}

bool Queen::ruleCheckMove(int deltaX, int deltaY, Board const & b) const
{
	return(checkMoveBishop(deltaX, deltaY, b) || checkMoveRook(deltaX, deltaY, b));
	/*int i = 0;
	if (deltaX == 0)
	{
		if (deltaY < 0)
		{
			for (i = -1; i > deltaY; i--)
			{
				if (!b.checkIfEmpty(m_posX, m_posY + i)) return false;
			}
			if (b.checkIfEmpty(m_posX, m_posY + deltaY)) return true;
			else
			{
				if (b.getPieceColor(m_posX, m_posY + deltaY) != m_color)
					return true;
				else
					return false;
			}
		}
		if (deltaY > 0)
		{
			for (i = 1; i < deltaY; i++)
			{
				if (!b.checkIfEmpty(m_posX, m_posY + i)) return false;
			}
			if (b.checkIfEmpty(m_posX, m_posY + deltaY)) return true;
			else
			{
				if (b.getPieceColor(m_posX, m_posY + deltaY) != m_color)
					return true;
				else
					return false;
			}
		}

	}

	if (deltaY == 0)
	{
		if (deltaX < 0)
		{
			for (i = -1; i > deltaX; i--)
			{
				if (!b.checkIfEmpty(m_posX + i, m_posY)) return false;
			}
			if (b.checkIfEmpty(m_posX + deltaX, m_posY)) return true;
			else
			{
				if (b.getPieceColor(m_posX + deltaX, m_posY) != m_color)
					return true;
				else
					return false;
			}
		}
		if (deltaX > 0)
		{
			for (i = 1; i > deltaX; i++)
			{
				if (!b.checkIfEmpty(m_posX + i, m_posY)) return false;
			}
			if (b.checkIfEmpty(m_posX + deltaX, m_posY)) return true;
			else
			{
				if (b.getPieceColor(m_posX + deltaX, m_posY) != m_color)
					return true;
				else
					return false;
			}
		}
	}


	if (deltaX == deltaY)
	{
		if (deltaX < 0)
		{
			for (i = -1; i > deltaX; i--)
			{
				if (!b.checkIfEmpty(m_posX + i, m_posY + i)) return false;
			}
			if (b.checkIfEmpty(m_posX + deltaX, m_posY + deltaY)) return true;
			else
			{
				if (b.getPieceColor(m_posX + deltaX, m_posY + deltaY) != m_color) return true;
				return false;
			}
		}
		if (deltaX > 0)
		{
			for (i = 1; i < deltaX; i++)
			{
				if (!b.checkIfEmpty(m_posX + i, m_posY + i)) return false;
			}
			if (b.checkIfEmpty(m_posX + deltaX, m_posY + deltaY)) return true;
			else
			{
				if (b.getPieceColor(m_posX + deltaX, m_posY + deltaY) != m_color) return true;
				return false;
			}
		}
	}

	return false;*/

}


Queen::~Queen()
{
}
