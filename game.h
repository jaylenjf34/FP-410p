/*
 * This file implements the Game code.  The game class handles gameplay logic, including 
 * the timing of input events, winning and losing conditions, and certain game state such
 * as the player's location.
 */
#include "menu.h"
#include <ncurses.h>

//CONSTANTS
const char OBSTACLE = '!';
const int OBSTACLEENERGY = 10;
const int TREASUREVALUE = 500;
const int MEADOWENERGY = 1;
const int SWAMPENERGY = 2;
const char NOTHING = 'N';
const char CLUE = '?';
const char TREASURE  = '$';
const int WATER = 1;
const int SWAMP = 2;
const int WALL = 3;



class Game
{
    public:
        Game();
        ~Game();
        void init(); 
        void play(bool); 
        void render_player(WINDOW * &, int, int);
        void handle_item(WINDOW* mapWindow, WINDOW* menuWindow, int, int, player&);
        bool prompt(WINDOW* win);

    private:
        Map map;
        Menu menu;
        player hero;
	    Grovnik curGrov;

        // CURSOR
        int cursorRow; // position of cursor on map window [0, LINES]
        int cursorCol; // position of cursor on map window [0, COLS - 20]

        // MAP SIZE - LINES lines, COL - 20 cols
        int mapWindowRows; 
        int mapWindowCols;

        // MAP WINDOW POSITION
        // top left corner of window "superimposed" on mapArray
        int mapRow;
        int mapCol;
};
