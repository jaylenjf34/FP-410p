/*
 * This file is the driver code for the Frupal program.  It initializes the Game object and parses command
 * line parameters to set the map in debug mode.  In debug mode, the entire map is immediately visible.
 */
#include "game.h"
#include <string.h>

int main(int argc, char* argv[])
{ 
  bool debug;

  if (argc == 2 && (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--debug") == 0))
  {
    debug = true;
  }
  else
  {
    debug = false;
  }
  
  Game game;
  game.play(debug);
  return 0;
}
