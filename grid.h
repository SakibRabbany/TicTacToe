#ifndef __GRID_H__
#define __GRID_H__

#include <vector>
#include <string>

class Piece;
class TextDisplay;

class Grid {
  	
  	std::vector<std::vector<Piece *> > theGrid;			// the actual chess board

  	int gridSize;    									// size of the grid
  	int player; 										// player

  	bool win;
    bool draw;

  	TextDisplay *td; 									// textdisplay
  	
    void changePlayer();                                    // changes the player after every move
    void clearGrid();                                     // clears the board after every game
    void notify(const int& r, const int& c, Piece *p);              // notifies both the displays when a piece is moved
    void winUpdate();
    void drawUpdate();

    bool validPos(const std::string& position);                           // checks if pos is a valid position on the board
    bool pieceExist(const std::string& position);                       // returns true if a piece exists at position
 
  public:
 
    Grid();                                           // ctor
    ~Grid();                                          // dtor
    
  	void init();
    
    bool addPiece(const std::string& position);                   // adds a piece of type t at dest
  	bool getWin();
    bool getDraw();

  	int getPlayer();

  	friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
