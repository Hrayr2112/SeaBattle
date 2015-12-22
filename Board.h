#pragma once
const int N = 10;
const char empty_field = '0';
const char occupied_field = '1';
const char destroyed_field = '2';
class Board {
private:
	char board[N][N];
public:
	Board();
	char* operator[](int i);
	void print();
	//stuguma navi mas karelia @tex dnel te che, stugelov ira bolor 8 koxmere (diagonalnern el hete)
	bool isFree(int x, int y);
};
