/*
 * This is the header file for the map class.  A map contains the 128x128 grovnik array and is also
 * responsible for manipulating the window to render the current state of the map.  It also contains a
 * food_bank, which is a way of storing user-defined food items to be randomly added when a food grovnik
 * is parsed from the file.
 */
#pragma once
#include <ncurses.h>
#include "player.h"
#include "item.h"
#include "grovnik.h"
#include <vector>
#include <fstream>

// define the color pairs to render on map
#define WATER_PAIR   1
#define SWAMP_PAIR   2
#define WALL_PAIR    3
#define EMPTY_PAIR   4
#define PLAYER_PAIR  5
#define DIAMOND_PAIR 6
#define MEADOW_PAIR  7


class Map // Map class, contains data for map and objects displayed on it
{
  private:
    Grovnik mapArr[128][128];
    bool debug;
    std::vector <Food *> food_bank;

  public:
    Map();
    ~Map();
    bool load(int&, int&, std::string);
    void output();
    void update(WINDOW * & map_window, int ch, int& y, int& x, player hero);
    void update_cursor(WINDOW * & map_window, int y, int x);
    void render(WINDOW * & map_window, int start_row, int start_col);
    Grovnik & mapGetter(int, int);
    void player_move(char, int &, int &, player &);
    void set_debug(bool);
    void mark_visible(int, int, player &);
    void create_item(int, int, char);
    void init_items(std::ifstream &);
    void tokenize(std::vector<std::string> &, std::string &);
    void clear(int, int);
    char displayObj(char);
};
