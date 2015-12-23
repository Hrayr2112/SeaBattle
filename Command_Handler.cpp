#include <iostream>
#include "Command_Handler.h"
#include "Board.h"
bool CommandHandler::try_to_place(int x0, int y0, int x1, int y1, int size, ostream & out) {
		while (true) {
		if (x0 > 9 || y0 > 9 || x1 > 9 || y1 > 9)
		{
			out << "\nTry to place your ship INSIDE the board";
			return false;
		}
		if (x0 == x1)
		{
			if (y1 - y0 != size - 1)
			{
				out << "\nThis should be a ";
				out << size;
				out << "-decker ship, try again";
				return false;
			}
			for (int j = y0; j <= y1; j++)
			{
				if (!board.isFree(x0, j))
				{
					out << "\nKeep distance betwwen the ships!";
					return false;
				}
			}
			for (int j = y0; j <= y1; j++)
			{
				board[x0][j] = occupied_field;
			}
		}
		else if (y0 == y1)
		{
			if (x1 - x0 != size - 1)
			{
				out << "\nThis should be a ";
				out << size;
				out << "-decker ship, try again";
				return false;
			}
			for (int i = x0; i <= x1; i++)
			{
				if (!board.isFree(i, y0))
				{
					out << "\nKeep distance betwwen the ships!";
					return false;
				}
			}
			for (int i = x0; i <= x1; i++)
			{
				board[i][y0] = occupied_field;
			}
		}
		else
		{
			out << "\nYour ship has to be straight, try again";
			return false;
		}
		return true;
	}
}

void CommandHandler::Player_fill(Board& enemyBoard) {
	int i, j, deck_2 = 3, deck_3 = 2, deck_4 = 1;
	static int count = 0;
	cin >> i >> j;
	if (count >= 2 && enemyBoard[i][j] == '0')
	{
		if (count == 2)
		{
			deck_2 -= 1;
		}
		if (count == 3)
		{
			deck_3 -= 1;
		}
		if (count == 4)
		{
			deck_4 -= 1;
		}
		infoBoard[i][j] = 'M';
		if (enemyBoard[i + 1][j] == occupied_field)
		{
			for (int for_miss = 0; for_miss != count + 2; for_miss++)
			{
				infoBoard[i + for_miss][j + 1] = 'M';
			}
		}
		if (enemyBoard[i - 1][j] == occupied_field)
		{
			for (int for_miss = 0; for_miss != count + 2; for_miss++)
			{
				infoBoard[i - for_miss][j - 1] = 'M';
			}
		}
		if (enemyBoard[i][j - 1] == occupied_field)
		{
			for (int for_miss = 0; for_miss != count + 2; for_miss++)
			{
				infoBoard[i - 1][j - for_miss] = 'M';
			}
		}
		if (enemyBoard[i][j + 1] == occupied_field)
		{
			for (int for_miss = 0; for_miss != count + 2; for_miss++)
			{
				infoBoard[i + 1][j + for_miss] = 'M';
			}
		}
		count = 0;
	}
	if (i > 0 && i < 10 && j > 0 && j < 10)
	{
		if (enemyBoard[i][j] == 'S')
		{
			count++;
			infoBoard[i][j] = occupied_field;
			if (count == 4)
			{
				cout << "The biggest ship!" << endl;
				count = 0;
			}
			if (count == 1 && deck_2 == 0 && deck_3 == 0 && deck_4 == 0)
			{
				cout << "Ship with one deck" << endl;
				count = 0;
			}
			Player_fill(enemyBoard);
		}
		else if (enemyBoard[i][j] == empty_field)
		{
			infoBoard[i][j] = 'M';
		}
		else if (infoBoard[i][j] == 'M')
		{
			cout << "Repeat your turn please" << endl;
			Player_fill(enemyBoard);
		}
	}
	else
	{
		cout << "Incorrect coordinates" << endl;
	}
}

void CommandHandler::AI_move(Board & enemyBoard)
{
}
