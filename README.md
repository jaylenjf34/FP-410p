## CS300-FRUPAL-Group-3
Repository for CS300 Group 3's final project FRUPAL, a text-based adventure game. 

## Team Members
Jacob Hilt, Zac Evanchak, Jaylen Figueroa, Adam Shih, and Tram Vuong

## Description and How To Guide
### How to compile
To compile our game, just type 'make'.
To run our game, type './frupal' on Linux. You will be prompted to enter in the name of the map file. The map file we used is called 'Map1.txt'.

### How to move around
W moves the hero up, A moves the hero left, S moves the hero down, and D moves the hero right.
The arrow keys move the cursor in the direction they point.

The player can quit at anytime by pressing 'q'.

### How items work
When stepping on a purchasable item, the menu will prompt the user asking if they'd like to buy it or not.

* If the user types 'n', they will move to the grovnik in which the item is held, but will not destroy the object. In other words, when they move off that grovnik, the item will still be in place so they can come back for it. 
* If the player types 'y', the item will perform its intended purpose, then disappear. In other words, when the player moves off of that grovnik, the item will no longer be there.

Here are our items, and what they do:
- Food: Add energy for whiffles
- Pickaxe: Reduce energy used to break one rock
- Axe: Reduce energy used to break one tree
- Treasure (no prompt): Add random sum between 0 and 500 to player's whiffles
- Royal Diamond: Increase royal diamond count, win the game if it reaches 4
- Ship: Allows the player to sail on water. Sailing costs no energy
- Binoculars: Allows the player to see 2 squares at a time in any direction

### How obstacles work
The game also includes the tree and rock obstacles. When the player occupies a grovnik containing one of these,
they either just take the full hit to their energy that the obstacle takes to break, or, if they have a tool
(such as a pickaxe or axe), they will be prompted to see if they'd like to use it.

* If they select 'n', they will move into the space just as they would without the tool.
* If they say 'y', they will still move into the space, but will take reduced energy to break it.

The player can quit at anytime by pressing 'q'.

## Additional Information & Links
We were able to implement all required features. Food, treasure, clues, tools, obstacles, binoculars, and the ship. Of course, we also implemented the royal diamonds, a win screen, and a death screen. The map automatically reveals itself as the player moves around, and the grovnik information isn't viewable unless the player has viewed that grovnik.
Unfortunately, we weren't able to implement any extra stretch goals. The one added feature is that the user is able to enter a map name, thereby meaning another map file could be created and used in our version of frupal. However, it would have to match our map file format. 

Google Drive link to Design & Requirements Document: https://docs.google.com/document/d/1GXRsxyIRnRy2N2VhzUufbPwuwdXvFkd6rwTCZflxBDo/edit?usp=sharing
Github: https://github.com/vuong2-pdx/CS300-FRUPAL-Group-3/edit/main/
Presentation Video:
https://media.pdx.edu/media/Group3Frupal/1_ix2xhgzz
