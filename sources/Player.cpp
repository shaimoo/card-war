#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
#include <string>
using namespace std;
namespace ariel
{
        /// constructor for player.
        Player:: Player(string n)
        {
          name = n;
          numbers_round = 0;
          numbers_win = 0;
          cardes_Taken = 0;
          my_cards.clear();
        }
        /// get player name.
        string Player::getName()
        {
            return name;
        }
        /// set player name.
        void Player::setName(string n)
        {
            name = n;
        }
        /// return the size of the stack.
        int Player::stacksize()
        {
           return my_cards.size();
        }
        /// return the size of the cards player wins.
        int Player::cardesTaken()
        {
           return cardes_Taken;
        }
        /// add card to the stack.
        void Player::add_card(Card card1)
         {
           my_cards.push_back(card1);
        }
        /// add the wins of cards to the player.
        void Player::set_numbers_win(int wins)
        {
            numbers_win = wins;
        }
        /// return the numbers rounds.
        int Player::get_numbers_rounds()
        {
            return numbers_round;
        }
        ///

        string Player::to_string()
        {
            string ans = "name player: " + name + "\n";
            ans += "numbers of wins: " + ::to_string(numbers_win) + "\n";
            ans += "numbers of round: " + ::to_string(numbers_round) + "\n";
            ans += "cards taken: " + ::to_string(cardes_Taken) + "\n";
            return ans;
        }

        Card Player::pull_card()
        {
            Card first_card = my_cards.back();
            my_cards.pop_back();
            return  first_card;
        }

        void Player::play_round(int numbers_wins)
        {
            numbers_round +=1;
            if(numbers_wins){
                numbers_win+=1;
                cardes_Taken+=numbers_wins;
            }
        }

}


