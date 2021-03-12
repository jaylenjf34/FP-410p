/*
 * This file defines the Grovnik struct.  A grovnik consists of a char to represent terrain, any item (object)
 * on the grovnik, whether it is visible, and a pointer to an item at this grovnik.
 */
struct Grovnik
{
	Grovnik();
  	~Grovnik();
  	char terrain;
  	/*
   	* Meadow: 0
   	* Water: 1
   	* Swamp: 2
   	* Wall: 3
   	*/

  	char object;
  	/*
   	* Nothing: N
   	* Diamond: D
   	* Player: @
   	* Ship: S
   	* Food: F
   	*/

  	bool visible;

  	class Item * item;
};
