/******************************************************************************
** Program Filename: Game.cpp
** Author: Ben Johnson
** Date: May 27, 2018
** Description: Ants vs Some Bees
** Inpupt: user input.
** Output: results printed to file or terminal depending on user's choice.
******************************************************************************/

#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Game.h"
#include "Harvester.h"
#include "Bodyguard.h"
#include "Fire.h"
#include "Long_Thrower.h"
#include "Ninja.h"
#include "Short_Thrower.h"
#include "Thrower.h"
#include "Wall.h"

using namespace std;

/******************************************************************************
** Function: Constructor
** Description: creates new object.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: object created, variables initialized.
******************************************************************************/
Game::Game()
{
  board = new Square[10];
  for(int i = 0; i < 10; i++)
  {
    board[i].ant = NULL;
    board[i].bodyguard = NULL;
    board[i].bees = NULL;
    board[i].num_bees = 0;
  }
  food_bank = 50;
}

/******************************************************************************
** Function: Destructor
** Description: cleans up memory.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: all memory deleted.
******************************************************************************/
Game::~Game()
{
  if(board != NULL)
  {
    for(int i = 0; i < 10; i++)
    {
      if(board[i].ant != NULL)
      {
        delete board[i].ant;
      }
      if(board[i].bodyguard != NULL)
        delete board[i].bodyguard;
      if(board[i].bees != NULL)
        delete [] board[i].bees;
    }
    delete [] board;
  }
}

/******************************************************************************
** Function: Game Over
** Description: checks if game is over or not.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: whether game is over or not.
******************************************************************************/
bool Game::game_over()
{
  if(board[0].bees != NULL && board[0].ant == NULL && board[0].bodyguard == NULL)
    return true;
  for(int i = 1; i < 10; i++)
  {
    if(board[i].bees != NULL)
      return false;
  }
  return true;
}

/******************************************************************************
** Function: Add bee
** Description: adds bee to end of board.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: bee added.
******************************************************************************/
void Game::add_bee()
{
    Bee* temp = new Bee[board[9].num_bees + 1];
    if(board[9].bees != NULL)
    {
      for(int i = 0; i < board[9].num_bees; i++)
      {
        temp[i] = board[9].bees[i];
      }
      delete [] board[9].bees;
    }
    Bee b;
    temp[board[9].num_bees] = b;
    board[9].bees = temp;
    board[9].num_bees++;
}

/******************************************************************************
** Function: Get Int
** Description: converts string to int.
** Parameters: string input: string to convert.
** Pre-Conditions: None
** Post-Conditions: int returned.
******************************************************************************/
int Game::get_int(string input)
{
  int total = 0;
  for(int i = 0; i < input.length(); i++)
  {
    total += (input[i]-48) * pow(10, input.length() - i - 1);
  }
  return total;
}

/******************************************************************************
** Function: Is int
** Description: checks if input is valid int or not.
** Parameters: string input: string to check.
** Pre-Conditions: None
** Post-Conditions: whether or not string is valid.
******************************************************************************/
bool Game::is_int(string input)
{
  if(input.length() < 1)
    return false;
  for(int i = 0; i < input.length(); i++)
  {
    if(input[i] < '0' || input[i] > '9')
      return false;
  }
  if(get_int(input) <= 0)
    return false;
  return true;
}

/******************************************************************************
** Function: valid int
** Description: checks if input is valid int or not within range.
** Parameters: string input: string to check.
**  int num: the upper limit for int value.
** Pre-Conditions: None
** Post-Conditions: whether or not string is valid.
******************************************************************************/
bool Game::valid_input(string input, int num)
{
  if(input.length() < 1)
    return false;
  for(int i = 0; i < input.length(); i++)
  {
    if(input[i] < '0' || input[i] > '9')
      return false;
  }
  if(get_int(input) > num || get_int(input) <= 0)
    return false;
  return true;
}

/******************************************************************************
** Function: Valid Pick
** Description: checks if type of ant has a spot to be placed.
** Parameters: string input: user choice.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
bool Game::valid_pick(string input)
{
  if(get_int(input) == 8)
  {
    for(int i = 0; i < 10; i++)
    {
      if(board[i].bodyguard == NULL)
        return true;
    }
    return false;
  }
  else
  {
    for(int i = 0; i < 10; i++)
    {
      if(board[i].ant == NULL)
        return true;
    }
    return false;
  }
}

/******************************************************************************
** Function: Valid Pick
** Description: checks if type of ant can be placed on chioce.
** Parameters: string input: user choice.
** Pre-Conditions: None
** Post-Conditions: None.
******************************************************************************/
bool Game::valid_position(string input, int type)
{
  if(type == 7)
  {
    if(board[get_int(input)-1].bodyguard == NULL)
      return true;
    return false;
  }
  else
  {
    if(board[get_int(input)-1].ant == NULL)
      return true;
    return false;
  }
}

/******************************************************************************
** Function: Get Type Ant
** Description: get user choice for type of ant.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: Valid User choice returned.
******************************************************************************/
int Game::get_type_ant()
{
  cout << "\nType             Food Cost Armor" << endl;
  cout << "1. Harvester         2       1" << endl;
  cout << "2. Thrower           4       1" << endl;
  cout << "3. Fire              4       1" << endl;
  cout << "4. Long Thrower      3       1" << endl;
  cout << "5. Short Thrower     3       1" << endl;
  cout << "6. Wall              4       4" << endl;
  cout << "7. Ninja             6       1" << endl;
  cout << "8. Bodyguard         4       2" << endl;
  cout << "\nWhich type of ant would you like to add? (1-8): ";
  string input;
  getline(cin, input);
  while(!valid_input(input, 8) || !valid_pick(input))
  {
    cout << "invalid input. give valid input: ";
    getline(cin, input);
  }
  return get_int(input) - 1;
}

/******************************************************************************
** Function: Get Position
** Description: get user choice for position of ant.
** Parameters: int type: the type of ant.
** Pre-Conditions: None
** Post-Conditions: Valid User choice returned.
******************************************************************************/
int Game::get_position(int type)
{
  cout << "\nWhere would you like to place this ant? (1 for far left, 10 for far right): ";
  string input;
  getline(cin, input);
  while(!valid_input(input, 10) || !valid_position(input, type))
  {
    cout << "invalid input. give valid input: ";
    getline(cin, input);
  }
  return get_int(input) - 1;
}

/******************************************************************************
** Function: Add Ant
** Description: adds chosen ant to board.
** Parameters: int type: the type of ant.
**  int position: where to place the ant on the board.
** Pre-Conditions: None
** Post-Conditions: correct ant added to board, food deducted.
******************************************************************************/
void Game::add_ant(int type, int position)
{
  if(type == 0) {food_bank -= 2; board[position].ant = new Harvester();}
  if(type == 1) {food_bank -= 4; board[position].ant = new Thrower();}
  if(type == 2) {food_bank -= 4; board[position].ant = new Fire();}
  if(type == 3) {food_bank -= 3; board[position].ant = new Long_Thrower();}
  if(type == 4) {food_bank -= 3; board[position].ant = new Short_Thrower();}
  if(type == 5) {food_bank -= 4; board[position].ant = new Wall();}
  if(type == 6) {food_bank -= 6; board[position].ant = new Ninja();}
  if(type == 7) {food_bank -= 4; board[position].bodyguard = new Bodyguard();}
}

/******************************************************************************
** Function: Add Ant
** Description: adds chosen ant to board.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: correct ant added to board, food deducted.
******************************************************************************/
void Game::add_ant()
{
  bool flag = false;
  for(int i = 0; i < 10; i++)
  {
    if((board[i].ant == NULL && food_bank >= 2) || (board[i].bodyguard == NULL && food_bank >= 4))
      flag = true;
  }
  if(flag)
  {
    cout << "\nWould you like to add an ant to the board? (y for yes, n for no): ";
    string input;
    getline(cin, input);
    while(input != "y" && input != "n")
    {
      cout << "invalid input. give valid input: ";
      getline(cin, input);
    }
    if(input == "y")
    {
      int type = get_type_ant();
      int position = get_position(type);
      add_ant(type, position);
    }
  }
}

/******************************************************************************
** Function: Attack Bees
** Description: has every ant attack bees.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: all ants attacked for turn.
******************************************************************************/
void Game::attack_bees()
{
  Bee** bee_board = new Bee*[10];
  int** num_bees_board = new int*[10];
  for(int i = 0; i < 10; i++)
  {
    bee_board[i] = board[i].bees;
    num_bees_board[i] = &(board[i].num_bees);
  }
  for(int i = 0; i < 10; i++)
  {
    if(board[i].ant != NULL)
      board[i].ant->attack(bee_board, num_bees_board, i);
  }
  delete [] bee_board;
  delete [] num_bees_board;
}

/******************************************************************************
** Function: Remove Bees
** Description: all dead bees for the turn are removed.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: all appropriate bees removed.
******************************************************************************/
void Game::remove_bees()
{
  for(int i = 0; i < 10; i++)
  {
    while(board[i].bees != NULL && board[i].bees[0].get_armor() <= 0)
    {
      if(board[i].num_bees == 1)
      {
        board[i].num_bees = 0;
        delete [] board[i].bees;
        board[i].bees = NULL;
        continue;
      }
      Bee* temp = new Bee[board[i].num_bees-1];
      for(int j = 0; j < board[i].num_bees - 1; j++)
      {
        temp[j] = board[i].bees[j+1];
      }
      delete [] board[i].bees;
      board[i].bees = temp;
      board[i].num_bees--;
    }
  }
}

/******************************************************************************
** Function: Remove Ants
** Description: all dead ants for the turn are removed.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: all appropriate ants removed.
******************************************************************************/
void Game::remove_ants()
{
  for(int i = 0; i < 10; i++)
  {
    if(board[i].ant != NULL && board[i].ant->get_armor() <= 0 && board[i].ant->get_name() == "FIR")
    {
      delete [] board[i].bees;
      board[i].bees = NULL;
      board[i].num_bees = 0;
    }
    if(board[i].ant != NULL && board[i].ant->get_armor() <= 0)
    {
      delete board[i].ant;
      board[i].ant = NULL;
    }
    if(board[i].bodyguard != NULL && board[i].bodyguard->get_armor() <= 0)
    {
      delete board[i].bodyguard;
      board[i].bodyguard = NULL;
    }
  }
}

/******************************************************************************
** Function: Attack Ants
** Description: bees attack ant on specific square.
** Parameters: int index: the current square.
** Pre-Conditions: None
** Post-Conditions: ant attacked by all bees.
******************************************************************************/
void Game::attack_ants(int index)
{
  int num = board[index].num_bees, i = 0;
  while(i < num && (board[index].ant != NULL && board[index].ant->get_armor() > 0 ||
                    board[index].bodyguard != NULL && board[index].bodyguard->get_armor() > 0))
  {
    if(board[index].bodyguard != NULL )
    {
      if(board[index].bodyguard->get_armor() > 0)
        board[index].bodyguard->set_armor(board[index].bodyguard->get_armor()-1);
    }
    else
    {
      if(board[index].ant->get_armor() > 0)
        board[index].ant->set_armor(board[index].ant->get_armor()-1);
    }
    i++;
  }
  if(i < num && (board[index].ant == NULL || board[index].ant->get_name() != "FIR"))
  {
    move_bees(index, i);
  }
}

/******************************************************************************
** Function: Move Bees
** Description: moves all bees on square to square before.
** Parameters: int index: the current square.
**  int index2: the current bee index.
** Pre-Conditions: None
** Post-Conditions: all bees on current square moved.
******************************************************************************/
void Game::move_bees(int index, int index2)
{
  if(index != 0 && board[index].bees != NULL)
  {
    Bee* temp = new Bee[board[index].num_bees + board[index-1].num_bees-index2];
    for(int i = 0; i < board[index-1].num_bees; i++)
    {
      temp[i] = board[index-1].bees[i];
    }
    for(int i = 0; i < board[index].num_bees - index2; i++)
    {
      temp[i+board[index-1].num_bees] = board[index].bees[i+index2];
    }
    if(board[index-1].bees != NULL)
      delete [] board[index-1].bees;
    board[index-1].bees = temp;
    board[index-1].num_bees += board[index].num_bees - index2;
    temp = new Bee[board[index].num_bees - (board[index].num_bees - index2)];
    for(int i = 0; i < board[index].num_bees - (board[index].num_bees - index2); i++)
    {
      temp[i] = board[index].bees[i];
    }
    if(board[index].bees != NULL)
    {
      delete [] board[index].bees;
      board[index].bees = NULL;
    }
    board[index].bees = temp;
    board[index].num_bees = board[index].num_bees - (board[index].num_bees - index2);
  }
}

/******************************************************************************
** Function: Move Bees
** Description: moves all bees on square to square before.
** Parameters: int index: the current square.
** Pre-Conditions: None
** Post-Conditions: all bees on current square moved.
******************************************************************************/
void Game::move_bees(int index)
{
  if(index != 0 && board[index].bees != NULL)
  {
    Bee* temp = new Bee[board[index].num_bees + board[index-1].num_bees];
    for(int i = 0; i < board[index-1].num_bees; i++)
    {
      temp[i] = board[index-1].bees[i];
    }
    for(int i = 0; i < board[index].num_bees; i++)
    {
      temp[i+board[index-1].num_bees] = board[index].bees[i];
    }
    if(board[index].bees != NULL)
    {
      delete [] board[index].bees;
      board[index].bees = NULL;
    }
    if(board[index-1].bees != NULL)
      delete [] board[index-1].bees;
    board[index-1].bees = temp;
    board[index-1].num_bees += board[index].num_bees;
    board[index].num_bees = 0;
  }
}

/******************************************************************************
** Function: Attack ants move bees
** Description: either attacks the ant on the square or moves the bees for
**  every square on board.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: all bees went through move for turn.
******************************************************************************/
void Game::attack_ant_move_bees()
{
  for(int i = 0; i < 10; i++)
  {
    if((board[i].ant == NULL || board[i].ant->get_name() == "NIN") && board[i].bodyguard == NULL)
      move_bees(i);
    else
      attack_ants(i);
    remove_ants();
  }
}

/******************************************************************************
** Function: Add Food
** Description: adds one food for every harvester on board.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: correct food added to food bank.
******************************************************************************/
void Game::add_food()
{
  for(int i = 0; i < 10; i++)
  {
    if(board[i].ant != NULL && board[i].ant->get_name() == "HRV")
      food_bank++;
  }
}

/******************************************************************************
** Function: Print Board
** Description: prints the board to the terminal.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: board printed.
******************************************************************************/
void Game::print_board()
{
  cout << "\nQueen Ant                            ";
  cout << "Food: " << food_bank << " ";
  cout << "                               Hive" << endl;
  cout<<"=================================================================================\n";
  for(int i = 0; i < 10; i++)
  {
    if(board[i].ant == NULL) cout << "|       ";
    else cout << "|" << board[i].ant->get_name() << "    ";
  }
  cout << "|" << endl;
  for(int i = 0; i < 10; i++)
  {
    if(board[i].bodyguard == NULL)  cout << "|       ";
    else  cout << "|BDG    ";
  }
  cout << "|" << endl;
  for(int i = 0; i < 10; i++)
  {
    if(board[i].bees == NULL)  cout << "|       ";
    else  cout << "|BEE x " << board[i].num_bees;
  }
  cout << "|" << endl;
  cout<<"=================================================================================\n";
}

/******************************************************************************
** Function: Start Game
** Description: initializes game
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: game started.
******************************************************************************/
void Game::start_game()
{
  cout<<"\n=================================================================================";
  cout<<"\n                       Welcome to Ants vs. Some Bees!" << endl;
  cout<<"                                By Ben Johnson" << endl;
  cout<<"=================================================================================\n";
  play_game();
}

/******************************************************************************
** Function: Start Game
** Description: runs main game loop.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: game ended.
******************************************************************************/
void Game::play_game()
{
  do{
    add_bee();
    add_food();
    print_board();
    add_ant();
    attack_bees();
    remove_bees();
    attack_ant_move_bees();
    //remove_ants();
  } while(!game_over());

  end_game();
}

/******************************************************************************
** Function: End Game
** Description: prints winner to terminal.
** Parameters: None.
** Pre-Conditions: None
** Post-Conditions: game over.
******************************************************************************/
void Game::end_game()
{
  if(board[0].bees != NULL)
  {
  cout<<"\n=================================================================================";
  cout<<"\n                                 Bees Win!" << endl;
  cout<<"=================================================================================\n";
  cout << endl;
  }
  else
  {
  cout<<"\n=================================================================================";
  cout<<"\n                                 Ants Win!" << endl;
  cout<<"=================================================================================\n";
  cout << endl;
  }
}
