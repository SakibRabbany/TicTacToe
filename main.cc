#include "grid.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	Grid grid;
	grid.init();
	cout << "welcome to TicTacToe" << endl;
    string Message = "How to play: enter coordinate of the position you want to place 00 ... 22";
    cout << Message << endl;

	while (true) {
		cout << grid;
		cout << "Player " << grid.getPlayer() << " turn" << endl;
		string coord;
		cin >> coord;
		if (grid.addPiece(coord)) {
			if (grid.getWin()) {
				cout << grid;
				cout << "Player " << grid.getPlayer() << " wins" << endl;
				break;
			} else if (grid.getDraw()){
				cout << grid;
				cout << "Draw" << endl;
				break;
			}
		} else {
			cout << "invalid position" << endl;
			continue;
		}
	}
}
