
#include <iostream>
using namespace std;

class Board {
private:
	int player_board[10][10];
	int enemy_board[10][10];
	int board_for_hits[10][10];
public:
	Board();
        int* operator [](int i){
        return board_for_hits[i]
        }
};

class Ship {
private:
public:
        Ship(Board&);
        // Фyнкция размещения кораблей игрока по навправлению и координатам
	void ship_place(int _string, int _column, int ship_size, int direction); 
};

class Shot {
private:
public:
        Shot(Board&); // Отстреливание компьютером
	void hit(Board&, char character, int digit); // Отстреливание игроком
};

int main()
{
	return 0;
}
