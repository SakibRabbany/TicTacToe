#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__

#include <iostream>
#include <vector>
#include <string>


class Piece;

class TextDisplay {
  std::vector<std::vector<char> > theDisplay;	// text display for the grid
  const int gridSize;													// size of the grid
 public:
  TextDisplay();															// ctor
  ~TextDisplay();															// dtor

  void notifyDisplay(const int& r, const int& c, Piece *p);	// notifies theDisplay when a piece is added
  
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);					//output overload, prints the grid
};

#endif
