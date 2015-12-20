#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
using namespace std;
const int N = 10;
const char empty_field = '0'; 
const char occupied_field = '1';
const char destroyed_field = '2';
class Board
{
private:
	char board[N][N];
public:
	Board()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				board[i][j] = empty_field;
			}
		}
	char* operator[](int i)
        {
             return board[i];
        }
	void print()
	{
		cout << "    ";
		for (int c = 0; c < N; c++)
		{
			cout << c << " ";
		}
		cout << "\n\n";
		for (int i = 0; i < N; i++)
		{
			cout << i << "   ";
			for (int j = 0; j < N; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
        //stuguma navi mas karelia @tex dnel te che, stugelov ira bolor 8 koxmere (diagonalnern el hete)
	bool isFree(int x, int y)
	{
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
};

class CommandHandler // Игровые фyнкции для игрока и компьютера 
{
private:
	Board& board;
	Board infoBoard;
	Board enemyBoard;
        bool try_to_place (int x0, int y0, int x1, int y1, int size, ostream& out) 
	{
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
public:
     // qani vor voch initializacvac ssilka chi kareli toxel classi mej, 
     // senc petqa grvi konstruktorum, vore kstana boarde u miangamic klasse sarqelu jamanak initializacni
	CommandHandler(Board& b) :
	board(b) {};				
	void Player_fill(Board& enemyBoard)
	{
		int i, j, deck_2 = 3, deck_3 = 2, deck_4 = 1;
		static int count = 0;
		cin >> i >> j;
		if (count >= 2 && enemyBoard[i][j] == '0')
		{
			if(count == 2)
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
					infoBoardd[i + 1][j + for_promax] = 'M';
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
				player_hit();
			}
			else if (enemyBoard[i][j] == '0')
			{
				infoBoard[i][j] = 'M';
			}
			else if (infoBoard[i][j] == 'M')
			{
				cout << "Repeat your turn please" << endl;
				player_hit();
			}
		}
		else
		{
			cout << "Incorrect coordinates" << endl;
		}
	}
        void AI_fill()
	{
		int x0, y0, x1, y1;
		auto place = [&](int size) {
			board.print();
			do
			{
				x0 = rand() % (N - size);
				y0 = rand() % (N - size);
				if (rand() % 2 == 0)
				{
					x1 = x0;
					y1 = y0 + size - 1;
				}
				else
				{
					y1 = y0;
					x1 = x0 + size - 1;
				}
			} while (try_to_place(x0, y0, x1, y1, size, cout) == false);
		};
		place(4);
		for (int i = 3; i > 0; i--)
			for (int k = 0; k < 5 - i; k++) 
				place(i);
	}
};

int main()
{
	Board Player_Board, AI_Board;
	CommandHandler Player(Player_Board), AI(AI_Board);
	Player.Player_fill();
	cout << "Finished filling" << endl;
	return 0;
}
