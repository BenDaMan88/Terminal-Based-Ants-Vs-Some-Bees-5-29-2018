/******************************************************************************
** Program Filename: Wall.h
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

#ifndef WALL_H
#define WALL_H

using namespace std;

class Wall:public Ant
{
  private:

  public:
    Wall();
    virtual void attack(Bee** bees, int** num_bees, int index);

};

#endif
