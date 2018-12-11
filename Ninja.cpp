/******************************************************************************
** Program Filename: Ninja.cpp
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <string>
#include <iostream>
#include "Ninja.h"
#include "Bee.h"
#include "Square.h"

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: creates new object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: object created, variables initialized.
******************************************************************************/
Ninja::Ninja()
{
  damage = 1;
  armor = 1;
  name = "NIN";
}

/******************************************************************************
** Function: Attack
** Description: attacks bees according to ant type.
** Parameters: Bee** bee: the array of bees.
**  int** num_bees: the number of bees on each square.
**  int index: the square the ant is on.
** Pre-Conditions: Board initialized.
** Post-Conditions: bees attacked by ant.
******************************************************************************/
void Ninja::attack(Bee** bees, int** num_bees, int index)
{
  if(bees[index] == NULL)
    return;
  for(int i = 0; i < (*(num_bees[index])); i++)
  {
    bees[index][i].set_armor(bees[index][i].get_armor()-1);
  }
}
