/******************************************************************************
** Program Filename: Ant.cpp
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <string>
#include <iostream>
#include "Ant.h"

using namespace std;


/******************************************************************************
** Function: Get Name
** Description: returns name
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: name returned.
******************************************************************************/
string Ant::get_name()
{
  return name;
}