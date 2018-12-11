/******************************************************************************
** Program Filename: Short_Thrower.h
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <iostream>
#include <string>
#include "Ant.h"
#include "Bee.h"

#ifndef SHORT_THROWER_H
#define SHORT_THROWER_H

using namespace std;

class Short_Thrower:public Ant
{
  private:

  public:
    Short_Thrower();
    virtual void attack(Bee** bees, int** num_bees, int index);

};

#endif
