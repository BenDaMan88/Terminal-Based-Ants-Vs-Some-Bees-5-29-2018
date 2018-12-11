/******************************************************************************
** Program Filename: main.cpp
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Game.h"


/******************************************************************************
** Function: Main Function
** Description: runs game
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: game is ended.
******************************************************************************/
int main()
{
  srand(time(NULL));
  
  Game g;
  g.start_game();
  
  return 0;
}