#include "pch.h"
#include "Piece.h"

#include "Board.h"

Piece::Piece()
{
	m_posX = 0;
	m_posY = 0;
	m_color = white;
}

Piece::Piece(int posX, int posY, Color color) : m_posX(posX) , m_posY(posY), m_color(color)
{

}


Piece::~Piece()
{
}


void Piece::setPos(int absX, int absY)
{
	m_posX = absX;
	m_posY = absY;
}

Color Piece::getColor() const
{
	return this->m_color;
}



void Piece::directMove(int deltaPosX, int deltaPosY)
{
	m_posX += deltaPosX;
	m_posY += deltaPosY;

}

void Piece::directAbsolutMove(int absPosX, int absPosY)
{
	m_posX = absPosX;
	m_posY = absPosY;



}

bool Piece::checkMoveRook(int deltaX, int deltaY, Board const & b) const
{
	//deltaX xor deltaY must be 0
	{
		int i;
		if (deltaX != 0 && deltaY != 0)
			return false;
		if (deltaX == 0)
		{
			if (deltaY < 0)
			{
				for (i = -1; i > deltaY; i--)
				{
					//std::cout << "DeltaY < 0 : " << i;
					if (!b.checkIfEmpty(m_posX, m_posY + i)) return false;
					//std::cout << "  Okay\n";
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
					//std::cout << "DeltaY>0 : " << i;
					if (!b.checkIfEmpty(m_posX, m_posY + i)) return false;
					//std::cout << " Okay \n";
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
			//std::cout << "coucouuuuuuu je suis laaaa\n";
			if (deltaX < 0)
			{

				for (i = -1; i > deltaX; i--)
				{
					//std::cout << "deltaX<0" << i;
					if (!b.checkIfEmpty(m_posX + i, m_posY)) return false;
					//std::cout << "  okay\n";
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
				for (i = 1; i < deltaX; i++)
				{
					//std::cout << "deltaX>0 : " << i;
					if (!b.checkIfEmpty(m_posX + i, m_posY)) return false;
					//std::cout << " okay\n";
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
	}
	return false;
}

bool Piece::checkMoveBishop(int deltaX, int deltaY, Board const & b) const
{
	if (deltaX == deltaY)
	{
		int i = 0;
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

	if (deltaX == -deltaY)
	{
		int i = 0;
		if (deltaX < 0)
		{
			for (i = -1; i > deltaX; i--)
			{
				if (!b.checkIfEmpty(m_posX + i, m_posY - i)) return false;
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
				if (!b.checkIfEmpty(m_posX + i, m_posY - i)) return false;
			}
			if (b.checkIfEmpty(m_posX + deltaX, m_posY + deltaY)) return true;
			else
			{
				if (b.getPieceColor(m_posX + deltaX, m_posY + deltaY) != m_color) return true;
				return false;
			}
		}
	}
	return false;
}

bool isLegalMove(const Piece & p, int deltaX, int deltaY, Board const& b)
{
	if (deltaX == 0 && deltaY == 0) return false;

	return(p.ruleCheckMove(deltaX, deltaY, b));
}

PieceList getPieceName(const Piece & p)
{
	return(p.pieceType());
}
