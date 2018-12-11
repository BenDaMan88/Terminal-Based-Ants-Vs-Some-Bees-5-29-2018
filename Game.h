/******************************************************************************
** Program Filename: Game.h
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <iostream>
#include <string>
#include "Square.h"

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game
{
  private:
    Square* board;
    int food_bank;

  public:
    Game();
    ~Game();
    bool game_over();
    bool is_int(string input);
    bool valid_input(string input, int num);
    bool valid_pick(string input);
    bool valid_position(string input, int type);
    int get_type_ant();
    int get_position(int type);
    int get_int(string input);
    void add_bee();
    void add_food();
    void add_ant(int type, int position);
    void add_ant();
    void attack_bees();
    void remove_bees();
    void remove_ants();
    void move_bees(int index);
    void move_bees(int index, int index2);
    void attack_ants(int index);
    void attack_ant_move_bees();
    void print_board();
    void start_game();
    void play_game();
    void end_game();

};

#endif
