/******************************************************************************
** Program Filename: Insect.h
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <iostream>
#include <string>

#ifndef INSECT_H
#define INSECT_H

using namespace std;

class Insect
{
  protected:
    int damage;
    int armor;
    
  public:
    void set_damage(int damage);
    void set_armor(int armor);
    int get_damage();
    int get_armor();
    
};

#endif