/******************************************************************************
** Program Filename: Bee.h
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <iostream>
#include <string>
#include "Insect.h"

#ifndef BEE_H
#define BEE_H

using namespace std;

class Bee:public Insect
{
  private:
    string name;

  public:
    Bee();
    string get_name();

};

#endif
