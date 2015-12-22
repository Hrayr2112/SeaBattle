#include <iostream>
#include "Board.h"
#include "Command_Handler.h"
using namespace std;
int main()
{
	Board Player_Board, AI_Board;
	CommandHandler Player(Player_Board), AI(AI_Board);
	Player.Player_fill(Player_Board);
	cout << "Finished filling" << endl;
	return 0;
}
