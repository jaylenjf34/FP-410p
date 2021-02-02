/*
 * This file implements the menu
 */
#include "menu.h"

/*
 * Constructor
 */
Menu::Menu()
{
  curgrov = nullptr;
  myPlayer = nullptr;
}

/*
 * Update
 * 
 * Reassigns current grovnik and player pointers
 */
bool Menu::update(Grovnik* grov, player* p)
{
  myPlayer = p;
  curgrov = grov;
  
  return true;
}

/*
 * Render
 * 
 * Manipulates window to present menu information and information about the current grovnik under the
 * cursor.
 * 
 * @param window:  menu window to manipulate
 */
void Menu::render(WINDOW* win)
{
  int y, x;
  getyx(win, y, x);
  werase(win);

  // print dividing line
  mvwvline(win, 0, 0, '|', LINES);

  // print out grovnik info under cursor
  // info will be taken from curgrov 
  readgrov(win);

  // print out movement controls for the hero
  mvwprintw(win, 10, 2, "Move Hero");
  mvwprintw(win, 11, 2, "w: up");
  mvwprintw(win, 12, 2, "s: down");
  mvwprintw(win, 13, 2, "a: left");
  mvwprintw(win, 14, 2, "d: right");

  // print out inventory contents
  mvwprintw(win, LINES - 8, 2, "Inventory:");
  if(myPlayer->has_axe())
    mvwprintw(win, LINES - 7, 2, "Axe");
  if(myPlayer->has_pick_axe())
    mvwprintw(win, LINES - 7, 6, "Pickaxe");
  if(myPlayer->has_ship())
    mvwprintw(win, LINES - 6, 2, "Ship");
  if(myPlayer->has_binoculars())
    mvwprintw(win, LINES - 5, 2, "Binoculars");

  mvwprintw(win, LINES - 3, 2, "Diamonds: %d", myPlayer->ret_diamonds());
  mvwprintw(win, LINES - 2, 2, "E: %d W: %d", myPlayer->ret_energy(), myPlayer->ret_whiffle());

  wrefresh(win);
  wmove(win, y, x);
  return;
}

/*
 * Read Grov
 * 
 * Prints grovnik item and terrain information to the menu window
 */
void Menu::readgrov(WINDOW* win)
{
  Food* f;
  Tree* t;
  Rock* r;
  Axe* a;
  PickAxe* p;

  if(!curgrov->visible || !curgrov)
    return;

  switch(curgrov->object)
  {
    case 'F':
      f = dynamic_cast<Food*>(curgrov->item);
      if(f){
        mvwprintw(win, 1, 2, "Food: %s", f->get_name().c_str());
        mvwprintw(win, 2, 2, "Cost: %d", f->get_cost());
        mvwprintw(win, 3, 2, "Energy +: %d", f->ret_energy()); 
        f = nullptr;
      }
      break;

    case 'T':
      t = dynamic_cast<Tree*>(curgrov->item);
      if(t) {
        mvwprintw(win, 1, 2, "Tree");
        mvwprintw(win, 2, 2, "Energy -: %d", t->get_energy_cost());
      }
      break;

    case 'R':
      r = dynamic_cast<Rock*>(curgrov->item);
      if(r) {
        mvwprintw(win, 1, 2, "Rock");
        mvwprintw(win, 2, 2, "Energy -: %d", r->get_energy_cost());
      }
      break;

    case 'A':
      a = dynamic_cast<Axe*>(curgrov->item);
      if(a) {
        mvwprintw(win, 1, 2, "Axe");
        mvwprintw(win, 2, 2, "Break trees with");
        mvwprintw(win, 3, 2, "less energy");
        mvwprintw(win, 4, 2, "Cost: %d", a->get_cost());
      }
      break;

    case 'P':
      p = dynamic_cast<PickAxe*>(curgrov->item);
      if(p) {
        mvwprintw(win, 1, 2, "PickAxe");
        mvwprintw(win, 2, 2, "Break rocks with");
        mvwprintw(win, 3, 2, "less energy");
        mvwprintw(win, 4, 2, "Cost: %d", p->get_cost());
      }
      break;

    case 'S':
      mvwprintw(win, 1, 2, "Ship ");
      mvwprintw(win, 2, 2, "Cost: %d", curgrov->item->get_cost());
      mvwprintw(win, 3, 2, "Sail on water");
      break;
    case 'D':
      mvwprintw(win, 1, 2, "ROYAL DIAMOND ");
      mvwprintw(win, 2, 2, "Your main goal ");
      mvwprintw(win, 3, 2, "Collect all 4 ");
      break;
    case 'B':
      mvwprintw(win, 1, 2, "Binoculars ");
      mvwprintw(win, 2, 2, "Cost: %d", curgrov->item->get_cost());
      mvwprintw(win, 3, 2, "Visible range +"); 
      break;
    case '$':
      mvwprintw(win, 1, 2, "Treasure ");
      mvwprintw(win, 2, 2, "Contains ???");
      mvwprintw(win, 3, 2, "whiffles.");
      break;
    case '1':
      mvwprintw(win, 1, 2, "Clue:");
      mvwprintw(win, 2, 2, "The diamond island");
      mvwprintw(win, 3, 2, "contains its name.");
      mvwprintw(win, 4, 2, "Ships cost $700.");
      break;
    case '2':
      mvwprintw(win, 1, 2, "Clue:");
      mvwprintw(win, 2, 2, "If ye seek better");
      mvwprintw(win, 3, 2, "vision, look to");
      mvwprintw(win, 4, 2, "the Northwest.");
      break;
    case '3':
      mvwprintw(win, 1, 2, "Clue:");
      mvwprintw(win, 2, 2, "If you are still");
      mvwprintw(win, 3, 2, "without a diamond");
      mvwprintw(win, 4, 2, "search harder.");
      break;

    default:
      mvwprintw(win, 1, 1, "");
      mvwprintw(win, 2, 1, "");
      mvwprintw(win, 3, 1, "");
      break;
  }

  switch(curgrov->terrain)
  {
    case '0':
      mvwprintw(win, 6, 2, "Terrain: Meadow");
      mvwprintw(win, 7, 2, "Passable: Yes");
      mvwprintw(win, 8, 2, "Energy: 1");
      break;

    case '1':
      mvwprintw(win, 6, 2, "Terrain: Water");
      mvwprintw(win, 7, 2, myPlayer->has_ship() ? "Passable: Yes" : "Passable: No");
      mvwprintw(win, 8, 2, "");
      break;

    case '2':
      mvwprintw(win, 6, 2, "Terrain: Swamp");
      mvwprintw(win, 7, 2, "Passable: Yes");
      mvwprintw(win, 8, 2, "Energy: 2");
      break;

    case '3':
      mvwprintw(win, 6, 2, "Terrain: Wall");
      mvwprintw(win, 7, 2, "Passable: No");
      mvwprintw(win, 8, 2, "");
      break;

    default:
      mvwprintw(win, 6, 2, "");
      mvwprintw(win, 7, 2, "");
      mvwprintw(win, 8, 2, "");
      break;
      
  }
}

/*
 * Prompt Buy
 * 
 * Displays a purchase prompt for Food and Tool item types
 */
void Menu::prompt_buy(WINDOW* win, Item* item)
{
  mvwprintw(win, 16, 2, "Buy %s", item->get_name().c_str());
  mvwprintw(win, 17, 2, "for %d? (Y/N)", item->get_cost());
  wrefresh(win);
}

/*
 * Prompt Use 
 * 
 * Display a Use Tool prompt for Tool Items
 */
void Menu::prompt_use(WINDOW* win, Item* item)
{
  std::string tool;

  if(item->get_name() == "Tree")
    tool = "Axe";
  else if(item->get_name() == "Rock")
    tool = "PickAxe";

  mvwprintw(win, 16, 2, "Use %s? (Y/N)", tool.c_str());
  wrefresh(win);
}
