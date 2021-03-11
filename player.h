#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

/**
 * The Pack class handles player inventory such as player equippable items.
 * This class also handles the initial player inventory. 
 */


class Pack
{
	public:

		Pack();
		//functions related to the use, presence and acquisition of axes in the players inventory
		void use_axe();
		bool has_axe();
		void add_axe();
		//functions related to the use, presence and acquisition of pickaxes in the players inventory
		void use_pickaxe();
		void add_pickaxe();
		bool has_pickaxe();
		////functions related to the presence and acquisition of binoculars in the players inventory
		int add_binoculars();
		bool has_binoculars();


    protected:
		bool axe;  // value to determine whether a user has an axe or not
		bool pick_axe;// value to determine whether Player has a pickaxe or not
		bool binoculars;// value used to determine if the player has binoculars or not

};


/**
 * This is the Player class that holds all relevant info that determines whether the Player is dead or not, 
 * how much currency, energy, and what items that the Player has in their possession.
 */

class Player
{
	public:

		Player(int e, int w, bool a, int a_t, int g);

		bool is_dead (); // function that checks whether the user is dead or not
		bool handle_movement(char); // handles Player state when attempting to move character

		bool has_axe(); // tells whether the Player has an axe or not
		int pickup_axe(); // lets a Player pickup an axe
		int use_axe(int, int); // determines energy used for axe use

		bool has_pick_axe(); // tells whether Player has pickaxe or not
		int pickup_pick_axe(); // lets Player pickup pick_axe
		int use_pick_axe(int, int); // uses up a Player's pickaxe

		int ret_energy(); // returns energy the Player has
		int add_energy(int); // add energy to the Player
		int remove_energy(int); // removes energy from the Player

		int ret_whiffle(); // returns whiffle that the Player has
		int add_whiffle(int); // adds currency to the Player
		int remove_whiffle(int); // removes currency from the Player
		
		int change_grovnik(int); // update current grovnik type 
		int ret_grovnik(); // returns the type of grovnik the Player has
		// TODO: implement following functions
		int change_grov_obj(int);
		int ret_grov_obj();

		bool has_ship(); // returns true or false value to determine whether Player has a ship or not.
		int add_ship(); // used for acquiring ship on the map.

		int add_diamonds(); // adds diamonds to the Player's items
		int ret_diamonds(); // return the amount of diamonds the Player has

		bool has_binoculars(); // tells us whether Player has binoculars or not
		int add_binoculars(); // add binoculars to the Player
		

	protected:

		Pack MyPack; //pack class object used for player inventory
		int energy; // Player life
		int whiffle; // Player currency
		int curr_grov; // current type of grovnik that the Player is on
		bool ship; // used for adding ship to Player's objects
		int diamonds; // used to store the number of Player's diamonds
		
};

#endif
