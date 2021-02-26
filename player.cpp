/*
 * This file implements the player class
 */
#include "player.h"
#include "grovnik.h"

using namespace std;




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
	MyPack.add_axe();
	return 1;
}

// function to use axe and determine how much energy
// call with energy to be used and division factor
int player :: use_axe(int e_used, int div)
{
	e_used = e_used / div; // caluclate energy to remove
	remove_energy(e_used); // remove energy from axe use
	MyPack.use_axe();
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
	return MyPack.has_axe();
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
			// probably shouldn't be here
			return false;
	}	
} 

// function for changing the binoculars value
int player :: add_binoculars()
{
	MyPack.add_binoculars();
	return 1;
}

// function for determining whether the player has binoculars or not.
// false means we do not have binoculars
// true means we do have binoculars
bool player :: has_binoculars()
{
	return MyPack.has_binoculars();
}


int player :: pickup_pick_axe()
{
	MyPack.add_pickaxe();
	return 1;
}

// call with energy to be used and division factor
int player :: use_pick_axe(int e_used, int div)
{
	e_used = e_used / div;
	remove_energy(e_used);
	MyPack.use_pickaxe();
	return 1;
}

// function to determine if the player has a pick_axe
bool player :: has_pick_axe()
{
  return MyPack.has_pickaxe();
}
