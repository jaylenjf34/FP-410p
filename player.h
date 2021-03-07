#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>




/*

   this is the player class that holds all relevant info that determines whether
   the player is dead or not, how much currency, energy, and what items that the player has in their
   possession.




 */


class player
{



	public:

		player(int e, int w, bool a, int a_t, int g);

		int ret_whiffle(); // returns whiffle that the player has
		int ret_energy(); // returns energy the player has
		int add_energy(int); // add energy to the player
		int remove_energy(int); // removes energy from the player
		int add_whiffle(int); // adds currency to the player
		int remove_whiffle(int); // removes currency from the player
		bool dead (); // function that checks whether the user is dead or not
		int change_grovnik(int); // update current grovnik type 
		int pickup_axe(); // lets a player pickup an axe
		int pickup_pick_axe(); // lets player pickup pick_axe
		int use_axe(int, int); // determines energy used for axe use
		int use_pick_axe(int, int); // uses up a player's pickaxe
		int add_ship(); // used for acquiring ship on the map.
		bool has_ship(); // returns true or false value to determine whether player has a ship or not.
		int add_diamonds(); // adds diamonds to the player's items
		int ret_diamonds(); // return the amount of diamonds the player has
		int ret_grovnik(); // returns the type of grovnik the player has
		bool has_axe(); // tells whether the player has an axe or not
		bool has_pick_axe(); // tells whether player has pickaxe or not
		int ret_axe_type(); // tells us what type of axe we have
		// Added by Jacob (clarifying so you know what's new)
		bool handle_movement(char);
		int add_binoculars();
		bool has_binoculars();
		// TODO: implement following functions
		int change_grov_obj(int);
		int ret_grov_obj();

	protected:
		int energy; // player life
		int whiffle; // player currency
		int curr_grov; // current type of grovnik that the player is on
		bool axe;  // value to determine whether a user has an axe or not
		int axe_type; // type of axe the player has
		bool pick_axe;// value to determine whether player has a pickaxe or not
		bool ship; // used for adding ship to player's objects
		int diamonds; // used to store the number of player's diamonds
    	int grov_obj;
		bool binoculars;



};




#endif
