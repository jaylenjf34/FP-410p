/**
 * This file implements the Item class and its derived classes
 */
#include "item.h"

/**
 * Constructor (Item)
 * 
 * @param _cost:  cost of the item in whiffles
 * @param _name:  name of the item
 */
Item::Item(int _cost, std::string _name )
{
  cost = _cost;
  name = _name;
}

/**
 * Copy Constructor (Item)
 */
Item::Item(const Item & source)
{
  cost = source.cost;
  name = source.name;
}

/**
 * Destructor (virtual)
 */
Item::~Item()
{}

/**
 * Get Name
 * 
 * Getter for the Item's name
 */
std::string Item::get_name()
{
  return name;
}

/**
 * Get Cost 
 * 
 * Getter for the Item's cost 
 */
int Item::get_cost()
{
  return cost;
}

/**
 * Constructor (food)
 * 
 * @param energy_value:  amount of energy the food restores
 */
Food::Food(int _cost, std::string _name, int _energy_value)
     :Item(_cost, _name)
{
  energy_value = _energy_value;
}

/**
 * Copy Constructor (Food)
 */
Food::Food(const Food & source): Item(source)
{
  energy_value = source.energy_value;
}

/**
 * Destructor (Food)
 */
Food::~Food()
{
  energy_value = 0;
}

/**
 * Return Energy
 * 
 * Getter for the food's energy
 */
int Food::ret_energy()
{
  return energy_value;
}

/**
 * Constructor (Axe)
 */
Axe::Axe ( int c, std::string _name, int div_factor)
     :Item(c, _name)
{
  energy_div = div_factor;
}

/**
 * Destructor (Axe)
 */
Axe::~Axe()
{
  energy_div = 0;
  cost = 0;
}

/**
 * Energy Div Getter
 * 
 * Returns factor to reduce energy by
 */
int Axe::ret_energy_div()
{
  return energy_div;
}

/**
 * Constructor (Pickaxe)
 */
PickAxe::PickAxe( int c, std::string _name, int div_factor)
        :Item(c, _name)
{
  energy_div = div_factor;
}

/**
 * Energy Div Getter
 * 
 * Returns factor to reduce energy by
 */
int PickAxe::ret_energy_div()
{
  return energy_div;
}

/**
 * Destructor (pickaxe)
 */
PickAxe::~PickAxe ()
{
  energy_div = 0;
  cost = 0;
}

/**
 * Constructor (Binoculars)
 */
Binoculars::Binoculars(int _cost, std::string _name)
           :Item(_cost, _name)
{}

/**
 * Copy Constructor (Binoculars)
 */
Binoculars::Binoculars(const Binoculars & to_copy)
           :Item(to_copy)
{}

/**
 * Destructor (Binoculars)
 */
Binoculars::~Binoculars()
{}

/**
 * Constructor (Ship)
 */
Ship::Ship(int _cost, std::string _name) 
     :Item(_cost, _name)
{}

/**
 * Copy Constructor (Ship)
 */
Ship::Ship(const Ship & to_copy) 
     :Item(to_copy)
{}

/**
 * Destructor (Ship)
 */
Ship::~Ship()
{}

/**
 * Obstacle (constructor)
 */
Obstacle::Obstacle(std::string name)
         :Item(0, name)
{}

/**
 * Get Energy Cost
 * 
 * Getter for obstacle's energy cost
 */
int Obstacle::get_energy_cost()
{
  return energy_cost;
}

/**
 * Set Energy Cost
 * 
 * Setter for obstacle's energy cost
 */
void Obstacle::set_energy_cost(int obstacle_cost)
{
  energy_cost = obstacle_cost;
}

/**
 * Tree (constructor)
 */
Tree::Tree() : Obstacle("Tree")
{
  energy_cost = 50;
}

/**
 * Rock (constructor)
 */
Rock::Rock() : Obstacle("Rock")
{
  energy_cost = 100;
}
