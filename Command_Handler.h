#pragma once
#include <fstream>
#include "Board.h"
using namespace std;
class CommandHandler // Игровые фyнкции для игрока и компьютера 
{
private:
	Board& board;
	Board infoBoard;
	Board enemyBoard;
	bool try_to_place(int x0, int y0, int x1, int y1, int size, ostream& out);
public:
	// qani vor voch initializacvac ssilka chi kareli toxel classi mej, 
	// senc petqa grvi konstruktorum, vore kstana boarde u miangamic klasse sarqelu jamanak initializacni
	CommandHandler(Board& b) : board(b) {};
	void Player_fill(Board& enemyBoard);
	void AI_move(Board& enemyBoard);
};
