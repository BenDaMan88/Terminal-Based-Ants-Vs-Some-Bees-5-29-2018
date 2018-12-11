/******************************************************************************
** Program Filename: Ant.h
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <iostream>
#include <string>
#include "Insect.h"
#include "Bee.h"

#ifndef ANT_H
#define ANT_H

using namespace std;

class Ant:public Insect
{
  protected:
    string name;

  public:
    virtual void attack(Bee** bees, int** num_bees, int index) = 0;
    string get_name();

};

#endif
