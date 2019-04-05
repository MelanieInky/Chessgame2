#pragma once
#include "Piece.h"
#include <iostream>

class Pawn :
	public Piece


{
public:
	Pawn();
	Pawn(int posX, int posY, Color color);
	~Pawn();
	void dispInfo() const;

	virtual bool ruleCheckMove(int deltaX, int deltaY, Board const&  b) const;
	virtual PieceList pieceType() const;

private:
	bool isPassing;


};

