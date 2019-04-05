// Chessgame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

#include "Board.h"
#include "Pawn.h"
#include "gameFunction.h"


int main()
{

	Board myBoard;

	/*myBoard.addPiece(d, 6, LQueen, white);
	myBoard.addPiece(b, 2, LPawn, white);
	myBoard.addPiece(2, 2, LPawn, black);
	myBoard.addPiece(5, 6, LPawn, black);
	myBoard.addPiece(3, 3, LRook, white);
	myBoard.addPiece(7, 7, LBishop, white);
	myBoard.movePiece(7, 7, 4, 4);
	myBoard.display();

	myBoard.movePiece(1, 1, 2, 2);

	myBoard.display();

	myBoard.movePiece(2, 2, 2, 3);

	myBoard.display();

	myBoard.movePiece(2, 3, 2, 5);
	myBoard.display();

	myBoard.movePiece(5, 6, 5, 4);

	myBoard.display();
	myBoard.movePiece(3, 3, 5, 3);
	myBoard.display();
	myBoard.movePiece(5, 3, 5, 4);
	myBoard.display();

	myBoard.movePiece(5, 4, 5, 3);
	myBoard.display();
	myBoard.movePiece(5, 3, 3, 3);
	myBoard.display();

	myBoard.displayAvailableMoveNaive(3, 3);
	myBoard.displayAvailableMoveNaive(2, 3);*/

	/*
	myBoard.addPiece(d, 4, LPawn, black);
	myBoard.display();
	//myBoard.displayAvailableMoveNaive(d, 4);
	myBoard.addPiece(b, 2, LPawn, black);
	//myBoard.displayAvailableMoveNaive(b, 2);

	myBoard.addPiece(e, 3, LQueen, white);
	//myBoard.displayAvailableMoveNaive(e, 3);
	myBoard.addPiece(c, 5, LBishop, white);

	myBoard.addPiece(c, 3, LRook, white);
	myBoard.display();
	myBoard.displayAvailableMoveNaive(c, 3);

	myBoard.displayAvailableMoveNaive(e, 3);

	myBoard.displayAvailableMoveNaive(c, 5);

	myBoard.addPiece(c, 4, LKnight, white);
	myBoard.display();

	myBoard.displayAvailableMoveNaive(c, 4);

	myBoard.addPiece(b, 3, LKing, white);
	myBoard.display();
	myBoard.displayAvailableMoveNaive(b, 3);

	*/

	myBoard.initialiseBoard();
	myBoard.display();

	std::string Srow;
	std::string NewSRow;
	int column;
	Row row;
	int newColumn;
	Row newRow;

	while (true)
	{
		std::cout << "enter a row\n";
		std::cin >> Srow;
		row = stringToRow(Srow);
		
		std::cout << "enter a column\n";
		std::cin >> column;



		myBoard.displayAvailableMoveNaive(row, column);

		std::cout << "enter a destination row\n";
		std::cin >> NewSRow;
		newRow = stringToRow(NewSRow);
		std::cout << "you have chosen row : " << newRow + 1 << std::endl;
		std::cout << "enter a destination column\n";
		std::cin >> newColumn;
		std::cout << "you have chosen column : " << newColumn << std::endl;

		myBoard.movePiece(row, column, newRow, newColumn);
		myBoard.display();


	}

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
