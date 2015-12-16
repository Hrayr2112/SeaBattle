#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
using namespace std;
const int N = 10; //vor amen angam 10 chgrenq
const char empty_field = '0'; 
const char occupied_field = '1';
const char destroyed_field = '2'; // ete uzenanq poxenq nshanakumnere, es const charerov hesht klni
class Board
{
private:
	char board[N][N]; //matrican, vortex tvyal Board-e pahelu a informacian, 10x10 chapi
public:
	Board(); //konstruktor, default-nerov klni sax empty_field
	char* operator[](int i); // operator [] vor ete unenanq Board a; karenanq grenq a[i][j]
	void print(); //tpuma matrican
	bool isFree(int x, int y); //stuguma navi mas karelia @tex dnel te che, stugelov ira bolor 8 koxmere (diagonalnern el hete)
};

class CommandHandler //ham xaxacoxe ham kompe kunena es klassic, stex linelu en funckianere, 
{
private:
	Board& board; //uni Board-i ssilka, vortex pahelu a tvyal xaxacoxi boarde;
	Board enemyBoard; // mi hat el board inqna stexcum, vor meje pahi ira unecac informacian hakarakordi boardi masin
public:
	CommandHandler(Board& b) :
		board(b) {} // qani vor voch initializacvac ssilka chi kareli toxel classi mej, 
					//senc petqa grvi konstruktorum, vore kstana boarde u miangamic klasse sarqelu jamanak initializacni
	void Player_fill(); //boardi mej (klassum` Board& board) meje lcnuma navere, xaxacoxi hamar, cinnerov
	void AI_fill(); // nuynpes lcnuma meje, funkcian kompi lcnelu hamara, randomnerov
};

int main()
{
	Board Player_Board, AI_Board; //ham kompe ham xaxacoxe kunena iranc sepakan Board-ere
	CommandHandler Player(Player_Board), AI(AI_Board); //u iranc sepakan CommandHandlernere
	Player.Player_fill(); // funkcianeri kanchi dzeve
	cout << "Finished filling\n";
	return 0;
}
