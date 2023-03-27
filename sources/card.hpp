#ifndef CARD
#define CARD
#include <iostream>
#include <string>

using namespace std;
namespace ariel{
class Card
{
    string sign;
    int number;
    public:
	Card (int num,string sign_);
	string get_sign();
	int get_number();	  
};
}

#endif

