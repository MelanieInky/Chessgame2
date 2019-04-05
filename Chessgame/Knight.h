#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
public:

	Knight();	
	Knight(int posX, int posY, Color color);

	~Knight();


	virtual PieceList pieceType() const;
	virtual bool ruleCheckMove(int deltaX, int deltaY, Board const&  b) const;


};

