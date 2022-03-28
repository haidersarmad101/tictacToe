#include <iostream>
#include <cstdlib>
using namespace std;
#define GREEN   "\033[32m" 

string B[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void clear_screen() {
  #ifdef _WIN32
    system("cls");
  #else
    system ("clear");
  #endif
}

int checkWin() {
	for (int i = 0, j = 0; i < 3; i++, j += 3) 
		if (B[i + 1] == B[i + 4] && B[i + 4] == B[i + 7] || B[j + 1] == B[j + 2] && B[j + 2] == B[j + 3]) 
			return 1;
	if (B[1] == B[5] && B[5] == B[9] || B[3] == B[5] && B[5] == B[7])
		return 1;
	for (int i = 1; i <= 9; i++) 
		if (B[i] == string(1, '0' + i)) return -1;
	return 0;
}

void displayBoard() {
  clear_screen();
	cout << "\n\n\tTic Tac Toe\n\n\033[32mPlayer 1 (X)\033[0m  -  \033[35mPlayer 2 (O)\n\n\033[0m";
	cout << "    _________________\n";
	for (int i = 0; i < 9; i += 3) {
		cout << "   |     |     |     |\n";
		cout << "   |  " << B[i + 1] << "  |  " << B[i + 2] << "  |  " << B[i + 3] << "  |\n";
		cout << "   |_____|_____|_____|\n";
	}
	cout << "\n\n";
}

int main() {
	int player = 1, x, choice;
	string color[] = {"\033[32m", "\033[35m"};
	string mark;
	do {
		displayBoard();
		player = 1 - player;
		cout << color[player]  << "Player " << player + 1 << ": \033[0m";
		cin >> choice;
		mark = player ? "\033[35mO\033[0m" : "\033[32mX\033[0m";
		if (B[choice] == string(1, '0' + choice))
			B[choice] = mark;
		else {
			cout << "Invalid move ";
      player = 1 - player;
			cin.ignore();
			cin.get();
			continue;
		}
		x = checkWin();
	} while (x == -1);
	displayBoard();
	x ? cout << color[player]  << "Player " << player + 1 << "\033[0m" << " wins! " : cout << "Draw";
	cin.ignore();
	cin.get();
	return 0;
}