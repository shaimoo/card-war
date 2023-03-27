#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include <string>
using namespace std;
namespace ariel{

        Player:: Player(string n){
          name = n;
        }

        string Player::getName(){
            return name;
        }

        void Player::setName(string n){
            name = n;
        }



        int Player::stacksize(){
           return 0;
        }

        int Player::cardesTaken(){
           return 0;
        }
         void Player::add_card(int num, string sign){
         Card c1(num,sign);
           my_cards.push_back(c1);
        }





}


