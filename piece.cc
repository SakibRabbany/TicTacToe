#include "piece.h"
#include <string>
#include <iostream>
using namespace std;

Piece::Piece(char type){
	c = type;
}

Piece::~Piece(){}

char Piece::getType(){return c;}
