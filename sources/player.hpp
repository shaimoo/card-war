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
        public: Player(string n);
        public: string getName();
        public: void setName(string n);
        int stacksize();
        int cardesTaken();
        void add_card(int num,string sign);
   
    };
    
    

    
} // namespace ariel

#endif
