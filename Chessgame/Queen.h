#pragma once
#include "Piece.h"
#include "Board.h"

class Queen :
	public Piece
{
public:
	Queen();
	Queen(int posX, int posY, Color color);

	virtual PieceList pieceType() const;
	virtual bool ruleCheckMove(int deltaX, int deltaY, Board const&  b) const;


	~Queen();
};

