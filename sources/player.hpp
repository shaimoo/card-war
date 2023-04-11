#ifndef PLAYER
#define PLAYER
#include <vector>
#include <string>
#include "card.hpp"
using namespace std;
namespace ariel
{
    class Player
    {
    	vector<Card> my_cards;
        string name;
        int numbers_win;
        int numbers_round;
        int cardes_Taken;

        public:
                Player(string n);
                string getName();
                void setName(string n);
                int stacksize();
                int cardesTaken();
                void add_card(Card card1);
                Card pull_card();
                void play_round(int numbers_wins);
                void set_numbers_win(int wins);
                int get_numbers_rounds();
                string  to_string();

   
    };

};
#endif
