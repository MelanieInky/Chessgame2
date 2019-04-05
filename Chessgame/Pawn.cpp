#include "pch.h"
#include "Pawn.h"
#include "Board.h"

Pawn::Pawn() : Piece(), isPassing(false)
{
}

Pawn::Pawn(int posX, int posY, Color color) : Piece(posX,posY, color) , isPassing(false)
{

}



Pawn::~Pawn()
{
}

void Pawn::dispInfo() const
{
	std::cout << "This pawn is in position (" << m_posX << "," << m_posY << ")\n";
}



bool Pawn::ruleCheckMove(int deltaX, int deltaY, Board const& b) const
//TODO : avancer, prendre, prise en passant, double avancer
//Mouvement possible, y+-1 et x+0, x+-1 et y+1, x+-1 et y-1
{

	int deltaYmod; //if black, reverse the chessboard to check the move
	if (m_color == black) deltaYmod = -deltaY;
	else deltaYmod = deltaY;

	if (deltaYmod == 1)
	{
		if (deltaX == 0)
			return(b.checkIfEmpty(m_posX + deltaX, m_posY + deltaY));
		if (deltaX == 1 || deltaX == -1) //TODO, prise en passant
		{
			if (!b.checkIfEmpty(m_posX + deltaX, m_posY + deltaY))
			{
				return(this->m_color != b.getPieceColor(m_posX + deltaX, m_posY + deltaY));
			}
		}
	}

	if (deltaYmod == 2 && deltaX == 0)
	{
		if (m_posY == 1 || m_posY == 6)
		{
			if (m_color == black)
				return(b.checkIfEmpty(m_posX + deltaX, m_posY + deltaY) && b.checkIfEmpty(m_posX + deltaX, m_posY + deltaY + 1));
			else
				return(b.checkIfEmpty(m_posX + deltaX, m_posY + deltaY) && b.checkIfEmpty(m_posX + deltaX, m_posY + deltaY - 1));
		}
	}

	return false;
}

PieceList Pawn::pieceType() const
{
	return LPawn;
}



