/******************************************************************************
** Program Filename: Long_Thrower.h
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

#ifndef LONG_THROWER_H
#define LONG_THROWER_H

using namespace std;

class Long_Thrower:public Ant
{
  private:

  public:
    Long_Thrower();
    virtual void attack(Bee** bees, int** num_bees, int index);

};

#endif
