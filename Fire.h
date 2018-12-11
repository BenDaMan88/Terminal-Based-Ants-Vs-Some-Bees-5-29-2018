/******************************************************************************
** Program Filename: Fire.h
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <iostream>
#include <string>
#include "Ant.h"
#include "Square.h"
#include "Bee.h"

#ifndef FIRE_H
#define FIRE_H

using namespace std;

class Fire:public Ant
{
  private:

  public:
    Fire();
    virtual void attack(Bee** bees, int** num_bees, int index);

};

#endif
