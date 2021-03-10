/*
 * This file implements the Game code.  The game class handles gameplay logic, including 
 * the timing of input events, winning and losing conditions, and certain game state such
 * as the Player's location.
 */
#include "menu.h"
#include <ncurses.h>
#include <string>

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
        void handle_item(WINDOW* mapWindow, WINDOW* menuWindow, int, int, Player&);
        bool prompt(WINDOW* win);

    private:
        Map map;
        Menu menu;
        Player hero;
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


	//strings for win screens/death screens
	char lose_statement  [28]  = "You have run out of energy.";
	char lose_statement_two [43] = "You fall to the ground, unable to move on.";
	char lose_statement_three [69] = " Your corpse's whiffles will be stolen by future travellers.";
	char lose_statement_four [57]  = "Press q to quit, so you may start a new hero's journey.";

	char win_statement [31] =  "You have found all 4 diamonds!";
	char win_statement_two [17] = "Energy: Infinite";
	char win_statement_three [30] = "Whiffles: One Zillion Zillion";
	char win_statement_four [25] =  "Press q to end the game.";
};
