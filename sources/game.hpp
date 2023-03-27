#ifndef GAME
#define GAME
#include "player.hpp"

namespace ariel{
class Game
{
   private: Player* player1;
   private: Player* player2;
 public: Game(Player p1, Player p2);
   void playTurn();
   void printLastTurn();
   void playAll(); 
   void printWiner(); 
   void printLog(); 
   void printStats();
};
}

#endif
