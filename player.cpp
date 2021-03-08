/**
 * This file implements the player class
 */
#include "player.h"
#include "grovnik.h"

using namespace std;

/**
 * @brief sets starter values for the player
 * 
 * @param e initial energy
 * @param w initial whiffle count
 * @param a whether player starts with an axe or not
 * @param a_t initial axe type
 * @param g initial grovnik
 * @return player 
 */




Pack :: Pack ()
{

 axe = false; 
 binoculars = false;
 pick_axe = false;



}



void Pack :: use_axe()
{
  axe = false;

}
bool Pack :: has_axe()
{

  return axe;

}
void  Pack :: add_axe()
{

  axe = true;
}



void Pack ::  use_pickaxe()
{
  pick_axe = false;

}

void Pack :: add_pickaxe()
{
  pick_axe = true;

}

bool Pack :: has_pickaxe()
{
  return pick_axe;

}

int Pack :: add_binoculars()
{
  binoculars = true;
  return 1;

}


bool Pack :: has_binoculars()
{
  return binoculars;

}

// sets starter values for the player

player :: player ( int e, int w, bool a, int a_t, int g)
{
	energy = e;
	whiffle = w;
	curr_grov = g;
	ship = false;
	diamonds = 0;
}

/**
 * @brief increases the energy that the player has.
 * 
 * @param val int to increase player's energy by
 * @return int 1 
 */
int player :: add_energy(int val)
{
	energy += val;
	return 1;
}

/**
 * @brief increases currency the player has with passed in value
 * 
 * @param val int to increase player currency by
 * @return int 1
 */
int player :: add_whiffle( int val)
{ 
	whiffle += val; 
	return 1;
}

/**
 * @brief removes energy from the player with passed in value
 * 
 * @param val int to decrease energy by
 * @return int 1
 */
int player :: remove_energy(int val)
{
	energy -= val;
	if(energy <= 0)
	{
		energy = 0;
	}

	return 1;
}

/**
 * @brief removes currency from the player with  a passed in value;
 * 
 * @param val int to decrease player currency by
 * @return int 1
 */
int player :: remove_whiffle (int val)
{
	whiffle -= val;

	if(whiffle <=  0)
	{
		whiffle = 0;
	}

	return 1;
}

/**
 * @brief function to determine if the player has died or not
 * 
 * @return true if player energy > 0, false otherwise
 */
bool player :: is_dead ()
{
	if(energy <= 0) // player is dead
	{
		return true;
	}
	else
		return false;
}

/**
 * @brief returns amount of currency for outside use
 * 
 * @return int 
 */
int player :: ret_whiffle()
{
	return whiffle;
}

/**
 * @brief returns amount of energy for outisde use
 * 
 * @return int 
 */
int player :: ret_energy()
{
	return energy;
}

/**
 * @brief updates the type of grovnik that the player is on. 
 * 
 * @param type int representing new grovnik type
 * @return int 1
 */
int player :: change_grovnik(int type)
{
	curr_grov = type;
	return 1;
}

/**
 * @brief gives player an axe. axe type is passed in as an int
 * 
 * @return int 
 */
int player :: pickup_axe()
{
	MyPack.add_axe();
	return 1;
}

/**
 * @brief function to use axe and determine how much energy is used
 * 
 * @param e_used amount of energy used as int
 * @param div division factor as int
 * @return int 
 */
int player :: use_axe(int e_used, int div)
{
	e_used = e_used / div; // calculate energy to remove
	remove_energy(e_used); // remove energy from axe use
	MyPack.use_axe();
	return 1;
}

/**
 * @brief function for giving player a ship
 * 
 * @return int 1
 */
int player :: add_ship()
{
	ship = true;
	return 1;
}

/**
 * @brief function for determining whether the player has a ship or not.
 * 
 * @return true if player has a ship, else false
 */
bool player :: has_ship()
{
	return ship;
}


/**
 * @brief function to add 1 diamond to player's items
 * 
 * @return int 1
 */
int player :: add_diamonds()
{
	++diamonds;
	return 1;
}


/**
 * @brief function to return number of diamonds the player has.
 * 
 * @return int
 */
int player :: ret_diamonds()
{
	return diamonds;
}

/**
 * @brief returns the type of grovnik the player is currently on.
 * 
 * @return int 
 */
int player :: ret_grovnik()
{
	return curr_grov;
}

/**
 * @brief determines whether the player has an axe or not
 * 
 * @return true if player has an axe, else false
 */
bool player :: has_axe()
{
	return MyPack.has_axe();
}



/**
 * @brief change player's energy depending on player's movement through terrain
 * 
 * @param terrain type of terrain as char
 * @return true if movement possible, else false
 */
bool player::handle_movement(char terrain)
{
	switch (terrain)
	{
		case '0':  // handle meadow
			--energy;
			return true;
			break;
		case '1': // handle water
			if (ship)
			{
				return true;
			}
			else
			{
				--energy;
				return false;
			}
			break;
		case '2': // handle swamp
			energy -= 2;
			return true;
			break;
		case '3':  // handle wall
			--energy;
			return false;
			break;
		default:
			// TODO: implement error handling
			return false;
	}	
} 

/**
 * @brief function for giving player binoculars
 * 
 * @return int 1
 */
int player :: add_binoculars()
{
	MyPack.add_binoculars();
	return 1;
}

/**
 * @brief function for determining whether the player has binoculars or not.
 * 
 * @return true if player has binoculars, else false
 */
bool player :: has_binoculars()
{
	return MyPack.has_binoculars();
}

/**
 * @brief gives player a pick_axe. pick_axe type is passed in as an int
 * 
 * @return int 
 */
int player :: pickup_pick_axe()
{
	MyPack.add_pickaxe();
	return 1;
}

/**
 * @brief function to use axe and determine how much energy is used
 * 
 * @param e_used energy used as int
 * @param div division factor as int
 * @return int 1
 */
int player :: use_pick_axe(int e_used, int div)
{
	e_used = e_used / div;
	remove_energy(e_used);
	MyPack.use_pickaxe();
	return 1;
}

/**
 * @brief function to determine if the player has a pick_axe
 * 
 * @return true if player has pick_axe, else false
 */
bool player :: has_pick_axe()
{
  return MyPack.has_pickaxe();
}
