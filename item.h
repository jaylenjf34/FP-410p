/*
 * This file is the header for the Item class and its derived Item types:  Food, Axe, Pickaxe, Ship,
 * Binoculars, Tree, and Rock.
 */
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
    public:
        Item(int, std::string); // cost, name of item
        Item(const Item &);
        virtual ~Item();
        std::string get_name(); //getter functions for the menu
        int get_cost();
    protected:
        int cost;
        std::string name;
};

class Food : public Item
{
    public:
        Food(int, std::string, int);// third int is for energy_value 
        Food(const Food &);
        ~Food();
        int ret_energy();// getter function for menu

    private:
        int energy_value; //how much energy a food item restores
};

class Axe : public Item
{
  public:
    Axe(int, std::string, int); //third int is for energy_div
    int ret_energy_div();
    ~Axe();

  protected:
    int energy_div; // used to divide up energy used
};

class PickAxe : public Item
{

  public:
    PickAxe(int, std::string, int); // third int is for energy_div
    int ret_energy_div();
    ~PickAxe();

  protected:
    int energy_div; // used to divide up energy used


};

class Binoculars : public Item
{
    public:
      Binoculars(int _cost, std::string _name);
	    Binoculars(const Binoculars & to_copy);
	    ~Binoculars();
};

class Ship : public Item
{
    public:
      Ship(int _cost, std::string _name);
      Ship(const Ship &);
      ~Ship();
};

class Obstacle : public Item
{
  public:
    Obstacle(std::string name);
    int get_energy_cost();
    void set_energy_cost(int);

  protected:
    int energy_cost;
};

class Tree : public Obstacle
{
  public:
    Tree();
};

class Rock : public Obstacle
{
  public:
    Rock();
};

#endif
