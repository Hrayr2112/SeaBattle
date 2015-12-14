# SeaBattle
SeaBattle is a university OOP course project which should be completed until the end of semester by the group of students consists of three. More detailed information can be found in ProjectDescription.txt.

#include <iostream>
#include <string>
using namespace std;

class Board {
private:
	int player_board[10][10];
	int enemy_board[10][10];
	int board_for_hits[10][10];
public:
	Board();
};

class Ship {
private:
public:
	void ship_place(int _string, int _column, int ship_size, int direction); // Фyнкция размещения кораблей игрока по навправлению и координатам 
};

class Shot {
private:
public:
	void hit(Board&, char character, int digit); // Отстреливание игроком
	void hit_PC(Board&); // Отстреливание компьютером
};

int main()
{
	return 0;
}
