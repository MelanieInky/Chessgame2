#include "pch.h"
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "King.h"

Board::Board()
{

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			m_board[i][j] = nullptr;


}


Board::~Board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete m_board[i][j];
		}
	}
}

void Board::clear()
{
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			removePiece(i, j);
}

void Board::initialiseBoard()
{
	clear();
	addPiece(a, 2, LPawn, white);
	addPiece(b, 2, LPawn, white);
	addPiece(c, 2, LPawn, white);
	addPiece(d, 2, LPawn, white);
	addPiece(e, 2, LPawn, white);
	addPiece(f, 2, LPawn, white);
	addPiece(g, 2, LPawn, white);
	addPiece(h, 2, LPawn, white);
	addPiece(a, 1, LRook, white);
	addPiece(b, 1, LKnight, white);
	addPiece(c, 1, LBishop, white);
	addPiece(d, 1, LQueen, white);
	addPiece(e, 1, LKing, white);
	addPiece(f, 1, LBishop, white);
	addPiece(g, 1, LKnight, white);
	addPiece(h, 1, LRook, white);

	addPiece(a, 7, LPawn, black);
	addPiece(b, 7, LPawn, black);
	addPiece(c, 7, LPawn, black);
	addPiece(d, 7, LPawn, black);
	addPiece(e, 7, LPawn, black);
	addPiece(f, 7, LPawn, black);
	addPiece(g, 7, LPawn, black);
	addPiece(h, 7, LPawn, black);
	addPiece(a, 8, LRook, black);
	addPiece(b, 8, LKnight, black);
	addPiece(c, 8, LBishop, black);
	addPiece(d, 8, LQueen, black);
	addPiece(e, 8, LKing, black);
	addPiece(f, 8, LBishop, black);
	addPiece(g, 8, LKnight, black);
	addPiece(h, 8, LRook, black);
}

int Board::addPiece(int posX, int posY, PieceList typeOfPiece, Color color) 
{
	if (posX >= 8 || posY >= 8 || posX < 0 || posY < 0)
	{
		std::cout << "Impossible to put a chess piece outside of the gameboard";
		return 1;
	}

	if (!this->checkIfEmpty(posX, posY))
	{
		std::cout << "This place is already occupied by a piece\n";
		return 2;
	}

	switch (typeOfPiece) {
	case LPawn:
	{
		Piece * newPawn = new Pawn(posX, posY, color);
		m_board[posX][posY] = newPawn;
		break;
	}
	case LRook:
	{
		Piece * newRook = new Rook(posX, posY, color);
		m_board[posX][posY] = newRook;
		break;
	}
	case LKing:
	{
		Piece * newKing = new King(posX, posY, color);
		m_board[posX][posY] = newKing;
		break;
	}
	case LQueen:
	{
		Piece * newQueen = new Queen(posX, posY, color);
		m_board[posX][posY] = newQueen;
		break;
	}
	case LBishop:
	{
		Piece * newBishop = new Bishop(posX, posY, color);
		m_board[posX][posY] = newBishop;
		break;
	}
	case LKnight:
		Piece * newKnight = new Knight(posX, posY, color);
		m_board[posX][posY] = newKnight;
		break;
	}
	return 0;
}

int Board::addPiece(Row row, int column, PieceList typeOfPiece, Color color)
{
	return addPiece((int)row, column-1, typeOfPiece, color);
}

int Board::removePiece(int posX, int posY)
{
	if (posX > 7 || posX < 0 || posY < 0 || posY > 7) return 1;

	delete m_board[posX][posY];
	m_board[posX][posY] = 0;
	return 0;
}

int Board::removePiece(Row row, int column)
{
	return removePiece(row, column - 1);
}

int Board::movePiece(int posX, int posY, int newPosX, int newPosY)
{
	Piece * p_pieceToMove = this->m_board[posX][posY];
	
	if (this->m_board[posX][posY] == 0)
	{
		std::cout << "This piece does not exist";
		return 1;
	}
	if (newPosX >= 8 || newPosY >= 8 || newPosX < 0 || newPosY <0)
	{
		std::cout << "Impossible to move the piece outside the game board\n";
		return 1;
	}
	
	if (isLegalMove(*p_pieceToMove, newPosX - posX, newPosY - posY, *this))
	{
		m_board[posX][posY] = nullptr;
		delete m_board[newPosX][newPosY];
		p_pieceToMove->setPos(newPosX, newPosY);
		m_board[newPosX][newPosY] = p_pieceToMove;
		return 0;
	}
	else
		std::cout << "illegal move\n";
		return 2;

	
}

int Board::movePiece(Row row, int column, Row newRow, int newColumn)
{
	return movePiece((int)row, column - 1, (int)newRow, newColumn -1);
}

bool Board::checkIfEmpty(int posX, int posY) const
{
	return (m_board[posX][posY] == nullptr);
}

Color Board::getPieceColor(int posX, int posY) const
{
	if (checkIfEmpty(posX, posY))
		return white;
	else
		return(m_board[posX][posY]->getColor());
		
}




void Board::display() const
{
	for (int j = 7; j >= 0; j--)
	{
		std::cout << j+1 << "  ";
		for (int i = 0; i < 8; i++)
		{
			std::cout << "|";
			display(i, j);
		}
		std::cout << "|\n";
	}
	std::cout << "    a  b  c  d  e  f  g  h\n\n";

}

void Board::display(int i , int j) const
{
	if (m_board[i][j] == nullptr)
	{
		std::cout << "__";
	}
	else
	{
		if (m_board[i][j]->getColor() == white)
			std::cout << "w";
		else
			std::cout << "b";

		PieceList pieceType = getPieceName(*m_board[i][j]);

		switch (pieceType)
		{
		case LPawn:

			std::cout << "p";
			break;
		case LRook:
			std::cout << "r";
			break;
		case LBishop:
			std::cout << "b";
			break;
		case LQueen:
			std::cout << "q";
			break;
		case LKing:
			std::cout << "k";
			break;
		case LKnight:
			std::cout << "k";
			break;
		default:
			std::cout << "__";
			break;
		}
	}
}

void Board::displayAvailableMoveNaive(int posX, int posY) const
{
	if (m_board[posX][posY] == nullptr)
	{
		std::cout << "can't display available move : piece does not exist\n";
		return;

	}
	for (int j = 7; j >= 0; j--)
	{
		std::cout << j + 1 << "  ";
		for (int i = 0; i < 8; i++)
		{
			std::cout << "|";
			//std::cout << "Checking deltaX : " << i - posX << "and deltaY : " << j - posY << "\n";
			if (isLegalMove(*m_board[posX][posY], i - posX, j - posY, *this))
				//std::cout << "Legal\n";
				std::cout << "xx";
			else
				display(i,j);
			
		}
		std::cout << "|\n";
	}
	std::cout << "    a  b  c  d  e  f  g  h\n\n";

}

void Board::displayAvailableMoveNaive(Row row, int column) const
{
	displayAvailableMoveNaive((int)row, column - 1);
}
