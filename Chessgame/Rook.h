#pragma once
#include "Piece.h"
#include <algorithm>
class Rook :
	public Piece
{
public:
	Rook();
	Rook(int posX, int posY, Color color);


	virtual PieceList pieceType() const;
	virtual bool ruleCheckMove(int deltaX, int deltaY, Board const&  b) const;

	~Rook();
};

