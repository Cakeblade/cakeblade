#include <iostream>

using namespace std;

class Player
{
private:
	int score;
	int findedCards[8];

public:
	Player()
	{
		score = 0;
		for (int i = 0; i < 8; i++)
			findedCards[i] = 0;
	}
	int getScore() { return score; }
	int getfindedCards(int i) { return findedCards[i]; }
	void setScore()
	{
		for (int i = 0; i < 8; i++)
		{
			if (findedCards[i] != 0)
				score++;
			
		}
		if (findedCards[6] == 1) 
			score++;
	}
	void setfindedCards(int i, int n) { findedCards[i] = n; };
};

class Gameboard
{
private:
	int board[4][4];
	int numDatabase[8];
	void resetBasicBoard()
	{
		int n = 1;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				board[i][j] = n;
				board[3 - i][3 - j] = n;
				n++;
			}
		}
	}
	void resetBoard()
	{
		int n;
		for (int i = 0; i < 8; i++)
			numDatabase[i] = 2;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				while (true)
				{
					n = rand() % 8 + 1;
					if (numDatabase[n - 1] != 0)
					{
						board[i][j] = n;
						numDatabase[n - 1] -= 1;
						break;
					}
				}
			}
		}
	}

public:
	Gameboard(int mode)
	{
		switch (mode)
		{
			case 1:
				resetBasicBoard();
				break;
			case 2:
				resetBoard();
				break;
			default:
				break;
		}
	}
	int getPosBoard(int x, int y) { return board[x][y]; }
	void printBoard()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << board[i][j] << " ";
			cout << endl;
		}
	}
};
