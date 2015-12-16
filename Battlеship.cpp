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
	Board enemyBoard;
public:
	CommandHandler(Board& b) :
 // qani vor voch initializacvac ssilka chi kareli toxel classi mej, 
 // senc petqa grvi konstruktorum, vore kstana boarde u miangamic klasse sarqelu jamanak initializacni
	board(b) {};				
	void Player_fill();
	void AI_fill(); 
};

int main()
{
	Board Player_Board, AI_Board;
	CommandHandler Player(Player_Board), AI(AI_Board); //iranc sepakan CommandHandlernere
	Player.Player_fill();
	cout << "Finished filling" << endl;
	return 0;
}
