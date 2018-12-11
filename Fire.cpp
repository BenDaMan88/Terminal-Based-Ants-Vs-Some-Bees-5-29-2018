/******************************************************************************
** Program Filename: Fire.cpp
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <string>
#include <iostream>
#include "Fire.h"
#include "Square.h"
#include "Bee.h"

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: creates new object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: object created, variables initialized.
******************************************************************************/
Fire::Fire()
{
  damage = 0;
  armor = 1;
  name = "FIR";
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
void Fire::attack(Bee**  bees, int** num_bees, int index)
{
  //does nothing while alive
}
