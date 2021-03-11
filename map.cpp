/**
 * This file implements the Map Class and defines a constructor and destructor for a Grovnik.  The map
 * is a 128x128 array of grovniks initialized to be meadow grovniks with no items.  A map.load() function is
 * exposed to allow the parsing of a data file that assigns each grovnik its terrain type and item.
 */
#include <iostream>
#include <ncurses.h>
#include "map.h"
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>

using namespace std;

/**
 * Grovnik Constructor
 */
Grovnik::Grovnik()
{
  terrain = '0';
  object = '\0'; // flag for item type at this grovnik
  visible = false;
  item = NULL; // pointer to object
}

/**
 * Grovnik Destructor 
 */
Grovnik::~Grovnik()
{
  if (item)
  {
    delete item;
    item = NULL;
  }
}

/**
 * Map Constructor
 */
Map::Map()
{
  srand(time(0)); // init random number generator for assigning items
}

/**
 * Map Destructor 
 */
Map::~Map()
{
  unsigned int i;
  // delete food bank
  for (i = 0; i < food_bank.size(); ++i)
  {
    delete food_bank[i];
  }
}

/**
 * Set Debug
 * 
 * If debug is true, then all map tiles are set to visible
 */
void Map::set_debug(bool _debug)
{
  debug = _debug;
}

/**
 * Get Grovnik
 * 
 * @param y:  row coordinate to get
 * @param x:  col coordinate to get
 * @return:  reference to grovnik
 */
Grovnik & Map::mapGetter(int y, int x)
{
  return mapArr[y][x];
}

/**
 * Player Move
 * 
 * Given character, Player, and Player coordinates, adjust coordinates and handle terrain penalties
 * via Player.handle_movement()
 * 
 * @param ch:  input from wgetch (game)
 * @param y:  reference to Player's row coordinate
 * @param x:  reference to Player's col coordinate
 * @param hero:  reference to the Player
 */
void Map::player_move(char ch, int& y, int& x, Player & hero)
{
  switch(ch) 
  {
    // LEFT
    case 'A':
    case 'a':
      if(x > 0)
      {
        if (hero.handle_movement(mapArr[y][x-1].terrain))
        {
          --x;
        }
      }
      break;
    // RIGHT
    case 'D':
    case 'd':
      if(x < 127)
      {
        if (hero.handle_movement(mapArr[y][x+1].terrain))
        {
          ++x;
        }
      }
      break;
    // UP
    case 'W':
    case 'w':
      if(y > 0)
      {
        if (hero.handle_movement(mapArr[y-1][x].terrain))
        {
          --y;
        }
      }
      break;
    // DOWN
    case 'S':
    case 's':
      if(y < 127)
      {
        if (hero.handle_movement(mapArr[y+1][x].terrain))
        {
          ++y;
        }
      }
      break;
  } 
}

/**
 * Map Render
 * 
 * Render the map with terrain and chars given a start row and start col.  Think of start row and start col
 * as the top left corner of the window 'superimposed' on the map array
 * 
 * @param map_window:  ncurses window to render
 * @param start_row:  the top-left corner row of the array to render
 * @param start_col:  the top-left corner col of the array to render
 */
void Map::render(WINDOW * & map_window, int start_row, int start_col)
{
  // Get the window size
  int window_rows = getmaxy(map_window);
  int window_cols = getmaxx(map_window);

  for(int y = 0; y < window_rows; ++y)
  {
    for(int x = 0; x < window_cols; ++x)
    {
      Grovnik & temp = mapArr[y + start_row][x + start_col]; // hold onto Grovnik being processed
	  if(temp.visible || debug == true)
      {
        // render if no object on the tile
        if(temp.object == 'N')
        {
          switch(temp.terrain)
          {
            case '0':
              wattron(map_window, COLOR_PAIR(MEADOW_PAIR));
              mvwaddch(map_window, y, x, ' ');
              wattroff(map_window, COLOR_PAIR(MEADOW_PAIR));
              break;
            case '1':
              wattron(map_window, COLOR_PAIR(WATER_PAIR));
              mvwaddch(map_window, y, x, ' ');
              wattroff(map_window, COLOR_PAIR(WATER_PAIR));
              break;
            case '2':
              wattron(map_window, COLOR_PAIR(SWAMP_PAIR));
              mvwaddch(map_window, y, x, ' ');
              wattroff(map_window, COLOR_PAIR(SWAMP_PAIR));
              break;
            case '3':
              wattron(map_window, COLOR_PAIR(WALL_PAIR));
              mvwaddch(map_window, y, x, ' ');
              wattroff(map_window, COLOR_PAIR(WALL_PAIR));
              break;
          }
        }

        // render diamond tile
        else if(temp.object == 'D')
        {
          switch(temp.object)
          {
            case 'D':
              wattron(map_window, COLOR_PAIR(DIAMOND_PAIR));
              mvwaddch(map_window, y, x, '$');
              wattroff(map_window, COLOR_PAIR(DIAMOND_PAIR));
              break;
          }
        }

        // render any other type of tile
        else
        { 
          switch(temp.terrain)
          {
            case '0':
              wattron(map_window, COLOR_PAIR(MEADOW_PAIR));
              mvwaddch(map_window, y, x, displayObj(temp.object));
              wattroff(map_window, COLOR_PAIR(MEADOW_PAIR));
              break;
            case '1':
              wattron(map_window, COLOR_PAIR(WATER_PAIR));
              mvwaddch(map_window, y, x, displayObj(temp.object));
              wattroff(map_window, COLOR_PAIR(WATER_PAIR));
              break;
            case '2':
              wattron(map_window, COLOR_PAIR(SWAMP_PAIR));
              mvwaddch(map_window, y, x, displayObj(temp.object));
              wattroff(map_window, COLOR_PAIR(SWAMP_PAIR));
              break;
            case '3':
              wattron(map_window, COLOR_PAIR(WALL_PAIR));
              mvwaddch(map_window,y, x, displayObj(temp.object));
              wattroff(map_window, COLOR_PAIR(WALL_PAIR));
              break;
          }
        }
      }

      else //if temp is not visible and debug is false
      {
        wattron(map_window, COLOR_PAIR(EMPTY_PAIR));
        mvwaddch(map_window, y, x, ' ');
        wattroff(map_window, COLOR_PAIR(EMPTY_PAIR));
      }
    }
  }
}

/**
 * Display Object
 * 
 * Basically translates the character contained in grovnik.object to a character to be rendered out to
 * screen.  Helpful for different types of obstacles, for example.
 * 
 * @param object:  object field of current grovnik being rendered
 * @return:  char to render to the screen
 */
char Map::displayObj(char object)
{
  char ret;
  switch(object)
  {
    case '1':
    case '2':
    case '3':
      ret = '?';
      break;

    //Obstacles - both get !
    case 'T':
      ret = '!';
      break;
    case 'R': // Rock, we'll include other obstacles here
      ret = '!';
      break;

    //Tools
     case 'A':
     ret = 'T';
     break;

     case 'P':
     ret = 'T';
     break;

    default:
      ret = object;
      break;
  }
  return ret;
}

/**
 * Map Load
 * 
 * Update the grovnik array with information from the map file
 * 
 * @param playerY:  row of the Player
 * @param playerX:  col of the Player
 * @param mapName:  name of the map file
 * @return:  true if file found and opened, false otherwise
 */
bool Map::load(int& playerY, int& playerX, std::string mapName)
{
  cout << endl;
  char ch;
  int y;
  int x;
  ifstream infile;
  infile.open(mapName);
  if(infile.fail())
    return false;

  // first, get the items
  init_items(infile);

  // assign terrain
  for (y = 0; y < 128; ++y)
  {
    for (x = 0; x < 128; ++x)
    {
      infile.get(ch); // Get single character from file
      mapArr[y][x].terrain = ch;
    }

    infile.ignore(1, '\n');
  }
  cout << endl;

  // ignore newline between grids
  infile.ignore(1, '\n');

  // assign object chars
  for (y = 0; y < 128; y++)
  {
    for (x = 0; x < 128; ++x)
    {
      infile.get(ch);
      mapArr[y][x].object = ch;
      if(ch == '@')
      {
        playerY = y;
        playerX = x;
        mapArr[y][x].object = ' ';
      }
      create_item(y, x, ch); // create item based on char
    }

    infile.ignore(1, '\n');
  }

  infile.close();
  return true;
}

/**
 * Map Output
 * 
 * Used in testing to output the read map to the terminal.  Not used in production, but here for reference.
 */
void Map::output() // For testing purposes: Outputs map
{
  for(int y = 0; y < 128; y++)
  {
    for(int x = 0; x < 128; x++)
    {
      cout << mapArr[y][x].terrain;
    }
    cout << endl;
  }
  cout << endl;

  for(int y = 0; y < 128; y++)
  {
    for(int x = 0; x < 128; x++)
    {
      cout << mapArr[y][x].object;
    }
    cout << endl;
  }
}

/**
 * Update Cursor
 * 
 * Updates the cursor position given the coordinates and map window
 */
void Map::update_cursor(WINDOW * & map_window, int y, int x)
{
  wmove(map_window, y, x);
}

/**
 * Mark Visible
 * 
 * Flips the visibile bools of grovniks in a 3x3 (5x5 if binoculars are available) square around the Player
 * 
 * @param row:  Player's row coordinate
 * @param col:  Player's col coordinate
 * @param hero:  current Player
 */
void Map::mark_visible(int row, int col, Player & hero)
{
  if (hero.has_binoculars())
  {
    for (int i = row - 2; i < row + 3; ++i)
    {
      if (i < 0 || i > 127)
      {
        continue;
      }
      for (int j = col - 2; j < col + 3; ++j)
      {
        if (j < 0 || j > 127)
        {
          continue;
        }
        else
        {
          mapArr[i][j].visible = true;
        }
      }
    }
  }
  else
  {
    for (int i = row - 1; i < row + 2; ++i)
    {
      if (i < 0 || i > 127)
      {
        continue;
      }
      for (int j = col - 1; j < col + 2; ++j)
      {
        if (j < 0 || j > 127)
        {
          continue;
        }
        else
        {
          mapArr[i][j].visible = true;
        }
      }
    }
  }
}

/**
 * Create Item
 * 
 * Create a new item at a Grovnik.  This is done on map file load
 * 
 * @param row: row of grovnik to add item to 
 * @param col:  col of grovnik to add item to
 * @param ch:  char parsed from map file
 */
void Map::create_item(int row, int col, char ch)
{
  switch(ch)
  {
    case 'F':
      mapArr[row][col].item = new Food(*food_bank[rand() % food_bank.size()]);
      break;
    case 'A':
      mapArr[row][col].item = new Axe(100, "Axe", 2);
      break;
    case 'P':
      mapArr[row][col].item = new PickAxe(150, "PickAxe", 2);
      break;
    case 'S':
      mapArr[row][col].item = new Ship(700, "USS Frupal");
      break;
    case 'B':
      mapArr[row][col].item = new Binoculars(500, "Binoculars");
      break;
    case 'T':
      mapArr[row][col].item = new Tree;
      break;
    case 'R':
      mapArr[row][col].item = new Rock;
      break;
  }
}

/**
 * Initialize Items
 * 
 * Parse the name, value, and other attributes of custom items during map.load().  Currently, only food
 * implements this function.  Ideally, this would also occur for tools and obstacles.
 * 
 * @param file:  file being parse for items
 */
void Map::init_items(ifstream & file)
{
  std::vector <std::string> tokens; // hold onto the values of parsed, |-delimited string
  std::string temp; // temporary holder for the current line

  while(getline(file, temp))
  {
    if (temp[0] == '-') // indicates the end of custom item input
    {
      return;
    }
    tokenize(tokens, temp);
    switch(temp[0])
    {
      // create a new food in the food 'bank' to be randomly selected when making a food at a grovnik
      case 'F':
        food_bank.push_back(new Food(std::stoi(tokens[1]), tokens[2], std::stoi(tokens[3])));
        break;
    }
    tokens.clear(); // empty tokens vec
  }
}

/**
 * Tokenize
 * 
 * Helper function to break |-delimited string into tokens to parse.  First turns string into stringstream,
 * then fills the token vector with the delimited strings.
 * 
 * @param tokens:  reference to token vector from init_items
 * @param to_tokenize:  string to break into tokens
 */
void Map::tokenize(std::vector<std::string> & tokens, std::string & to_tokenize)
{
  std::string token;
  std::stringstream stream(to_tokenize);
  while(getline(stream, token, '|'))
  {
    tokens.push_back(token);
  }
}

/**
 * Clear
 * 
 * Simple function that clears the grovnik object char after item used, obstacle cleared, etc.
 * 
 * @param y:  row coordinate of grovnik to clear
 * @param x:  col coordinate of grovnik to clear
 */
void Map::clear(int y, int x)
{
  mapArr[y][x].object = ' ';
}
