#pragma once

#include <iostream>
#include "enum.h"


class Board;

class Piece
{
public:
	Piece();
	Piece(int posX, int posY, Color color);

	~Piece();
	
	void setPos(int absX, int absY);
	virtual bool ruleCheckMove(int deltaX, int deltaY, Board const&  b) const = 0;
	virtual PieceList pieceType() const = 0;
	Color getColor() const;
private:

	void directMove(int deltaPosX, int deltaPosY); //move the piece without following rules
	void directAbsolutMove(int absPosX, int absPosY); //same shit

protected:
	bool checkMoveRook(int deltaX, int deltaY, Board const& b) const;

	bool checkMoveBishop(int deltaX, int deltaY, Board const& b) const;
	
// Attributes


protected:
	int m_posX;
	int m_posY;
	Color m_color;

};

bool isLegalMove(const Piece & p , int deltaX, int deltaY, Board const& b);

PieceList getPieceName(const Piece & p);