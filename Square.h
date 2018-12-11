/******************************************************************************
** Program Filename: Square.h
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <string>
#include <iostream>
#include "Ant.h"
#include "Bodyguard.h"
#include "Bee.h"

#ifndef SQUARE_H
#define SQUARE_H

using namespace std;

struct Square
{

  Ant* ant;
  Bodyguard* bodyguard;
  Bee* bees;
  int num_bees;

};

#endif
