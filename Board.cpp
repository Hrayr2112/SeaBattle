#include <iostream>
#include "Board.h"
Board::Board() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = empty_field;
		}
	}
}

char * Board::operator[](int i) {
	return board[i];
}

void Board::print() {       // Output table
	std::cout << "    ";
	for (int c = 0; c < N; c++)
	{
		std::cout << c << " ";
	}
	std::cout << "\n\n";
	for (int i = 0; i < N; i++)
	{
		std::cout << i << "   ";
		for (int j = 0; j < N; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool Board::isFree(int x, int y) {
	if (x < 0 || x >= 10 || y < 0 || y >= 10) 
	{
		return false;
	}
	int x1, y1, a[3] = { 0, 1, -1 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			x1 = x + a[i];
			y1 = y + a[j];
			if (x1 >= 0 && x1 < 10 && y1 >= 0 && y1 < 10)
			{
				if (board[x1][y1] != empty_field)
				{
					return false;
				}
			}
		}
	}
	return true;
}
