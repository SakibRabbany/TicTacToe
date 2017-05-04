#include <vector>
#include <string>
#include <iostream>

#include "piece.h"
#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(): gridSize(3){
    for (int r = 0 ; r < gridSize ; ++r) {
        vector<char> Col;
        theDisplay.push_back(Col);
        for (int c = 0 ; c < gridSize ; ++c) {
            theDisplay.at(r).push_back(' ');
        }
    }
}

TextDisplay::~TextDisplay(){}	//dtor

void TextDisplay::notifyDisplay(const int& r, const int& c, Piece *p) {
    theDisplay[r][c] = p->getType();
}

ostream &operator<<(ostream &out, const TextDisplay &td){	//output overload, prints the grid
    for (int i = 0 ; i < td.gridSize ; i++){
        for (int j = 0 ; j < td.gridSize ; j++){
            cout << td.theDisplay[i][j];
            if (j == 0 || j == 1) out << '|';
            if (j == 2){
                out << endl;
                if (i == 0 || i == 1){
                    for (int k = 0 ; k < 5 ; k++){
                        out << '-';
                    }
                    out << endl;
                }
            }
        }
    }
    return out;
}
