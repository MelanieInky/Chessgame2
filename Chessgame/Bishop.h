#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop();
	Bishop(int posX, int posY, Color color);

	~Bishop();
	virtual PieceList pieceType() const;
	virtual bool ruleCheckMove(int deltaX, int deltaY, Board const& b) const;

};

