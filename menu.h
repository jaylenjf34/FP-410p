#ifndef MENU_H
#define MENU_H

#include <ncurses.h>
#include "player.h"
#include "map.h"
#include "item.h"

class Menu
{
  private:
    int size = 20;
    Grovnik* curgrov;
    Player* myPlayer;

  public:
    Menu();
    
    bool update(Grovnik* grov, Player* p);
    void render(WINDOW* win);
    void readgrov(WINDOW* win);
    void prompt_buy(WINDOW* win, Item* item);
    void prompt_use(WINDOW* win, Item* item);
};

#endif
