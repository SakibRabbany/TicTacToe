#include <string>
#include "piece.h"
#include "grid.h"
#include "textdisplay.h"
#include <vector>
using namespace std;

Grid::Grid(){
    gridSize = 3;
    player = 1;
    win = false;
    draw = false;
    td = NULL;
}

Grid::~Grid(){
    for (int r = 0 ; r < gridSize ; r++) {
        for (int c = 0 ; c < gridSize ; c++) {
            delete theGrid[r][c];
        }
    }
    delete td;
}



void Grid::clearGrid() {
    delete td;
    for(int i = 0 ; i < gridSize; i++){
        theGrid.at(i).clear();
    }
    theGrid.clear();
    draw = false;
    win = false;
    player = 1;
}


void Grid::init() {
    

    td = new TextDisplay();;
    for (int r = 0 ; r < gridSize ; r++) {
        vector<Piece *> Col;
        theGrid.push_back(Col);
        for (int c = 0 ; c < gridSize ; c++) {
            Piece *p = NULL;
            theGrid.at(r).push_back(p);
        }
    }
}

void Grid::changePlayer() {
    if (player == 1) {
        player = 2;
    } else {
        player = 1;
    }
}

void Grid::notify(const int& r, const int& c, Piece *p){
    td->notifyDisplay(r, c, p);
}


bool Grid::validPos(const std::string& position){
    return (position.length() == 2 && '0' <= position[0] && position[0] <= '2' && '0' <= position[1] && position[1] <= '2');
}

bool Grid::pieceExist(const std::string& position) {
    int r = position[0] - '0';
    int c = position[1] - '0';
    if (theGrid[r][c]) {
        return true;
    } else {
        return false;
    }
}


bool Grid::addPiece(const std::string& position){
    if (!validPos(position)) return false;
    if (pieceExist(position)) return false;
    int r = position[0] - '0';
    int c = position[1] - '0';

    Piece * newPiece = NULL;
    char kind;
    
    if (player == 1) {
        kind = 'O';
        newPiece = new Piece(kind);
    } else {
        kind = 'X';
        newPiece = new Piece(kind);
    }
    theGrid[r][c] = newPiece;
    notify(r, c, newPiece);
    winUpdate();
    drawUpdate();
    if (!win) {
        changePlayer();
    }
    return true;
}


void Grid::winUpdate(){
    if (pieceExist("00") && pieceExist("01") && pieceExist("02")
        &&
        theGrid[0][0]->getType() == theGrid[0][1]->getType()
        &&
        theGrid[0][0]->getType() == theGrid[0][2]->getType()){
        win = true;
        return;
    } else if (pieceExist("10") && pieceExist("11") && pieceExist("12")
               &&
               theGrid[1][0]->getType() == theGrid[1][1]->getType()
               &&
               theGrid[1][0]->getType() == theGrid[1][2]->getType()){
        win = true;
        return;
    } else if (pieceExist("20") && pieceExist("21") && pieceExist("22")
               &&
               theGrid[2][0]->getType() == theGrid[2][1]->getType()
               &&
               theGrid[2][0]->getType() == theGrid[2][2]->getType()){
        win = true;
        return;
    } else if (pieceExist("00") && pieceExist("10") && pieceExist("20")
               &&
               theGrid[0][0]->getType() == theGrid[1][0]->getType()
               &&
               theGrid[0][0]->getType() == theGrid[2][0]->getType()){
        win = true;
        return;
    } else if (pieceExist("01") && pieceExist("11") && pieceExist("21")
               &&
               theGrid[0][1]->getType() == theGrid[1][1]->getType()
               &&
               theGrid[0][1]->getType() == theGrid[2][1]->getType()){
        win = true;
        return;
    } else if (pieceExist("02") && pieceExist("12") && pieceExist("22")
               &&
               theGrid[0][2]->getType() == theGrid[1][2]->getType()
               &&
               theGrid[0][2]->getType() == theGrid[2][2]->getType()){
        win = true;
        return;
    } else if (pieceExist("00") && pieceExist("11") && pieceExist("22")
               &&
               theGrid[0][0]->getType() == theGrid[1][1]->getType()
               &&
               theGrid[0][0]->getType() == theGrid[2][2]->getType()){
        win = true;
        return;	
    } else if (pieceExist("20") && pieceExist("11") && pieceExist("02")
               &&
               theGrid[2][0]->getType() == theGrid[1][1]->getType()
               &&
               theGrid[2][0]->getType() == theGrid[0][2]->getType()){
        win = true;
        return;	
    } 
}

void Grid::drawUpdate(){
    draw = true;
    for(int r = 0 ; r < gridSize ; r++){
        for (int c = 0 ; c < gridSize ; c++){
            if (!theGrid[r][c]){
                draw = false;
                return;
            }
        }
    }
}

int Grid::getPlayer(){return player;}

bool Grid::getWin(){return win;}

bool Grid::getDraw(){return draw;}

ostream &operator<<(ostream &out, const Grid &g) {
    out << *(g.td);
    return out;
}


