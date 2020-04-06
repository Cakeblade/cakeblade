#include <iostream>
#include "classes.cpp"

using namespace std;

int main()
{
	int mode, rawdata1, rawdata2;
	int posX1, posY1, posX2, posY2;
	int cnt = 0;
	int endTrigger = 0;
	int gamedata[8];
	for (int i = 0; i < 8; i++)
		gamedata[i] = 0;
	Player p1, p2;
	cout << "choose game mode" << endl;
	cout << "1. basic" << endl;
	cout << "2. random" << endl;
	cin >> mode;
	Gameboard game(mode);
	//game.printBoard();
	while (endTrigger != 8)
	{
		cout << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (gamedata[game.getPosBoard(i, j) - 1] == 0) cout << 'x'; 
				else cout << game.getPosBoard(i, j);
			}
			cout << endl;
		}
		switch (cnt % 2)
		{
			case 0:
				cout << "PLAYER 1's turn." << endl;
				cin >> rawdata1 >> rawdata2;
				while (rawdata1 == rawdata2)
				{
					cout << "you pick the same position!" << endl;
					cin >> rawdata1 >> rawdata2;
				}
				posX1 = rawdata1 / 10 - 1;
				posY1 = rawdata1 % 10 - 1;
				posX2 = rawdata2 / 10 - 1;
				posY2 = rawdata2 % 10 - 1;
				if (game.getPosBoard(posX1, posY1) == game.getPosBoard(posX2, posY2) && gamedata[game.getPosBoard(posX1, posY1) - 1] == 0)
				{
					gamedata[game.getPosBoard(posX1, posY1) - 1] = 1;
					p1.setfindedCards(game.getPosBoard(posX1, posY1) - 1, 1);
					endTrigger++;
					cout << endl << "correct!" << endl;
				}
				else if (game.getPosBoard(posX1, posY1) == game.getPosBoard(posX2, posY2)) cout << endl << "you cheater!" << endl;
				else cout << endl << "Wrong" << endl;
				break;
			case 1:
				cout << "PLAYER 2's turn." << endl;
				cin >> rawdata1 >> rawdata2;
				while (rawdata1 == rawdata2)
				{
					cout << "you pick the same position!" << endl;
					cin >> rawdata1 >> rawdata2;
				}
				posX1 = rawdata1 / 10 - 1;
				posY1 = rawdata1 % 10 - 1;
				posX2 = rawdata2 / 10 - 1;
				posY2 = rawdata2 % 10 - 1;
				if (game.getPosBoard(posX1, posY1) == game.getPosBoard(posX2, posY2) && gamedata[game.getPosBoard(posX1, posY1) - 1] == 0)
				{
					gamedata[game.getPosBoard(posX1, posY1) - 1] = 1;
					p2.setfindedCards(game.getPosBoard(posX1, posY1) - 1, 1);
					endTrigger++;
					cout << endl << "correct!" << endl;
				}
				else if (game.getPosBoard(posX1, posY1) == game.getPosBoard(posX2, posY2)) cout << endl << "you cheater!" << endl;
				else cout << endl << "Wrong" << endl;
				break;
			default:
				break;
		}
		cnt++;
	}
	p1.setScore();
	p2.setScore();
	if (p1.getScore() > p2.getScore()) cout << "Player 1 WIN!" << endl;
	else if (p1.getScore() < p2.getScore()) cout << "Player 2 WIN!" << endl;
	else cout << "DRAW!" << endl;
} 
