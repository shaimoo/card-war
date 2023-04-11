#ifndef GAME
#define GAME
#include "player.hpp"
#include <vector>

namespace ariel{
class Game
{
    Player& player1;
    Player& player2;
    vector<string> logs;
    int draws;
 public:
    Game(Player& player1, Player& player2);
   void playTurn();
   void printLastTurn();
   void playAll(); 
   void printWiner(); 
   void printLog(); 
   void printStats();
};
}

#endif
