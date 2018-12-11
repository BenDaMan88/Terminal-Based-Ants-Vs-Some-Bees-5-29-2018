/******************************************************************************
** Program Filename: Thrower.h
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

#ifndef THROWER_H
#define THROWER_H

using namespace std;

class Thrower:public Ant
{
  private:

  public:
    Thrower();
    virtual void attack(Bee** bees, int** num_bees, int index);

};

#endif
