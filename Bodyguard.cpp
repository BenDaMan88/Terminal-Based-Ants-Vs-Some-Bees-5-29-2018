/******************************************************************************
** Program Filename: Bodyguard.cpp
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <string>
#include <iostream>
#include "Bodyguard.h"
#include "Bee.h"

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: creates new object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: object created, variables initialized.
******************************************************************************/
Bodyguard::Bodyguard()
{
  damage = 0;
  armor = 2;
  name = "BDG";
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
void Bodyguard::attack(Bee** bees, int** num_bees, int index)
{
  //does nothing
}
