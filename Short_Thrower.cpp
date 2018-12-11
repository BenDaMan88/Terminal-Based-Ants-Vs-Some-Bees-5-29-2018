/******************************************************************************
** Program Filename: Short_Thrower.cpp
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <string>
#include <iostream>
#include "Short_Thrower.h"
#include "Bee.h"

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: creates new object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: object created, variables initialized.
******************************************************************************/
Short_Thrower::Short_Thrower()
{
  damage = 1;
  armor = 1;
  name = "S_T";
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
void Short_Thrower::attack(Bee** bees, int** num_bees, int index)
{
  int i = index;
  bool flag = false;
  for(i; i < index + 3; i++)
  {
    if((*(num_bees[i])) > 0)
    {
      flag = true;
      break;
    }
  }
  if(flag)
  {
    for(int j = 0; j < (*(num_bees[i])); j++)
    {
      bees[i][j].set_armor(bees[i][j].get_armor()-1);
    }
  }
}
