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
	Board(); 
	char* operator[](int i); 
	void print(); 
	bool isFree(int x, int y); //stuguma navi mas karelia @tex dnel te che, stugelov ira bolor 8 koxmere (diagonalnern el hete)
};

class CommandHandler // Игровые фyнкции для игрока и компьютера 
{
private:
	Board& board;
	Board infoBoard;
	Board enemyBoard;
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
			infoBoard[i][j] = "promax";
			if (enemyBoard[i + 1][j] == occupied_field)
			{
				for (int for_promax = 0; for_promax != count + 2; for_promax++)
				{
					infoBoard[i + for_promax][j + 1] = "promax";
				}
			}
			if (enemyBoard[i - 1][j] == occupied_field)
			{
				for (int for_promax = 0; for_promax != count + 2; for_promax++)
				{
					infoBoard[i - for_promax][j - 1] = "promax";
				}
			}
			if (enemyBoard[i][j - 1] == occupied_field)
			{
				for (int for_promax = 0; for_promax != count + 2; for_promax++)
				{
					infoBoard[i - 1][j - for_promax] = "promax";
				}
			}
			if (enemyBoard[i][j + 1] == occupied_field)
			{
				for (int for_promax = 0; for_promax != count + 2; for_promax++)
				{
					infoBoardd[i + 1][j + for_promax] = "promax";
				}
			}
			count = 0;
		}
		if (i > 0 && i < 10 && j > 0 && j < 10)
		{
			if (enemyBoard[i][j] == "Ship")
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
					cout << "Ship from one deck" << endl;
					count = 0;
				}
				player_hit();
			}
			else if (enemyBoard[i][j] == '0')
			{
				infoBoard[i][j] = "promax";
			}
			else if (infoBoard[i][j] == "promax")
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
	}
	void AI_fill(); 
};

int main()
{
	Board Player_Board, AI_Board;
	CommandHandler Player(Player_Board), AI(AI_Board);
	Player.Player_fill();
	cout << "Finished filling" << endl;
	return 0;
}
