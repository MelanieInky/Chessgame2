#pragma once

#include <vector>
#include <iostream>
#include "enum.h"


class Piece;

class Board
{
public:
	Board();
	~Board();
	void clear();
	void initialiseBoard();

	int addPiece(int posX, int posY, PieceList typeOfPiece, Color color);
	int addPiece(Row row, int column, PieceList typeOfPiece, Color color);
	int removePiece(int posX, int posY);
	int removePiece(Row row, int column);
	int movePiece(int posX, int posY, int newPosX, int newPosY);
	int movePiece(Row row, int column, Row newRow, int newColumn);
	bool checkIfEmpty(int posX, int posY) const;
	Color getPieceColor(int posX, int posY) const;

	
	void displayAvailableMoveNaive(int posX, int posY) const;
	void displayAvailableMoveNaive(Row row, int column) const;

	void display() const;


private  : void display(int i, int j) const;




private:

	Piece* m_board[8][8];

	//std::vector < std::vector < Piece >> m_board;

};



