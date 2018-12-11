/******************************************************************************
** Program Filename: Harvester.h
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

#ifndef HARVESTER_H
#define HARVESTER_H

using namespace std;

class Harvester:public Ant
{
  private:

  public:
    Harvester();
    virtual void attack(Bee** bees, int** num_bees, int index);
};

#endif
