#pragma once
#include "Piece.h"

class King : 
	public Piece
{
public:
	King();
	King(int posX, int posY, Color color);

	virtual PieceList pieceType() const;
	virtual bool ruleCheckMove(int deltaX, int deltaY, Board const&  b) const;

	~King();
};

