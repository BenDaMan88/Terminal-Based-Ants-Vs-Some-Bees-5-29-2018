/******************************************************************************
** Program Filename: Insect.cpp
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <string>
#include <iostream>
#include "Insect.h"

using namespace std;

/******************************************************************************
** Function: Setter
** Description: sets value.
** Parameters: new value.
** Pre-Conditions: None
** Post-Conditions: value set.
******************************************************************************/
void Insect::set_damage(int damage)
{
  this->damage = damage;
}

/******************************************************************************
** Function: Setter
** Description: sets value.
** Parameters: new value.
** Pre-Conditions: None
** Post-Conditions: value set.
******************************************************************************/
void Insect::set_armor(int armor)
{
  this->armor = armor;
}

/******************************************************************************
** Function: Getter
** Description: returns value.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
int Insect::get_damage()
{
  return damage;
}

/******************************************************************************
** Function: Getter
** Description: returns value.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: value returned.
******************************************************************************/
int Insect::get_armor()
{
  return armor;
}
