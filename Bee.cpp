/******************************************************************************
** Program Filename: Bee.cpp
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <string>
#include <iostream>
#include "Bee.h"

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: creates new object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: object created, variables initialized.
******************************************************************************/
Bee::Bee()
{
  name = "BEE";
  damage = 1;
  armor = 3;
}

/******************************************************************************
** Function: Get Name
** Description: returns name
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: name returned.
******************************************************************************/
string Bee::get_name()
{
  return name;
}
