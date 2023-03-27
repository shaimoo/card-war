#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
 using namespace ariel;
        


        Game::Game(Player p1, Player p2){
            player1= new Player(p1.getName());
            player2= new Player(p2.getName());
        }
        
void Game::printLastTurn(){}
void Game::playAll(){}
void Game::printLog(){}
void Game::printWiner(){}
void Game::printStats(){}
void Game::playTurn(){}
