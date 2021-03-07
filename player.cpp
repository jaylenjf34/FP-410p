/*
 * This file implements the player class
 */
#include "player.h"
#include "grovnik.h"

using namespace std;

// sets starter values for the player
player :: player ( int e, int w, bool a, int a_t, int g)
{
	energy = e;
	whiffle = w;
	axe = a;
	axe_type = a_t;
	curr_grov = g;
	ship = false;
	binoculars = false;
	diamonds = 0;
	pick_axe = false;
}

// changes the energy that the player has.
int player :: add_energy(int val)
{
	energy += val;
	return 1;
}

// increases currency the player has with passed in value
int player :: add_whiffle( int val)
{ 
	whiffle += val; 
	return 1;
}

// removes energy from the player with passed in value
int player :: remove_energy(int val)
{
	energy -= val;
	if(energy <= 0)
	{
		energy = 0;
	}

	return 1;
}

// removes currency from the player with  a passed in value;
int player :: remove_whiffle (int val)
{
	whiffle -= val;

	if(whiffle <=  0)
	{
		whiffle = 0;
	}

	return 1;
}

// function to determine if the player has dies or not
bool player :: dead ()
{
	if(energy <= 0) // player is dead
	{
		return true;
	}
	else
		return false;
}

// returns amount of currency for outside use
int player :: ret_whiffle()
{
	return whiffle;
}

// returms amount of energy for outisde use
int player :: ret_energy()
{
	return energy;
}

// updates the type of grovnik that the player is on. 
int player :: change_grovnik(int type)
{
	curr_grov = type;
	return 1;
}

// player picks up an axe types is passed in as an int
int player :: pickup_axe()
{
	axe = true;
	return 1;
}

// function to use axe and determine how much energy
// call with energy to be used and division factor
int player :: use_axe(int e_used, int div)
{
	e_used = e_used / div; // caluclate energy to remove
	remove_energy(e_used); // remove energy from axe use
	axe = false; 
	return 1;
}

// function for cahnging the ship value
int player :: add_ship()
{
	ship = true;
	return 1;
}

// function for determining whether the player has a ship or not.
// false means we do not have a ship
// true means we do have a ship
bool player :: has_ship()
{
	return ship;
}


// function to add diamonds to player's items
int player :: add_diamonds()
{
	++diamonds;
	return 1;
}



// function ot return number of diamonds the player has.
int player :: ret_diamonds()
{
	return diamonds;
}

// returns the type of grovnik the player is currently on.
int player :: ret_grovnik()
{
	return curr_grov;
}

// determines whether the player has an axe or not
bool player :: has_axe()
{
	return axe;
}

// returns what axe type we have.
int player :: ret_axe_type()
{
	return axe_type;
}

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

// function for changing the binoculars value
int player :: add_binoculars()
{
	binoculars = true;
	return 1;
}

// function for determining whether the player has binoculars or not.
// false means we do not have binoculars
// true means we do have binoculars
bool player :: has_binoculars()
{
	return binoculars;
}


int player :: pickup_pick_axe()
{
	pick_axe = true;
	return 1;
}

// call with energy to be used and division factor
int player :: use_pick_axe(int e_used, int div)
{
	e_used = e_used / div;
	remove_energy(e_used);
	pick_axe = false;
	return 1;
}

// function to determine if the player has a pick_axe
bool player :: has_pick_axe()
{
  return pick_axe;
}